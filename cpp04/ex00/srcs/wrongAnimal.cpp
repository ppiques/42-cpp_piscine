/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:55:27 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 13:55:27 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wrongAnimal.hpp"

WrongAnimal::WrongAnimal()
{
	std::cout << "A new WrongAnimal has been created" << std::endl;
	this->type = "Undefined";
	return;
}

WrongAnimal::WrongAnimal(const WrongAnimal &WrongAnimal)
{
	std::cout << "A new WrongAnimal copy has been created" << std::endl;
	this->type = WrongAnimal.type;
	return;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "A WrongAnimal has been destroyed" << std::endl;
	return;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &rhs)
{
	this->type = rhs.type;
	return (*this);
}

const	std::string &WrongAnimal::getType(void) const
{
	return (this->type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Definitely not an animal sound." << std::endl;
	return;
}