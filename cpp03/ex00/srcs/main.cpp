/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:18:06 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/09 13:18:06 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "claptrap.hpp"

int	main()
{
	ClapTrap clapTrap1("Jess");
	ClapTrap clapTrap2("Harl");

	std::cout << std::endl;

	clapTrap1.attack("Harl");
	clapTrap2.takeDamage(0);
	clapTrap2.attack("Jess");
	clapTrap1.takeDamage(0);

	std::cout << std::endl;

	clapTrap1.beRepaired(0);
	clapTrap1.beRepaired(1);
	clapTrap2.beRepaired(2);
	clapTrap2.beRepaired(3);

	std::cout << std::endl;

	clapTrap2.takeDamage(50);
	clapTrap2.attack("Jess");
	clapTrap1.attack("Harl");

	std::cout << std::endl;

	return (0);
}