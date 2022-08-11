/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:24:36 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 14:24:36 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brain.hpp"

Brain::Brain()
{
	std::cout << "A brain class has been created" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = "Undefined";
	return;
}

Brain::Brain(const Brain &Brain)
{
	std::cout << "A Brain class copy has been created" << std::endl;
	for (int i = 0; i < 100; i++)
		this->ideas[i] = Brain.ideas[i];
	return;
}

Brain::~Brain()
{
	std::cout << "A brain class has been destroyed" << std::endl;
	return;
}

Brain &Brain::operator=(const Brain &rhs)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}