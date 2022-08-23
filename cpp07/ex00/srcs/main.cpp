/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:43:30 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/23 11:43:30 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) {
	
	int a = 2;
	int b = 3;

	::swap( a, b );
	std::cout << "a = " << a << ", b = " << b << std::endl;
	std::cout << "min( a, b ) = " << ::min( a, b ) << std::endl;
	std::cout << "max( a, b ) = " << ::max( a, b ) << std::endl;

	std::string c = "chaine1";
	std::string d = "chaine2";

	::swap(c, d);
	std::cout << "c = " << c << ", d = " << d << std::endl;
	std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
	std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
	
	return 0;
}

// int	main()
// {
// 	int a = 21;
// 	int	b = 42;
// 	int	c = 5;
// 	int	d = 5;
// 	std::string e = "Bonjour";
// 	std::string f = "Hello";

// 	::swap(a, b);
// 	std::cout << "a = " << a << ", b = " << b << std::endl;
// 	std::cout << "min(a, b) = " << ::min(a, b) << std::endl;
// 	std::cout << "max(a, b) = " << ::max(a, b) << std::endl;
// 	std::cout << "min(c, d) = " << ::min(c, d) << std::endl;
// 	std::cout << "max(c, d) = " << ::max(c, d) << std::endl;

// 	std::cout << std::endl;

// 	::swap(e, f);
// 	std::cout << "e = " << e << ", f = " << f << std::endl;
// 	std::cout << "min(e, f) = " << ::min(e, f) << std::endl;
// 	std::cout << "max(e, f) = " << ::max(e, f) << std::endl;

// 	return (0);
// }