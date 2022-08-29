/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scavtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 14:29:45 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/09 14:29:45 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

#include "claptrap.hpp"

class ScavTrap : public ClapTrap
{
	public :

	ScavTrap();
	ScavTrap(std::string const &name);
	ScavTrap(ScavTrap const &cpy);
	~ScavTrap();

	ScavTrap	&operator=(ScavTrap const &rhs);

	void	attack(std::string const &target);
	void	guardGate();
};

#endif