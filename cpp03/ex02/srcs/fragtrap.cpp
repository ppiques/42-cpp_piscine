/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragtrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:00:57 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/09 15:00:57 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fragtrap.hpp"

FragTrap::FragTrap()
{
	this->_name = "Undefined";
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "The FragTrap unit " << this->_name << " joined the battlefield !" << std::endl;
	return ;
}

FragTrap::FragTrap(std::string const &name)
{
	this->_name = name;
	this->_hp = 100;
	this->_ep = 100;
	this->_ad = 30;
	std::cout << "The FragTrap unit " << this->_name << " joined the battlefield !" << std::endl;
	return ;
}

FragTrap::FragTrap(FragTrap const &FragTrap) : ClapTrap(FragTrap)
{
	this->_name = FragTrap._name;
	this->_hp = FragTrap._hp;
	this->_ep = FragTrap._ep;
	this->_ad = FragTrap._ad;
	return ;
}

FragTrap::~FragTrap()
{
	std::cout << "The FragTrap unit " << this->_name << " has been destroyed !" << std::endl;
	return ;
}

FragTrap	&FragTrap::operator=(FragTrap const &rhs)
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

void	FragTrap::highFivesGuys(void)
{
	std::cout << "The FragTrap unit " << this->_name << " is up for a high five !" << std::endl;
	return ;
}