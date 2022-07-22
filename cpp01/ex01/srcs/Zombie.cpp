/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:18:05 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/22 18:18:05 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie()
{
	return;
}

Zombie::~Zombie()
{
	std::cout << this->_name + " died." << std::endl;
	return ;
}

void	Zombie::announce(void)
{
	std::cout << this->_name + ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::string Zombie::get_name(void) const
{
	return (this->_name);
}

void	Zombie::set_name(std::string name)
{
	this->_name = name;
}