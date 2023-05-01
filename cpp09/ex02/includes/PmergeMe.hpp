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

#include <vector>
#include <list>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <algorithm>

class PmergeMe 
{
	public:
		PmergeMe();
		PmergeMe(const char **argv, int argc);
		PmergeMe(const PmergeMe &cpy);
		~PmergeMe();

		PmergeMe& operator=(const PmergeMe& rhs);

		void sortWithList(std::list<int>::iterator left, std::list<int>::iterator right);
		void listInsertionSort(std::list<int>::iterator left, std::list<int>::iterator right);
		void listMerge(std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right);
		
		void sortWithVector(std::vector<int> &v);
		void vectorSortSplitArray(std::vector<std::vector<int> > &split_array, int length);
		void vectorInsert(std::vector<int> &element, std::vector<std::vector<int> > &split_array, int n);
		std::vector<std::vector<int> > vectorSplitArray(std::vector<int> &v);
		std::vector<std::vector<int> > vectorSortEachPairs(std::vector<std::vector<int> > &split_array);
		std::vector<int> sortIntoVect(const std::vector<std::vector<int> > &sorted_split_array, int straggler);
		
		void addElements(const std::vector<int>& v);
        void addElements(const std::list<int>& l);

		std::vector<int>	vect;
		std::list<int>		list;
};

#endif
