/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:51:46 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 13:51:46 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP
# include "animal.hpp"
# include "brain.hpp"

class Cat : virtual public AAnimal
{
	public :

	Cat();
	Cat(const Cat &cpy);
	virtual ~Cat();

	Cat &operator=(const Cat &rhs);

	virtual Brain *getBrain(void) const;

	virtual void makeSound() const;

	private :

	Brain *_brain;
};

#endif