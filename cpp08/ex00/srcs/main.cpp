/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:28:58 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/25 11:28:58 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://cplusplus.com/reference/stl/
// https://cplusplus.com/reference/iterator/ an iterator looks like a fancy pointer

#include "easyfind.hpp"

int	main()
{
	std::vector<int>			vector;
	std::vector<int>::iterator	iterator;

	vector.reserve(5);

	vector.push_back(10);
	vector.push_back(20);
	vector.push_back(30);
	vector.push_back(40);
	vector.push_back(50);

	iterator = easyfind(vector, 40);
	printIterator(iterator, vector.end());
	iterator = easyfind(vector, 42);
	printIterator(iterator, vector.end());

	return (0);
}

