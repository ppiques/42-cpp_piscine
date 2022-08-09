/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claptrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:18:04 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/09 13:18:04 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "claptrap.hpp"

ClapTrap::ClapTrap()
{
	this->_name = "Undefined";
	this->_hp = 10;
	this->_ep = 10;
	this->_ad = 0;
	std::cout << "The ClapTrap unit " << this->_name << " joined the battlefield !" << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string const &name) : _name(name)
{
	this->_hp = 10;
	this->_ep = 10;
	this->_ad = 0;
	std::cout << "The ClapTrap unit " << this->_name << " joined the battlefield !" << std::endl;
	return ;
}

ClapTrap::ClapTrap(ClapTrap const &ClapTrap)
{
	this->_name = ClapTrap._name;
	this->_hp = ClapTrap._hp;
	this->_ep = ClapTrap._ep;
	this->_ad = ClapTrap._ad;
	return ;
}

ClapTrap::~ClapTrap()
{
	std::cout << "The ClapTrap unit " << this->_name << " has been destroyed !" << std::endl;
	return ;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &rhs)
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

void	ClapTrap::attack(std::string const &target)
{
	if (this->_hp <= 0)
	{
		std::cout << "The ClapTrap unit " << this->_name << " is down and cannot act !" << std::endl;
		return;
	}
	if (this->_ep == 0)
	{
		std::cout << "Error : The ClapTrap unit " << this->_name << " is out of energy !" << std::endl;
		return ;
	}
	if (this->_ad == 1 || this->_ad <= 0 )
		std::cout << "The ClapTrap unit " << this->_name << " inflicts " << this->_ad << " point of damage to " << target << " !" << std::endl;
	else
		std::cout << "The ClapTrap unit " << this->_name << " inflicts " << this->_ad << " points of damage to " << target << " !" << std::endl;
	this->_ep -= -1;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (this->_hp <= 0)
		return;
	if (amount == 1 || amount <= 0)
		std::cout << "The ClapTrap unit " << this->_name << " receives " << amount << " point of damage !" << std::endl;
	else
		std::cout << "The ClapTrap unit " << this->_name << " receives " << amount << " points of damage !" << std::endl;
	this->_hp -= amount;
	std::cout << this->_name << " has " << this->_hp << " hitpoints left." << std::endl;
	if (this->_hp <= 0)
		std::cout << this->_name << " is now a wreck !" << std::endl;
	return ;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (this->_hp <= 0)
	{
		std::cout << "The ClapTrap unit " << this->_name << " is down and cannot act !" << std::endl;
		return;
	}
	if (amount <= 0)
	{
		std::cout << "Error : The ClapTrap unit " << this->_name << " cannot heal for 0 hitpoints." << std::endl;
		return ;
	}
	if (this->_ep <= 0)
	{
		std::cout << "Error : The ClapTrap unit " << this->_name << " is out of energy !" << std::endl;
		return ;
	}
	this->_hp += amount;
	if (amount == 1)
	{
		std::cout << "The ClapTrap unit " << this->_name << " heals for " << amount << " hitpoint !" << std::endl;
		std::cout << this->_name << " has " << this->_hp << " hitpoints left." << std::endl;
		return ;
	}
	else 
		std::cout << "The ClapTrap unit " << this->_name << " heals for " << amount << " hitpoints !" << std::endl;
	std::cout << this->_name << " has " << this->_hp << " hitpoints left." << std::endl;
	return ;
}