/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:37:25 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/22 13:37:25 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar.hpp"

// We make use of static casts here because we already know what type we are casting from and to

Scalar::Scalar()
{
	this->_dot = false;
	this->_notOnlyZero = false;
	this->_dotFirst = false;
	this->_error = false;
	this->_valueLen = 0;
	this->_floatEdgeCases = "None";
	this->_doubleEdgeCases = "None";
	this->_errorValueInt = false;
	this->_errorValueChar = false;
	this->_valueInt = 0;
	this->_valueChar = 0;
	this->_valueFloat = 0.0f;
	this->_valueDouble = 0.0f;
	return;
}

Scalar::Scalar(char const *value) : _srcValue(value)
{
	this->_dot = false;
	this->_notOnlyZero = false;
	this->_dotFirst = false;
	this->_error = false;
	this->_valueLen = 0;
	this->_floatEdgeCases = "None";
	this->_doubleEdgeCases = "None";
	this->_errorValueInt = false;
	this->_errorValueChar = false;
	if (setEdgeCases(value) == false)
	{
		errorHandler(value);
		findDot();
	}
	setInt(value);
	setChar(value);
	setFloat(value);
	setDouble(value);
	return;
}

Scalar::Scalar(const Scalar &cpy)
{
	(*this) = cpy;
	return;
}

Scalar::~Scalar()
{
	return;
}

Scalar &Scalar::operator=(const Scalar &rhs)
{
	this->_dot = rhs._dot;
	this->_notOnlyZero = rhs._notOnlyZero;
	this->_dotFirst = rhs._dotFirst;
	this->_error = rhs._error;
	this->_valueLen = rhs._valueLen;
	this->_floatEdgeCases = rhs._floatEdgeCases;
	this->_doubleEdgeCases = rhs._doubleEdgeCases;
	this->_errorValueInt = rhs._errorValueInt;
	this->_errorValueChar = rhs._errorValueChar;
	this->_valueInt = rhs._valueInt;
	this->_valueChar = rhs._valueChar;
	this->_valueFloat = rhs._valueFloat;
	this->_valueDouble = rhs._valueDouble;
	this->_srcValue = rhs._srcValue;
	return (*this);
}

void	Scalar::setInt(char const *value)
{
	bool	Digit = false;
	long	tester;

	for (int i = 0; value[i] != 0; i++)
	{
		if (isDigit(value[i]) == true || value[i] == '-')
			Digit = true;
	}
	if (Digit == true)
	{
		tester = static_cast<long>(atol(value));
		if (tester > 2147483647 || tester < -2147483648)
			this->_errorValueInt = true;
		else
			this->_valueInt = static_cast<int>(atoi(value));
	}
	else
		this->_valueInt = static_cast<int>(*value);
}


void	Scalar::setChar(char const *value)
{
	bool	Digit = false;
	long	tester;

	for (int i = 0; value[i] != 0; i++)
	{
		if (isDigit(value[i]) == true || value[i] == '-')
			Digit = true;
	}
	if (Digit == true)
	{
		tester = static_cast<long>(atol(value));
		if (tester > 127 || tester < -128)
			this->_errorValueChar = true;
		else
			this->_valueChar = static_cast<char>(atoi(value));
	}
	else
		this->_valueChar = static_cast<char>(*value);
}

void	Scalar::setFloat(char const *value)
{
	bool	Digit = false;

	if (this->_valueLen > 1 && value[0] == '.')
	{
		this->_dotFirst = true;
		value++;
	}
	for (int i = 0; value[i] != 0; i++)
	{
		if (isDigit(value[i]) == true || value[i] == '-')
			Digit = true;
	}
	if (Digit == true)
		this->_valueFloat = static_cast<float>(atof(value));
	else
		this->_valueFloat = static_cast<float>(*value);
}

void	Scalar::setDouble(char const *value)
{
	bool	Digit = false;

	if (this->_valueLen > 1 && value[0] == '.')
	{
		this->_dotFirst = true;
		value++;
	}
	for (int i = 0; value[i] != 0; i++)
	{
		if (isDigit(value[i]) == true || value[i] == '-')
			Digit = true;
	}
	if (Digit == true)
		this->_valueDouble = static_cast<double>(atof(value));
	else
		this->_valueDouble = static_cast<double>(*value);
}

void	Scalar::printInt(void) const
{
	std::cout << "int : ";
	if (this->_floatEdgeCases != "None" || this->_errorValueInt == true)
		std::cout << "impossible" << std::endl;
	else if (this->_dotFirst == true)
		std::cout << "0" << std::endl;
	else
		std::cout << this->_valueInt << std::endl;
	return;
}

void	Scalar::printChar(void) const
{
	std::cout << "char : ";
	if (this->_floatEdgeCases != "None" || this->_errorValueChar == true)
		std::cout << "impossible" << std::endl;
	else if (this->_valueChar < 32 || this->_valueChar > 126)
		std::cout << "Non displayable" << std::endl;
	else
		std::cout << "'" << this->_valueChar << "'" << std::endl;
	return;
}

void	Scalar::printFloat(void) const
{
	std::cout << "float : ";
	if (this->_floatEdgeCases != "None")
		std::cout << this->_floatEdgeCases << std::endl;
	else if (this->_dotFirst == true)
		std::cout << "0." << this->_valueDouble << "f" << std::endl;
	else if (this->_dot == true && this->_notOnlyZero == true)
		std::cout << this->_valueFloat << "f" << std::endl;
	else if (this->_valueLen > 6 && this->_dot == false)
		std::cout << this->_valueFloat << "f" << std::endl;
	else
		std::cout << this->_valueFloat << ".0f" << std::endl;
	return;
}

void	Scalar::printDouble(void) const
{
	std::cout << "double : ";
	if (this->_doubleEdgeCases != "None")
		std::cout << this->_doubleEdgeCases << std::endl;
	else if (this->_dotFirst == true)
		std::cout << "0." << this->_valueDouble << std::endl;
	else if (this->_dot == true && this->_notOnlyZero == true)
		std::cout << this->_valueDouble << std::endl;
	else if (this->_valueLen > 6 && this->_dot == false)
		std::cout << this->_valueFloat << std::endl;
	else
		std::cout << this->_valueDouble << ".0" << std::endl;
	return;
}