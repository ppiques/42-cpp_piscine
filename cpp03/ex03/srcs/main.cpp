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
#include "fragtrap.hpp"
#include "diamondtrap.hpp"

int	main()
{
	ClapTrap clapTrap1("Clap");
	ScavTrap scavTrap2("Scav");
	FragTrap fragTrap3("Frag");
	DiamondTrap DiamondTrap4("Diamond");

	clapTrap1.attack("Scav");
	scavTrap2.takeDamage(0);
	clapTrap1.beRepaired(200);
	scavTrap2.attack("Clap");
	clapTrap1.takeDamage(20);

	std::cout << std::endl;

	clapTrap1.beRepaired(0);
	clapTrap1.beRepaired(1);
	scavTrap2.beRepaired(2);
	scavTrap2.beRepaired(3);

	std::cout << std::endl;

	scavTrap2.guardGate();

	std::cout << std::endl;

	scavTrap2.takeDamage(500);
	scavTrap2.attack("Clap");
	clapTrap1.attack("Scav");

	std::cout << std::endl;

	fragTrap3.highFivesGuys();
	fragTrap3.beRepaired(50);
	fragTrap3.takeDamage(50);
	fragTrap3.attack("Scav");
	scavTrap2.takeDamage(30);

	std::cout << std::endl;

	DiamondTrap4.highFivesGuys();
	DiamondTrap4.guardGate();
	DiamondTrap4.attack("Frag");
	DiamondTrap4.beRepaired(50);
	DiamondTrap4.takeDamage(60);
	DiamondTrap4.whoAmI();

	std::cout << std::endl;
	
	return (0);
}