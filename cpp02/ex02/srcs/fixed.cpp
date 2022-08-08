/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:09:58 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/07 16:09:58 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int	Fixed::_nb_fractional_bits = 8;

Fixed::Fixed(void)
{
	this->_fixed_point = 0;
	return ;
}

Fixed::Fixed(const int int_value)
{
	this->_fixed_point = int_value << this->_nb_fractional_bits;
	return;
}

Fixed::Fixed(const float float_value)
{
	this->_fixed_point = roundf(float_value * 256);
	return;
}

Fixed::Fixed(Fixed const &src)
{
	*this = src;
	return ;
}

Fixed::~Fixed()
{
	return ;
}

Fixed &Fixed::operator=(Fixed const &rhs)
{
	if (this != &rhs)
	{
		if (getRawBits() != rhs._fixed_point)
			this->_fixed_point = rhs._fixed_point;
	}
	return *this;
}

Fixed Fixed::operator*(Fixed const &rhs) const
{
	Fixed ret;

	ret._fixed_point = roundf((this->toFloat() * rhs.toFloat()) * 256);
	return (ret);
}

Fixed Fixed::operator/(Fixed const &rhs) const
{
	Fixed ret;

	if (rhs.toFloat() == 0)
	{
		std::cout << "Error : cannot divide by 0." << std::endl;
		return (ret); 
	}
	ret._fixed_point = roundf((this->toFloat() * rhs.toFloat()) * 256);
	return (ret);
}

Fixed Fixed::operator+(Fixed const &rhs) const
{
	Fixed ret;

	ret.setRawBits(_fixed_point + rhs._fixed_point);
	return (ret);
}

Fixed Fixed::operator-(Fixed const &rhs) const
{
	Fixed ret;

	ret.setRawBits(_fixed_point - rhs._fixed_point);
	return (ret);
}

Fixed &Fixed::operator++(void)
{
	this->_fixed_point++;
	return (*this);
}

Fixed Fixed::operator++(int)
{
	Fixed ret(*this);

	++(*this);
	return (ret);
}

Fixed &Fixed::operator--(void)
{
	this->_fixed_point--;
	return (*this);
}

Fixed Fixed::operator--(int)
{
	Fixed ret(*this);

	--(*this);
	return (ret);
}

bool	Fixed::operator<(Fixed const &rhs) const
{
	if (this->_fixed_point < rhs._fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator>(Fixed const &rhs) const
{
	if (this->_fixed_point > rhs._fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator<=(Fixed const &rhs) const
{
	if (this->_fixed_point <= rhs._fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator>=(Fixed const &rhs) const
{
	if (this->_fixed_point >= rhs._fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator==(Fixed const &rhs) const
{
	if (this->_fixed_point == rhs._fixed_point)
		return (true);
	return (false);
}

bool	Fixed::operator!=(Fixed const &rhs) const
{
	if (this->_fixed_point != rhs._fixed_point)
		return (true);
	return (false);
}

const Fixed	&Fixed::min(Fixed &lhs, const Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

Fixed	&Fixed::min(Fixed &lhs, Fixed &rhs)
{
	if (lhs < rhs)
		return (lhs);
	return (rhs);
}

const Fixed	&Fixed::max(Fixed &lhs, const Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

Fixed	&Fixed::max(Fixed &lhs, Fixed &rhs)
{
	if (lhs > rhs)
		return (lhs);
	return (rhs);
}

int	Fixed::getRawBits(void) const
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

std::ostream	&operator<<(std::ostream & outstr, Fixed const & instance)
{
	outstr << instance.toFloat();
	return (outstr);
}