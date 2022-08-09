/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 14:44:08 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/07 14:44:08 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
# include <iostream>

class Fixed
{
	public :

	Fixed();
	Fixed(Fixed const &cpy); // copy constructor
	~Fixed();

	Fixed	&operator=(Fixed const &rhs); // surcharge de l'opérateur d'affectation (rhs : right_hand_side)

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	private :

	int			_fixed_point;
	static int	_nb_fractional_bits;



};

#endif