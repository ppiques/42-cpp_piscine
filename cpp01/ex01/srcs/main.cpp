/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 18:18:59 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/22 18:18:59 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main()
{
	int	i = 0;
	Zombie	*zombie_horde1 = zombieHorde(42, "Titouan");

	while (i < 42)
	{
		zombie_horde1[i].announce();
		i++;
	}
	delete [] zombie_horde1;
	
	Zombie	*zombie_horde2 = zombieHorde(10, "Romero");
	i = 0;

	while (i < 10)
	{
		zombie_horde2[i].announce();
		i++;
	}
	delete [] zombie_horde2;

	return (0);
}