/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:47:20 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 13:47:20 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "dog.hpp"

Dog::Dog()
{
	std::cout << "A new dog has been created" << std::endl;
	this->type = "Dog";
	return;
}

Dog::Dog(const Dog &Dog) : Animal(Dog)
{
	std::cout << "A new dog copy has been created" << std::endl;
	this->type = Dog.type;
	return;
}

Dog::~Dog()
{
	std::cout << "A dog has been destroyed" << std::endl;
	return;
}

Dog &Dog::operator=(const Dog &rhs)
{
	this->type = rhs.type;
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Bark Bark !" << std::endl;
	return;
}