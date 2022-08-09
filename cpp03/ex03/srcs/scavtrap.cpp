/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:29:25 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/09 14:29:25 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scavtrap.hpp"

ScavTrap::ScavTrap()
{
	this->_name = "Undefined";
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	this->_scav_ep = 50;
	std::cout << "The ScavTrap unit " << this->_name << " joined the battlefield !" << std::endl;
	return ;
}

ScavTrap::ScavTrap(std::string const &name)
{
	this->_name = name;
	this->_hp = 100;
	this->_ep = 50;
	this->_ad = 20;
	this->_scav_ep = 50;
	std::cout << "The ScavTrap unit " << this->_name << " joined the battlefield !" << std::endl;
	return ;
}

ScavTrap::ScavTrap(ScavTrap const &ScavTrap) : ClapTrap(ScavTrap)
{
	this->_name = ScavTrap._name;
	this->_hp = ScavTrap._hp;
	this->_ep = ScavTrap._ep;
	this->_ad = ScavTrap._ad;
	return ;
}

ScavTrap::~ScavTrap()
{
	std::cout << "The ScavTrap unit " << this->_name << " has been destroyed !" << std::endl;
	return ;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &rhs)
{
	if (this != &rhs)
	{
		this->_name = rhs._name;
		this->_hp = rhs._hp;
		this->_ep = rhs._ep;
		this->_ad = rhs._ad;
	}
	return *this;
}

void	ScavTrap::guardGate()
{
	std::cout << "The ScavTrap unit " << this->_name << " is now in Gate Keeper mode !" << std::endl;
	return ;
}