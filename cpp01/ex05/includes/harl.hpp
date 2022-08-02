/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 15:52:58 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/02 15:52:58 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>

class Harl
{
	public :

	Harl();
	~Harl();

	void	complain(std::string level);

	private :

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);
};

#endif