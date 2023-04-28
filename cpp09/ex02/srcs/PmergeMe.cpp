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

void PmergeMe::sortWithList(std::list<int>::iterator left, std::list<int>::iterator right)
{
	int	size = std::distance(left, right);
	if (size <= 1)
		return;
	if (size <= 10)
	{
		listInsertionSort(left, right);
		return;
	}
	std::list<int>::iterator mid = left;
	std::advance(mid, size / 2);

	sortWithList(left, mid);
	sortWithList(mid, right);
	listMerge(left, mid, right);
}

void PmergeMe::listInsertionSort(std::list<int>::iterator left, std::list<int>::iterator right)
{
    for (std::list<int>::iterator i = left; i != right; i++)
    {
        std::list<int>::iterator j = i;
        while (j != left && *j < *(--std::list<int>::iterator(j)))
        {
            std::swap(*j, *(--std::list<int>::iterator(j)));
            j--;
        }
    }
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

void PmergeMe::sortWithVector(std::vector<int> &v)
{
	int						straggler;
	vector<vector<int> >	split_array;

	if (v.size() % 2 != 0)
	{
		straggler = v.back();
		v.pop_back();
	}
	else
		straggler = NULL;

	split_array = vectorSplitArray(v);
	split_array = vectorSortEachPairs(split_array);
	split_array = vectorSortSplitArray(split_array);
}

vector<vector<int> > PmergeMe::vectorSplitArray(std::vector<int> &v)
{
  vector<vector<int> > split_array;
  vector<int> temp_array;

  for (int i = 0; i < v.size(); i++)
  {
    int value = v[i];
    int temp_length = temp_array.size();
    if (temp_length == 1)
    {
      temp_array.push_back(value);
      split_array.push_back(temp_array);
      temp_array.clear();
    }
    else if (split_array.size() * 2 == v.size() - 1)
    {
      vector<int> new_pair;
      new_pair.push_back(value);
      split_array.push_back(new_pair);
    }
    else if (temp_length == 0)
    {
      temp_array.push_back(value);
    }
  }
  return (split_array);
}

vector<vector<int> > PmergeMe::vectorSortEachPairs(vector<vector<int> > &split_array)
{
	for (int i = 0; i < split_array.size(); i++)
	{
		vector<int> pair = split_array[i];
		if (pair.size() != 1 && (pair[0] > pair[1]))
		{
			int	j;
			j = pair[0];
			pair[0] = pair[1];
			pair[1] = j;
		}
	}
	return (split_array);
}

vector<vector<int> > PmergeMe::vectorSortSplitArray(vector<vector<int> &split_array)
{
	for (int i = 0; i < split_array.size(); i++)
	{
		// need recursivity
	}
}

void PmergeMe::vectorInsertionSort(std::vector<int> &v, int left, int right)
{
    for (int i = left + 1; i <= right; i++)
    {
        int k = v[i];
        int j = i - 1;
        while (j >= left && v[j] > k)
        {
            v[j+1] = v[j];
            j--;
        }
        v[j+1] = k;
    }
}

void PmergeMe::vectorMerge(std::vector<int> &v, int left, int mid, int right)
{
    int i, j, k;
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

void PmergeMe::addElements(const std::vector<int> &v)
{
	vect = v;
}

void PmergeMe::addElements(const std::list<int> &l)
{
	list = l;
}
