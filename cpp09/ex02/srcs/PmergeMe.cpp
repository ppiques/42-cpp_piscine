/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   PmergeMe.cpp									   :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: ppiques <ppiques@students.42.fr>		   +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/03/24 16:02:42 by ppiques		   #+#	#+#			 */
/*   Updated: 2023/03/24 16:02:42 by ppiques		  ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe()
{
	vect.push_back(0);
	list.push_back(0);
	return;
}

PmergeMe::PmergeMe(const char **argv, int argc) 
{
	for (int i = 1; i < argc; i++) 
	{
		int val = std::atoi(argv[i]);
		vect.push_back(val);
		list.push_back(val);
	}
}

PmergeMe::PmergeMe(const PmergeMe &cpy) 
{
	this->vect = cpy.vect;
	this->list = cpy.list;
}

PmergeMe::~PmergeMe() 
{
}

PmergeMe& PmergeMe::operator=(const PmergeMe &rhs) 
{
	if (this != &rhs)
	{
		this->vect = rhs.vect;
		this->list = rhs.list;
	}
	return (*this);
}

void PmergeMe::listMerge(std::list<int>::iterator left, std::list<int>::iterator mid, std::list<int>::iterator right)
{
	std::list<int> tmpList;
	std::list<int>::iterator i = left;
	std::list<int>::iterator j = mid;

	while (i != mid && j != right) 
	{
		if (*i <= *j)
		{
			tmpList.push_back(*i);
			i++;
		} 
		else
		{
			tmpList.push_back(*j);
			j++;
		}
	}
	while (i != mid)
	{
		tmpList.push_back(*i);
		i++;
	}
	while (j != right)
	{
		tmpList.push_back(*j);
		j++;
	}	
	i = left;
	std::list<int>::iterator it = tmpList.begin();
	while (i != right)
	{
		*i = *it;
		i++;
		it++;
	}
}

void PmergeMe::sortWithList(std::list<int>::iterator left, std::list<int>::iterator right)
{
	if (std::distance(left, right) <= 1)
		return;

	std::list<int>::iterator mid = left;
	std::advance(mid, std::distance(left, right) / 2);

	sortWithList(left, mid);
	sortWithList(mid, right);
	listMerge(left, mid, right);
}

void PmergeMe::vectorMerge(std::vector<int> &v, int left, int mid, int right)
{
	int i;
	int j;
	int k;
	int first_half = mid - left + 1;
	int second_half = right - mid;

	std::vector<int> L(first_half);
	std::vector<int> R(second_half);

	for (i = 0; i < first_half; i++)
		L[i] = v[left + i];
	for (j = 0; j < second_half; j++)
		R[j] = v[mid + 1 + j];

	i = 0;
	j = 0;
	k = left;
	while (i < first_half && j < second_half)
	{
		if (L[i] <= R[j])
		{
			v[k] = L[i];
			i++;
		}
		else
		{
			v[k] = R[j];
			j++;
		}
		k++;
	}
	while (i < first_half)
	{
		v[k] = L[i];
		i++;
		k++;
	}
	while (j < second_half)
	{
		v[k] = R[j];
		j++;
		k++;
	}
}

void PmergeMe::sortWithVector(std::vector<int> &v, int left, int right)
{
	if ((right - left) <= 1)
		return;
	int mid = left + (right - left) / 2;

	sortWithVector(v, left, mid);
	sortWithVector(v, mid + 1, right);
	vectorMerge(v, left, mid, right);	
}

void PmergeMe::addElements(const std::vector<int> &v)
{
	vect = v;
}

void PmergeMe::addElements(const std::list<int> &l)
{
	list = l;
}
