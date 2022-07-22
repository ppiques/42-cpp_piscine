/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:19:13 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/22 15:19:13 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


// Titouan dies as soon as he's called because the function calls it's constructor, and then it's destructor when it's done.
// Philibert is created with a new, so he dies when a delete is called.
// Alfredo is created in this function, so when this function is over, he dies.
int	main()
{
	Zombie	zombie_1("Alfredo");
	Zombie	*zombie_2 = newZombie("Philibert");

	randomChump("Titouan");
	zombie_1.announce();
	zombie_2->announce();
	delete zombie_2;
	zombie_1.announce();
	
	return (0);
}