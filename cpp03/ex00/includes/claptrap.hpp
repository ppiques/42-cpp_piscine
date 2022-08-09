/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   claptrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 13:18:02 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/09 13:18:02 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP

#include <iostream>

class ClapTrap
{
	public :

	ClapTrap();
	ClapTrap(std::string const &name);
	ClapTrap(ClapTrap const &cpy);
	~ClapTrap();

	ClapTrap	&operator=(ClapTrap const &rhs);

	void	attack(std::string const &target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	private :

	std::string _name;
	int			_hp;
	int			_ep;
	int			_ad;
};

#endif