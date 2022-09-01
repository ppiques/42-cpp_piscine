/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 11:12:44 by ppiques           #+#    #+#             */
/*   Updated: 2022/09/01 11:43:55 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scalar.hpp"

bool	Scalar::isDigit(char c) const
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	Scalar::setEdgeCases(std::string const &value)
{
	std::string	floatEdgeCases[] =
	{
		"+inff",
		"-inff",
		"nanf"
	};
	std::string	doubleEdgeCases[] =
	{
		"+inf",
		"-inf",
		"nan"
	};
	for (int i = 0; i < 3; i++)
	{
		if (floatEdgeCases[i] == value || doubleEdgeCases[i] == value)
		{
			this->_floatEdgeCases = floatEdgeCases[i];
			this->_doubleEdgeCases = doubleEdgeCases[i];
			return (true);
		}
	}
	return (false);
}

void	Scalar::findDot(void)
{
	int	fCount = 0;

	for (int i = 0; this->_srcValue[i] != '\0'; i++)
	{
		if (this->_srcValue[i] == '.')
		{
			this->_dot = true;
			i++;
			while (this->_srcValue[i] != '\0' && (isDigit(this->_srcValue[i]) == true || this->_srcValue[i] == 'f'))
			{
				if (this->_srcValue[i] != '\0' && this->_srcValue[i] != 'f' && this->_srcValue[i] != '0')
					this->_notOnlyZero = true;
				if (this->_srcValue[i] == 'f')
					fCount++;
				i++;
			}
			if (this->_srcValue[i] == '.')
				throw ScalarError();
			if (fCount > 1)
				throw ScalarError();
			return;
		}
	}
}

void	Scalar::errorHandler(char const *value)
{
	bool asciiChar = false;
	int fCount = 0;

	for (int i = 0; value[i] != '\0'; i++)
	{
		if (isDigit(value[i]) == false)
		{
			if (value[i] != '.' && value[i] != 'f' && value[i] != '-' && value[i] != '+' && (value[i] >= 32 && value[i] <= 126))
				asciiChar = true;
			if (value[i] == 'f')
				fCount++;
		}
		if (asciiChar == true && i >= 1)
			throw ScalarError();
		if (fCount > 1)
			throw ScalarError();
		this->_valueLen += 1;
	}
}