/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:53:17 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 13:53:17 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

void	tryConstruct(std::string name, int grade)
{
	try
	{
		Bureaucrat Bureaucrat(name, grade);
		std::cout << Bureaucrat.getName() << " grade " << Bureaucrat.getGrade() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

int	main()
{
	srand (time(NULL));
	tryConstruct("Boss", 1);
	tryConstruct("Minion", 150);
	tryConstruct("toohigh", 0);
	tryConstruct("toolow", 151);
	Bureaucrat	Bureaucrat1;
	Bureaucrat	Bureaucrat2;

	std::cout << std::endl;

	try
	{
		Bureaucrat1.IncrementGrade();
		std::cout << "New Bureaucrat1 grade : " << Bureaucrat1.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat1.DecrementGrade();
		std::cout << "New Bureaucrat1 grade : " << Bureaucrat1.getGrade() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----OUT OF BOUND GRADES TESTS----";
	std::cout << std::endl;

	try
	{
		while (Bureaucrat1.getGrade() < 150)
			Bureaucrat1.DecrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat1.DecrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		while (Bureaucrat2.getGrade() > 1)
			Bureaucrat2.IncrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	
	try
	{
		Bureaucrat2.IncrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << Bureaucrat1;
	std::cout << Bureaucrat2;

	return (0);
}