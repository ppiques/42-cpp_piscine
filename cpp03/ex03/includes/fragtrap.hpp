/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fragtrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 15:00:55 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/09 15:00:55 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

#include "claptrap.hpp"

class FragTrap : virtual public ClapTrap
{
	public :

	FragTrap();
	FragTrap(std::string const &name);
	FragTrap(FragTrap const &cpy);
	~FragTrap();

	FragTrap	&operator=(FragTrap const &rhs);

	void	highFivesGuys(void);

	protected :

	int	_frag_hp;
	int	_frag_ad;
};

#endif