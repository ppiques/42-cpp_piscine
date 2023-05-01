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
	int								straggler;
	std::vector<std::vector<int> >	split_array;

	if (v.size() % 2 != 0)
	{
		straggler = v.back();
		v.pop_back();
	}
	else
		straggler = -1;

	split_array = vectorSplitArray(v);
	split_array = vectorSortEachPairs(split_array);
	vectorSortSplitArray(split_array, split_array.size() - 1);
	vect = sortIntoVect(split_array, straggler);
}

std::vector<std::vector<int> > PmergeMe::vectorSplitArray(std::vector<int> &v)
{
	std::vector<std::vector<int> >		split_array;
	std::vector<int>					temp_array;
	int									value;
	int									temp_length;

	for (long unsigned int i = 0; i < v.size(); i++)
	{
		value = v[i];
		temp_length = temp_array.size();
		if (temp_length == 1)
		{
			temp_array.push_back(value);
			split_array.push_back(temp_array);
			temp_array.clear();
		}
		else if (split_array.size() * 2 == v.size() - 1)
		{
			std::vector<int> new_pair;
			new_pair.push_back(value);
			split_array.push_back(new_pair);
		}
		else if (temp_length == 0)
			temp_array.push_back(value);
	}
	return (split_array);
}

std::vector<std::vector<int> > PmergeMe::vectorSortEachPairs(std::vector<std::vector<int> > &split_array)
{
	for (long unsigned int i = 0; i < split_array.size(); i++)
	{
		if (split_array[i].size() != 1 && split_array[i][0] > split_array[i][1])
		{
			int temp = split_array[i][0];
			split_array[i][0] = split_array[i][1];
			split_array[i][1] = temp;
		}
	}
	return (split_array);
}

void PmergeMe::vectorSortSplitArray(std::vector<std::vector<int> > &split_array, int length)
{
	if (length < 1)
		return;
	else
	{
		vectorSortSplitArray(split_array, length - 1);
		vectorInsert(split_array[length], split_array, length - 1);
	}
}

void PmergeMe::vectorInsert(std::vector<int> &element, std::vector<std::vector<int> > &split_array, int n)
{
	if (n < 0) 
		split_array[0] = element;
	else if (element[1] >= split_array[n][1]) 
	{
		long unsigned int m = n;
		if (m == split_array.size() - 1) 
			split_array.push_back(element);
		else 
			split_array[m + 1] = element;
	} 
	else 
	{
		long unsigned int m = n;
		if (m == split_array.size() - 1) 
			split_array.push_back(split_array[n]);
		else 
		{
			split_array[n + 1] = split_array[n];
			vectorInsert(element, split_array, n - 1);
		}
	}
}

int jacobsthal(int n) 
{
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return (jacobsthal(n - 1) + 2 * jacobsthal(n - 2));
}

std::vector<int> build_jacob_insertion_sequence(const std::vector<int> &array) 
{
	int array_len = array.size();
	int jacob_index = 3; // The first one that matters
	std::vector<int> end_sequence;

	while (jacobsthal(jacob_index) < array_len - 1) 
	{
		end_sequence.push_back(jacobsthal(jacob_index));
		jacob_index++;
	}
	return (end_sequence);
}

std::vector<int> PmergeMe::sortIntoVect(const std::vector<std::vector<int> > &sorted_split_array, int straggler)
{
	// Placeholders for the key sequences
	std::vector<int> S;
	std::vector<int> pend;

	for (long unsigned int i = 0; i < sorted_split_array.size(); i++) 
	{
		// Add the larger elements into 'S'
		S.push_back(sorted_split_array[i][1]);
		// Add smaller elements into 'pend'
		pend.push_back(sorted_split_array[i][0]);
	}

	// Insert the first element in S
	// We know it's the smallest since it was already sorted smaller in the first pairing
	S.insert(S.begin(), pend[0]);

	// Now, we need to build an insertion sequence, taking advantage of the Jacobsthal number set

	// Store some placeholders
	int 				jacobindex = 3; // Start at three, since we already inserted 1 and we can skip the beginning of this sequence
	int					last = -1; // -1 is default, -2 is in loop
	int					item;
	long unsigned int	iterator = 0; // We already added one
	std::vector<int>	indexSequence;
	std::vector<int>	jacob_insertion_sequence = build_jacob_insertion_sequence(pend);

	// Iterate through the rest of 'pend'
	while (iterator <= pend.size()) 
	{
		if (!jacob_insertion_sequence.empty() && last != -2) 
		{
			indexSequence.push_back(jacob_insertion_sequence[0]);
			item = pend[jacob_insertion_sequence[0] - 1];
			// Now pop it off
			jacob_insertion_sequence.erase(jacob_insertion_sequence.begin());
			last = -2;
		} 
		else 
		{
			// Else, let's fill it with what's remaining most efficiently
			// First, make sure the Jacobsthal number wasn't already used
			if (find(indexSequence.begin(), indexSequence.end(), iterator) != indexSequence.end())
				iterator++;
			item = pend[iterator - 1];
			indexSequence.push_back(iterator);
			last = -3;
		}

		// We now have the most optimal item to insert (with the least comparisons!).
		// Let's use binary search to get the insertion point
		std::vector<int>::iterator	insertion_point = lower_bound(S.begin(), S.end(), item);

		// Then insert it into S
		S.insert(insertion_point, item);

		// Increment our iterators
		iterator++;
		jacobindex++;
	}

	// If an odd-numbered array was given, we took off the straggler in the beginning.
	// We now binary search insert the entire array for this one, following the algorithm.
	if (straggler != -1) 
	{
		std::vector<int>::iterator insertion_point = lower_bound(S.begin(), S.end(), straggler);
		S.insert(insertion_point, straggler);
	}
	return S;
}

void PmergeMe::addElements(const std::vector<int> &v)
{
	vect = v;
}

void PmergeMe::addElements(const std::list<int> &l)
{
	list = l;
}
