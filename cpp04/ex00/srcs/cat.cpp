/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:51:44 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 13:51:44 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.hpp"

Cat::Cat()
{
	std::cout << "A new Cat has been created" << std::endl;
	this->type = "Cat";
	return;
}

Cat::Cat(const Cat &Cat) : Animal(Cat)
{
	std::cout << "A new Cat copy has been created" << std::endl;
	this->type = Cat.type;
	return;
}

Cat::~Cat()
{
	std::cout << "A Cat has been destroyed" << std::endl;
	return;
}

Cat &Cat::operator=(const Cat &rhs)
{
	this->type = rhs.type;
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meow !" << std::endl;
	return;
}