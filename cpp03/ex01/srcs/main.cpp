/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:29:23 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/09 14:29:23 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "claptrap.hpp"
#include "scavtrap.hpp"

int	main()
{
	ClapTrap clapTrap1("Jess");
	ScavTrap scavTrap2("Harl"); // will first create a Undefined claptrap, then a Harl scavtrap

	clapTrap1.attack("Harl");
	scavTrap2.takeDamage(0);
	clapTrap1.beRepaired(200);
	scavTrap2.attack("Jess");
	clapTrap1.takeDamage(20);

	clapTrap1.beRepaired(0);
	clapTrap1.beRepaired(1);
	scavTrap2.beRepaired(2);
	scavTrap2.beRepaired(3);

	scavTrap2.guardGate();

	scavTrap2.takeDamage(500);
	scavTrap2.attack("Jess");
	clapTrap1.attack("Harl");

	return (0);
}