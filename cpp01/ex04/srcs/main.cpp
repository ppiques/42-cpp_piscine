/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 11:18:31 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/27 11:18:31 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

int	main(int argc, char **argv)
{
	Replacer replacer;
	if (argc == 1)
	{
		std::cout << "Arguments : filename, s1 (to be replaced), s2 (replacing string)" << std::endl;
		return (0);
	}
	if (argc != 4)
	{
		std::cout << "Error : invalid number of arguments." << std::endl;
		return (0);
	}
	replacer.replace_file(argv[1], argv[2], argv[3]);
	return (0);
}