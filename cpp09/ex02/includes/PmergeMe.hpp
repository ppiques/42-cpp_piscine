/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:03:01 by ppiques           #+#    #+#             */
/*   Updated: 2023/03/24 16:03:01 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <chrono>
#include <vector>
#include <list>

class PmergeMe 
{
	public:
		PmergeMe();
		PmergeMe(const std::string &input);
		PmergeMe(const PmergeMe &cpy);
		~PmergeMe();

		PmergeMe& operator=(const PmergeMe& rhs);

		void sortWithVector();
		void sortWithList();

	private:
		std::vector<int> _dataVec;
		std::list<int> _dataList;
};

#endif