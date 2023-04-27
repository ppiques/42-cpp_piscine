/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:42:19 by ppiques           #+#    #+#             */
/*   Updated: 2023/03/24 14:42:19 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char *argv[]) 
{
	if (argc != 2) 
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	if (strlen(argv[1]) <= 1)
	{
		std::cerr << "Error" << std::endl;
		return 1;
	}

	RPN rpn(argv[1]);
	rpn.operation();
	return 0;
}
