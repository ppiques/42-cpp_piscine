/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:17:54 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/22 18:17:54 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public :

	Zombie();
	~Zombie();

	void		announce(void);
	void		set_name(std::string);
	std::string	get_name(void) const;

	private:

	std::string _name;
};

Zombie*	zombieHorde(int N, std::string name);

#endif