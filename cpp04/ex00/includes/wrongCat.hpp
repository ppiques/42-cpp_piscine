/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:57:41 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 13:57:41 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP
# include "wrongAnimal.hpp"

class WrongCat : virtual public WrongAnimal
{
	public :

	WrongCat();
	WrongCat(const WrongCat &cpy);
	virtual ~WrongCat();

	WrongCat &operator=(const WrongCat &rhs);

	void makeSound() const;
};

#endif