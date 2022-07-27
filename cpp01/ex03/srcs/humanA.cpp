/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:19:41 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/26 09:19:41 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "humanA.hpp"

humanA::humanA(std::string name, Weapon &type) : _name(name), _type(type)
{
	return;
}

humanA::~humanA()
{
	return;
}

std::string	humanA::getName() const
{
	return (this->_name);
}

Weapon const &humanA::getType() const
{
	return (this->_type);
}

void	humanA::attack()
{
	std::cout << this->_name << " attacks with his " << this->_type.getType() << " !" << std::endl;
}