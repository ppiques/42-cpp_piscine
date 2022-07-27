/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:20:14 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/26 09:20:14 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_HPP
# define HUMANA_HPP

#include "weapon.hpp"

// As HumanA must always be armed, we use a reference for the Weapon type.
// It allows us to make sure the type cannot be changed. 
class humanA
{
	public :

	humanA(std::string name, Weapon &type);
	~humanA();

	std::string		getName() const;
	Weapon const	&getType() const;
	void			attack();

	private :

	std::string	_name;
	Weapon		&_type;
};

#endif