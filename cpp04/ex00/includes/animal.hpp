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

class Animal
{
	public :

	Animal();
	Animal(const Animal &cpy);
	virtual ~Animal();

	Animal	&operator=(const Animal &rhs);

	const std::string	&getType(void) const;

	virtual void makeSound() const;

	protected :

	std::string type;
};

#endif