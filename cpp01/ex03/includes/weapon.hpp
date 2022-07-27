/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:20:18 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/26 09:20:18 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	WEAPON_HPP
# define WEAPON_HPP

#include <iostream>

class Weapon
{
	public :

	Weapon(std::string type);
	~Weapon();

	std::string	const	&getType() const;
	void				setType(std::string const &type);

	private :

	std::string _type;
};

#endif