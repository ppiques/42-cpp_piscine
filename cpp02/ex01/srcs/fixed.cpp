/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:36:54 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/07 15:36:54 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int	Fixed::_nb_fractional_bits = 8;

Fixed::Fixed(void)
{
	std::cout << "Default constructor called" << std::endl;
	this->_fixed_point = 0;
	return ;
}

Fixed::Fixed(const int int_value)
{
	std::cout << "Int constructor called" << std::endl;
	this->_fixed_point = int_value << this->_nb_fractional_bits; // bitshift to the left https://docs.microsoft.com/fr-fr/cpp/cpp/left-shift-and-right-shift-operators-input-and-output?view=msvc-170
	return;
}

Fixed::Fixed(const float float_value)
{
	std::cout << "Float constructor called" << std::endl;
	this->_fixed_point = roundf(float_value * 256); // pow(2, this->_fixed_point) = <binary>100000000 = 256
	return;
}

Fixed::Fixed(Fixed const &cpy)
{
	std::cout << "Copy constructor called" << std::endl;
	*this = cpy; // dereference to get the actual value and not the memory address
	return ;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
	return ;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &rhs)
	{
		if (getRawBits() != rhs._fixed_point)
			this->_fixed_point = rhs._fixed_point;
	}
	return *this;
}

std::ostream	&operator<<(std::ostream & outstr, Fixed const & instance)
{
	outstr << instance.toFloat();
	return (outstr);
}

int	Fixed::getRawBits(void) const // removed std::cout for ex01
{
	return (this->_fixed_point);
}

void	Fixed::setRawBits(int const raw)
{
	this->_fixed_point = raw;
}

float	Fixed::toFloat(void) const
{
	float result;

	result = (float)this->_fixed_point / 256;

	return (result);
}

int 	Fixed::toInt(void) const
{
	return (this->_fixed_point >> this->_nb_fractional_bits); // bitshift to the right : https://docs.microsoft.com/fr-fr/cpp/cpp/left-shift-and-right-shift-operators-input-and-output?view=msvc-170
}