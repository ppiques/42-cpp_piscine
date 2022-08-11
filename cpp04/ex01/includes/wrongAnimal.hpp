/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:53:56 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 13:53:56 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP
# include <iostream>

class WrongAnimal
{
	public :

	WrongAnimal();
	WrongAnimal(const WrongAnimal &cpy);
	virtual ~WrongAnimal();

	WrongAnimal	&operator=(const WrongAnimal &rhs);

	const std::string	&getType(void) const;

	void makeSound() const;

	protected :

	std::string type;
};

#endif