/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/07 16:09:22 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/07 16:09:22 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fixed.hpp"

int main(void)
{
	Fixed a;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

	std::cout << "Subject tests" << std::endl;
	std::cout << std::endl;

	std::cout << a << std::endl;
	std::cout << ++a << std::endl;
	std::cout << a << std::endl;
	std::cout << a++ << std::endl;
	std::cout << a << std::endl;

	std::cout << b << std::endl;

	std::cout << Fixed::max( a, b ) << std::endl;

	std::cout << std::endl;
	std::cout << "End of subject tests" << std::endl;
	std::cout << "Now going through user tests" << std::endl;
	std::cout << std::endl;

	std::cout << Fixed::min(a, b) << std::endl;
	std::cout << a / 0 << std::endl;
	std::cout << a / 1 << std::endl;
	std::cout << a / 2 << std::endl;
	std::cout << a * b << std::endl;
	std::cout << a + 1 << std::endl;
	std::cout << a - 1 << std::endl;

	return 0;
}