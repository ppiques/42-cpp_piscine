/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:48:14 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/19 13:48:14 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (argc == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
	else
	{
		while (i != argc)
		{
			for (int j = 0; j < (int)strlen(argv[i]); j++)
				putchar(toupper(argv[i][j]));
			std::cout << " ";
			i++;
		}
		std::cout << std::endl;
	}
	return (0);
}