/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:19:39 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/26 09:19:39 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanB.hpp"

humanB::humanB(std::string name) : _name(name), _type(NULL)
{
	return;
}

humanB::~humanB()
{
	return;
}

std::string	humanB::getName() const
{
	return (this->_name);
}

void	humanB::setWeapon(Weapon &type)
{
	this->_type = &type;
}

void	humanB::attack()
{
	std::cout << this->_name << " attacks with his ";
	if (this->_type == NULL)
		std::cout << "bare hands !" << std::endl;
	else
		std::cout << this->_type->getType() << " !" << std::endl;
}