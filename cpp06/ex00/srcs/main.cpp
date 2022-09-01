/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:21:50 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/22 13:21:50 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* https://en.wikipedia.org/wiki/Literal_%28computer_programming%29 - A literal is a notation for representing a fixed value in source code (int, char, ...)
 Pour rappel un scalaire est un type de donnée qui ne représente qu'une seule variable à la fois : 
 la variable ne représente qu'une seule et unique donnée.
 Un entier, un caractère, un réel, un booléen, etc., sont des scalaires.
*/

#include "scalar.hpp"

int	main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error : wrong number of arguments" << std::endl;
		return (0);
	}
	try
	{
		Scalar scalar1(argv[1]);
		scalar1.printChar();
		scalar1.printInt();
		scalar1.printFloat();
		scalar1.printDouble();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}