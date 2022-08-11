/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:57:39 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 13:57:39 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongCat.hpp"

WrongCat::WrongCat()
{
	std::cout << "A new WrongCat has been created" << std::endl;
	this->type = "WrongCat";
	return;
}

WrongCat::WrongCat(const WrongCat &WrongCat) : WrongAnimal(WrongCat)
{
	std::cout << "A new WrongCat copy has been created" << std::endl;
	this->type = WrongCat.type;
	return;
}

WrongCat::~WrongCat()
{
	std::cout << "A WrongCat has been destroyed" << std::endl;
	return;
}

WrongCat &WrongCat::operator=(const WrongCat &rhs)
{
	this->type = rhs.type;
	return (*this);
}

void	WrongCat::makeSound() const
{
	std::cout << "Bark Bark ?" << std::endl; // should not be called
	return;
}