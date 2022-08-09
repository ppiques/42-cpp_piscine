/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 15:36:56 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/07 15:36:56 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <fstream> // https://m.cplusplus.com/reference/fstream/fstream/
# include <sstream> // https://m.cplusplus.com/reference/sstream/
# include <cmath> // https://m.cplusplus.com/reference/cmath/

class Fixed
{
	public :

	Fixed();
	Fixed(int const fractionnal_bits);
	Fixed(float const fractionnal_bits);
	Fixed(Fixed const &cpy); // copy constructor
	~Fixed();

	Fixed	&operator=(Fixed const &rhs); // surcharge de l'opérateur d'affectation (rhs : right_hand_side)

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
	float	toFloat(void) const;
	int		toInt(void) const;
	
	private :

	int			_fixed_point;
	static int	_nb_fractional_bits;
};

std::ostream & operator<<( std::ostream & outstr, Fixed const & instance); // surcharge de l'opérateur << pour pouvoir insérer une représentation en virgule flottante du nombre à virgule fixe dans le flux de sortie (objet output stream) passé en paramètre.

#endif