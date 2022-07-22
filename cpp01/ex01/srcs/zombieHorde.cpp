/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:17:52 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/22 18:17:52 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie* zombieHorde(int N, std::string name)
{
	int	i;

	i = 0;
	Zombie *zombie_horde = new Zombie[N];

	while (i < N)
	{
		zombie_horde[i].set_name(name);
		i++;
	}
	return (zombie_horde);
}