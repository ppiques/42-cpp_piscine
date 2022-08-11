/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:44:57 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 13:44:57 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP
# include "animal.hpp"
# include "brain.hpp"

class Dog : virtual public Animal
{
	public :

	Dog();
	Dog(const Dog &cpy);
	virtual ~Dog();

	Dog &operator=(const Dog &rhs);

	virtual Brain *getBrain(void) const;

	virtual void makeSound() const;

	private :

	Brain *_brain;
};

#endif