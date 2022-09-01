/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:52:18 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/23 11:52:18 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP

#include <iostream>

template<typename T>
void	iter(T *address, long int size, void (*function)(T const &elem))
{
	for (long int i = 0; i < size; i++)
		function(address[i]);
	return;
}

template<typename T>
void	printContent(T const &elem)
{
	std::cout << elem << std::endl;
}

#endif