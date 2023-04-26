/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:18:43 by ppiques           #+#    #+#             */
/*   Updated: 2023/03/24 14:18:43 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: not enough arguments" << std::endl;
		return 1;
	}

	BitcoinExchange btc;

	if (btc.parseDatabase() == 1)
		return 1;
	btc.parseInput(argv[1]);
	btc.printOutput();

	return 0;
}
