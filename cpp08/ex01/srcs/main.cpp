/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:57:57 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/25 11:57:57 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "span.hpp"

int	main()
{
	srand (time(NULL));
	std::cout << "---BASIC TEST---" << std::endl;

	Span sp = Span(5);

	sp.addNumber(6);
	sp.addNumber(3);
	sp.addNumber(17);
	sp.addNumber(9);
	sp.addNumber(11);

	std::cout << "shortestSpan : " << sp.shortestSpan() << std::endl;
	std::cout << "longestSpan : " << sp.longestSpan() << std::endl;

	std::cout << std::endl;
	std::cout << "---EXTRA TESTS---" << std::endl;

	try
	{
		Span sp1 = Span(2);
		sp1.addNumber(17);
		sp1.addNumber(18);

		std::cout << "1-shortestSpan : " << sp1.shortestSpan() << std::endl;
		std::cout << "1-longestSpan : " << sp1.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Span sp2 = Span(4);
		sp2.addRandomNumber(0, 10000);
		sp2.addRandomNumber(0, 10000);
		sp2.addRandomNumber(0, 10000);
		sp2.addRandomNumber(0, 10000);

		std::cout << "2-shortestSpan : " << sp2.shortestSpan() << std::endl;
		std::cout << "2-longestSpan : " << sp2.longestSpan() << std::endl;

	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Span bigsp = Span(10000);
		bigsp.addRandomNumbers(0, 100000, 10000);
		
		std::cout << "big-shortestSpan : " << bigsp.shortestSpan() << std::endl;
		std::cout << "big-longestSpan : " << bigsp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	try
	{
		Span rangesp = Span(4);
		std::vector<int>	temp;

		temp.push_back(1);
		temp.push_back(5);
		temp.push_back(15);
		rangesp.addRange(temp.begin(), temp.end());
		
		std::cout << "range-shortestSpan : " << rangesp.shortestSpan() << std::endl;
		std::cout << "range-longestSpan : " << rangesp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	std::cout << std::endl;

	try
	{
		Span smallsp = Span(1);
		smallsp.addNumber(42);

		std::cout << "sperror-shortestSpan : " << smallsp.shortestSpan() << std::endl; // shouldn't print
		std::cout << "sperror-longestSpan : " << smallsp.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	
	std::cout << std::endl;

	try
	{
		Span sperror = Span(2);
		sperror.addNumber(17);
		sperror.addNumber(18);
		sperror.addNumber(19);

		std::cout << "sperror-shortestSpan : " << sperror.shortestSpan() << std::endl; // shouldn't print
		std::cout << "sperror-longestSpan : " << sperror.longestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	return (0);
}