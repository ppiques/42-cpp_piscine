/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:02:01 by ppiques           #+#    #+#             */
/*   Updated: 2022/09/01 18:07:22 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "array.hpp"

#define MAX_VAL 750
int main(int, char**)
{
	Array<int> numbers(MAX_VAL);
	int* mirror = new int[MAX_VAL];


	std::cout << "----SUBJECT TESTS----" << std::endl;
	for (int i = 0; i < MAX_VAL; i++)
	{
		const int value = 0;
		numbers[i] = value;
		mirror[i] = value;
	}
	//SCOPE
	{
		Array<int> tmp = numbers;
		Array<int> test(tmp);
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		if (mirror[i] != numbers[i])
		{
			std::cerr << "didn't save the same value!!" << std::endl;
			return 1;
		}
	}
	try
	{
		numbers[-2] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		numbers[MAX_VAL] = 0;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	for (int i = 0; i < MAX_VAL; i++)
	{
		numbers[i] = 42;
	}
	delete [] mirror;

	std::cout << std::endl;
	std::cout << "----EXTRA TESTS----" << std::endl;
	
	
    Array<int> empty_arr;
    try
    {
        empty_arr[5] = 0;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }

	std::cout << std::endl;
	
	Array<float> float_array(10);
	float f = 0.5;
	for (int i = 0; i < 10; i++)
		float_array[i] = f++;
	std::cout << "float_array :" << std::endl;
	std::cout << "size = " << float_array.size() << std::endl;
    std::cout << "float_array[0] = " << float_array[0] << std::endl;
    std::cout << "float_array[1] = " << float_array[1] << std::endl;
    std::cout << "float_array[2] = " << float_array[2] << std::endl;
    std::cout << "float_array[3] = " << float_array[3] << std::endl;
	
	std::cout << std::endl;
	
	Array<float> float_array2(float_array);
	std::cout << "float_array2 :" << std::endl;
	std::cout << "size = " << float_array2.size() << std::endl;
    std::cout << "float_array2[0] = " << float_array2[0] << std::endl;
    std::cout << "float_array2[1] = " << float_array2[1] << std::endl;

    std::cout << std::endl;
	
    Array<std::string> str_array(10);
    str_array[0] = "Test0";
    str_array[1] = "Test1";
    str_array[2] = "Test2";
    str_array[3] = "Test3";
    std::cout << "str_array :" << std::endl;
    std::cout << "size = " << str_array.size() << std::endl;
    std::cout << "str_array[0] = " << str_array[0] << std::endl;
    std::cout << "str_array[1] = " << str_array[1] << std::endl;
    std::cout << "str_array[2] = " << str_array[2] << std::endl;
    std::cout << "str_array[3] = " << str_array[3] << std::endl;
	return 0;
}