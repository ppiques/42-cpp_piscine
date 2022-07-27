/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:19:43 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/26 09:19:43 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.hpp"

Weapon::Weapon(std::string type) : _type(type)
{
	return;
}

Weapon::~Weapon()
{
	return;
}

const	std::string &Weapon::getType() const
{
	return (this->_type);
}

void	Weapon::setType(std::string const &type)
{
	if (type.empty())
	{
		this->_type = "typeless weapon";
		return;
	}
	this->_type = type;
}