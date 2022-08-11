/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:33:29 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 13:33:29 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP
# include <iostream>
# include "brain.hpp"

class AAnimal
{
	public :

	virtual ~AAnimal();

	const std::string	&getType() const;

	virtual Brain *getBrain() const = 0;

	virtual void makeSound() const = 0;

	protected :

	std::string type;
};

#endif