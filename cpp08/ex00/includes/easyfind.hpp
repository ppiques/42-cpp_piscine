/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:32:00 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/25 11:32:00 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
typename T::iterator	easyfind(T &container, int i)
{
	typename T::iterator	ret;

	ret = find(container.begin(), container.end(), i);
	return (ret);
}

template<typename T>
void	printIterator(T iterator, T last)
{
	if (iterator != last)
		std::cout << "Iterator value : " << *iterator << std::endl;
	else
		std::cout << "Error : Iterator value not found" << std::endl;
}

#endif