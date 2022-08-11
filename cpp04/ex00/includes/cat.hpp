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

class Cat : virtual public Animal
{
	public :

	Cat();
	Cat(const Cat &cpy);
	virtual ~Cat();

	Cat &operator=(const Cat &rhs);

	virtual void makeSound() const;
};

#endif