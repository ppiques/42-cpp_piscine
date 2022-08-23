/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 11:38:01 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/23 11:38:01 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
# define WHATEVER_HPP

#include <iostream>

template<typename T>
void	swap(T &i, T &k)
{
	T tmp;

	tmp = i;
	i = k;
	k = tmp;
}

template<typename T>
T	min(T x, T y)
{
	return (x < y ? x : y);
}

template<typename T>
T	max(T x, T y)
{
	return (x > y ? x : y);
}

#endif