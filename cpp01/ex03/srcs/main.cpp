/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:19:12 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/26 09:19:12 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "weapon.hpp"
#include "humanA.hpp"
#include "humanB.hpp"

int main()
{
	{
		Weapon club = Weapon("crude spiked club");

		humanA bob("Philibert", club);
		bob.attack();
		club.setType("steel club");
		bob.attack();
		std::cout << std::endl;
	}

	{
		Weapon club = Weapon("crude spiked club");

		humanB jim("Ramirez");
		jim.setWeapon(club);
		jim.attack();
		club.setType("baseball bat");
		jim.attack();
		std::cout << std::endl;

	}

	{
		Weapon sword = Weapon("sword");

		humanA timothe("Timothée", sword);
		timothe.attack();
		sword.setType("");
		timothe.attack();
		std::cout << std::endl;

	}

	{
		Weapon spear = Weapon("spear");

		humanB ronald("Ronald");
		ronald.attack();
		ronald.setWeapon(spear);
		ronald.attack();
		spear.setType("wooden spear");
		ronald.attack();
		std::cout << std::endl;
	}
}