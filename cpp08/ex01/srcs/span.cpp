/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:58:01 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/25 11:58:01 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

Span::Span()
{
	this->_N = 0;
	return ;
}

Span::Span(unsigned int const &N)
{
	this->_N = N;
	return;
}

Span::Span(Span const &cpy)
{
	(*this) = cpy;
	return ;
}

Span::~Span()
{
	return;
}

Span &Span::operator=(Span const &rhs)
{
	if (this == &rhs)
		return (*this);
	this->_N = rhs._N;
	this->_container = rhs._container;
	return (*this);
}

void	Span::addNumber(int value)
{
	if (this->_container.size() >= this->_N)
		throw std::range_error("Error : No more room in container.");
	this->_container.push_back(value);
}

void	Span::addRandomNumber(int min, int max)
{
	if (this->_container.size() >= this->_N)
		throw std::range_error("Error : No more room in container.");
	int random = rand() % max + min;
	this->_container.push_back(random);
}

void	Span::addRandomNumbers(int min, int max, unsigned int nb)
{
	while (nb != 0)
	{
		addRandomNumber(min, max);
		nb--;
	}
}

void	Span::addRange(std::vector<int>::iterator start, std::vector<int>::iterator end)
{
	std::vector<int> vector(start, end);

	if (vector.size() > this->_N - this->_container.size())
		throw std::range_error("Error : No more room in container.");
	copy(vector.begin(), vector.end(), std::back_inserter(this->_container));
}

int	Span::shortestSpan(void) const
{
	std::vector<int>			vector = this->_container;
	std::vector<int>::iterator	min;
	std::vector<int>::iterator	max;
	std::vector<int>::iterator	iterator;
	int							ret;

	if (this->_container.size() <= 1)
		throw std::range_error("Error : the container only has a single object. Unable to use shortestSpan.");
	sort(vector.begin(), vector.end());
	min = vector.begin();
	max = vector.end() - 1;
	ret = *max - *min;
	if (this->_container.size() == 2)
		return (ret);
	for (iterator = vector.begin(); iterator != vector.end() - 1 && ret != 0; iterator++)
	{
		if (*(iterator + 1) - *iterator < ret)
			ret = *(iterator + 1) - *iterator;
	}
	return (ret);
}

int	Span::longestSpan(void) const
{
	std::vector<int>			vector = this->_container;
	std::vector<int>::iterator	min;
	std::vector<int>::iterator	max;
	int							ret;

	if (this->_container.size() <= 1)
		throw std::range_error("Error : the container only has a single object. Unable to use longestSpan.");
	sort(vector.begin(), vector.end());
	min = vector.begin();
	max = vector.end() - 1;
	ret = *max - *min;
	return (ret);
}