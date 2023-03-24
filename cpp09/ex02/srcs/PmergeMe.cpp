/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:02:42 by ppiques           #+#    #+#             */
/*   Updated: 2023/03/24 16:02:42 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	return;
}

PmergeMe::PmergeMe(const std::string& input)
{
    int value;
    std::stringstream ss(input);
    while (ss >> value) 
	{
        _dataVec.push_back(value);
        _dataList.push_back(value);
    }
	return;
}

PmergeMe::PmergeMe(const PmergeMe &cpy)
{
	(*this) = cpy;
	return;
}

PmergeMe& PmergeMe::operator=(const PmergeMe& rhs)
{
    this->_dataVec = rhs._dataVec;
    this->_dataList = rhs._dataList;
    return (*this);
}

PmergeMe::~PmergeMe()
{
	return;
}

