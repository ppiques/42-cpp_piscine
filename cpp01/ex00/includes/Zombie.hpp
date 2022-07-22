/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:18:55 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/22 15:18:55 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

#include <iostream>

class Zombie
{
	public :

	Zombie(std::string name);
	~Zombie();

	void	announce(void);

	private:

	std::string _name;
};

Zombie*	newZombie( std::string name);
void	randomChump(std::string name);

#endif