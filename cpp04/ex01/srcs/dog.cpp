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
	std::cout << "A new Dog has been created" << std::endl;
	this->type = "Dog";
	this->_brain = new Brain();
	return;
}

Dog::Dog(const Dog &Dog) : Animal(Dog)
{
	std::cout << "A new Dog copy has been created" << std::endl;
	this->type = Dog.type;
	this->_brain = new Brain(*Dog._brain);
	return;
}

Dog::~Dog()
{
	std::cout << "A Dog has been destroyed" << std::endl;
	return;
}

Dog &Dog::operator=(const Dog &rhs)
{
	this->type = rhs.type;
	delete this->_brain;
	this->_brain = new Brain(*(rhs._brain));
	return (*this);
}

Brain *Dog::getBrain(void) const
{
	return (this->_brain);
}

void	Dog::makeSound() const
{
	std::cout << "Bark Bark !" << std::endl;
	return;
}