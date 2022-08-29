/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   diamondtrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:15:20 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/09 15:15:20 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

#include "claptrap.hpp"
#include "scavtrap.hpp"
#include "fragtrap.hpp"

class DiamondTrap : public FragTrap, public ScavTrap // https://www.geeksforgeeks.org/virtual-base-class-in-c/ we now use virutal classes for scav and frag to avoid ambiguities
{
	public :

	DiamondTrap();
	DiamondTrap(std::string const &name);
	DiamondTrap(DiamondTrap const &cpy);
	~DiamondTrap();

	DiamondTrap	&operator=(DiamondTrap const &rhs);

	void	whoAmI();

	private :

	std::string _name;
};

#endif