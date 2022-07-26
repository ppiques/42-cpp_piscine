/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 09:03:57 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/26 09:03:57 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int	main()
{
	std::string brain = "HI THIS IS BRAIN";
	std::string *stringPTR = &brain;
	std::string &stringREF = brain;

	std::cout << std::endl;
	std::cout << "Memory address of the string variable : " << &brain << std::endl;
	std::cout << "Memory address held by stringPTR : " <<  stringPTR << std::endl;
	std::cout << "Memory address held by stringREF : " << &stringREF << std::endl;
	std::cout << "String value : " << brain << std::endl;
	std::cout << "Value pointed to by stringPTR : " << *stringPTR << std::endl;
	std::cout << "Value pointed to by stringREF : " << stringREF << std::endl;

	return (0);
}