/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:57:55 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/25 11:57:55 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

class Span
{
	public :

	Span();
	Span(unsigned int const &N);
	Span(const Span &cpy);
	~Span();

	Span &operator=(const Span &rhs);

	int	shortestSpan(void) const;
	int	longestSpan(void) const;

	void	addNumber(int value);
	void	addRandomNumber(int min, int max);
	void	addRandomNumbers(int min, int max, unsigned int nb);
	void	addRange(std::vector<int>::iterator start, std::vector<int>::iterator end);

	private :

	unsigned int		_N;
	std::vector<int>	_container;
};

#endif