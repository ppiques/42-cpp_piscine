/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:39:12 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 13:39:12 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

Animal::Animal()
{
	std::cout << "A new animal has been created" << std::endl;
	this->type = "Undefined";
	return;
}

Animal::Animal(const Animal &Animal)
{
	std::cout << "A new animal copy has been created" << std::endl;
	this->type = Animal.type;
	return;
}

Animal::~Animal()
{
	std::cout << "An animal has been destroyed" << std::endl;
	return;
}

Animal &Animal::operator=(const Animal &rhs)
{
	this->type = rhs.type;
	return (*this);
}

const	std::string &Animal::getType(void) const
{
	return (this->type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Error : Animal has no defined type." << std::endl;
	return;
}