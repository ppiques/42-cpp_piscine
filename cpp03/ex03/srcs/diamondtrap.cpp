/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diamondtrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:15:34 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/09 15:15:34 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "diamondtrap.hpp"

DiamondTrap::DiamondTrap()
{
	this->_name = "Undefined";
	this->_hp = FragTrap::_frag_hp;
	this->_ep = ScavTrap::_scav_ep;
	this->_ad = FragTrap::_frag_ad;
	std::cout << "The DiamondTrap unit " << this->_name << " joined the battlefield !" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(std::string const &name)
{
	this->_name = name;
	ClapTrap::_name = name + "_clap_name";
	this->_hp = FragTrap::_frag_hp;
	this->_ep = ScavTrap::_scav_ep;
	this->_ad = FragTrap::_frag_ad;
	std::cout << "The DiamondTrap unit " << this->_name << " joined the battlefield !" << std::endl;
	return ;
}

DiamondTrap::DiamondTrap(DiamondTrap const &DiamondTrap) : ClapTrap(DiamondTrap), FragTrap(DiamondTrap), ScavTrap(DiamondTrap)
{
	this->_name = DiamondTrap._name;
	this->_hp = DiamondTrap._hp;
	this->_ep = DiamondTrap._ep;
	this->_ad = DiamondTrap._ad;
	return ;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "The DiamondTrap unit " << this->_name << " has been destroyed !" << std::endl;
	return ;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &rhs)
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

void	DiamondTrap::whoAmI()
{
	std::cout << this->_name << " : Hello ! My name is : " << this->_name << ". My clap name is : " << ClapTrap::_name << std::endl;
	return ;
}