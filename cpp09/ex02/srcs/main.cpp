/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 16:02:54 by ppiques           #+#    #+#             */
/*   Updated: 2023/03/24 16:02:54 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main(int argc, const char **argv)
{
    if (argc < 2)
    {
        std::cerr << "Error: missing arguments" << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; i++) 
	{
		std::string str = "0123456789- ";
		if (str.find(argv[i][0]) == std::string::npos)
		{
			std::cout << "Error: wrong input" << std::endl;
			return 1;
		}
        int val = std::atoi(argv[i]);
		if (val < 0)
		{
			std::cout << "Error: Negative numbers are not allowed" << std::endl;
			return 1;
		}
    }

    PmergeMe merger(argv, argc);

    int n = merger.vect.size();

    std::cout << "Before: ";
    for (int i = 0; i < n; i++)
        std::cout << merger.vect[i] << " ";
    std::cout << std::endl;

    clock_t vector_start_time = clock();
    merger.sortWithVector(merger.vect, 0, n - 1);
    clock_t vector_end_time = clock();

    std::cout << "After: ";
    for (int i = 0; i < n; i++)
        std::cout << merger.vect[i] << " ";
    std::cout << std::endl;

    clock_t list_start_time = clock();
    merger.sortWithList(merger.list.begin(), merger.list.end());
    clock_t list_end_time = clock();

	// std::cout << "After: ";
	// for (std::list<int>::iterator it = merger.list.begin(); it != merger.list.end(); it++)
	// std::cout << *it << " ";
    // std::cout << std::endl;

    double vector_time = (double)(vector_end_time - vector_start_time) / CLOCKS_PER_SEC * 1000000.00;
    double list_time = (double)(list_end_time - list_start_time) / CLOCKS_PER_SEC * 1000000.00;

    std::cout << "Time to process a range of " << n << " elements with std::vector: " << vector_time << " us" << std::endl;
    std::cout << "Time to process a range of " << n << " elements with std::list: " << list_time << " us" << std::endl;

    return 0;
}
