/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:22:45 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 14:22:45 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain
{
	public :

	Brain();
	Brain(const Brain &cpy); // allows deep copies
	virtual ~Brain();

	Brain &operator=(const Brain &rhs);

	std::string ideas[100];
};

#endif