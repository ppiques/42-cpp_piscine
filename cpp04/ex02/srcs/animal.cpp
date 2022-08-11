/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:39:12 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 13:39:12 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animal.hpp"

AAnimal::~AAnimal()
{
	std::cout << "An abstract animal has been destroyed" << std::endl;
	return;
}

const	std::string &AAnimal::getType(void) const
{
	return (this->type);
}
