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

void	Span::addRandomNumbers(int min, int max, int nb)
{
	if (this->_container.size() >= this->_N + nb)
		throw std::range_error("Error : No more room in container.");
	while (nb >= 0)
	{
		int random = rand() % max + min;
		this->_container.push_back(random);
		nb--;
	}
}

int	Span::shortestSpan(void) const
{
	std::vector<int>			tmp = this->_container;
	std::vector<int>::iterator	min;
	std::vector<int>::iterator	max;
	std::vector<int>::iterator	iterator;
	int							ret;

	if (this->_container.size() <= 1)
		throw std::range_error("Error : the container only has a single object. Unable to use shortestSpan.");
	sort(tmp.begin(), tmp.end());
	min = tmp.begin();
	max = tmp.end() - 1;
	ret = *max - *min;
	if (this->_container.size() == 2)
		return (ret);
	for (iterator = tmp.begin() + 1; iterator != tmp.end() - 1 && ret != 0; iterator++)
	{
		if (*(iterator + 1) - *iterator < ret)
			ret = *(iterator + 1) - *iterator;
	}
	return (ret);
}

int	Span::longestSpan(void) const
{
	std::vector<int>			tmp = this->_container;
	std::vector<int>::iterator	min;
	std::vector<int>::iterator	max;
	int							ret;

	if (this->_container.size() <= 1)
		throw std::range_error("Error : the container only has a single object. Unable to use longestSpan.");
	sort(tmp.begin(), tmp.end());
	min = tmp.begin();
	max = tmp.end() - 1;
	ret = *max - *min;
	return (ret);
}