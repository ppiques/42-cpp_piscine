/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   humanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:20:16 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/26 09:20:16 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
# define HUMANB_HPP

#include "weapon.hpp"

// We use a pointer for the weapon type, so we can change it by making it point to something else 
// if this human is not supposed to be armed at a particular moment.
class humanB
{
	public :

	humanB(std::string name);
	~humanB();

	std::string		getName() const;
	void			attack();
	void			setWeapon(Weapon &type);

	private :

	std::string	_name;
	Weapon		*_type;
};

#endif