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
#include "form.hpp"

int	main()
{
	srand (time(NULL));

	std::cout << "----TEST CORRECT FORM----"<< std::endl;
	try
	{
		Form f1("Form-1A", 75, 50);
		std::cout << f1 << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	try
	{
		Form f2("Form-2A", 12, 80);
		std::cout << f2 << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << "----TEST INCORRECT FORM----"<< std::endl;
	try
	{
		Form f12("Form-12A", 0, 50);
		std::cout << f12 << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form f3("Form-3A", 50, 153);
		std::cout << f3 << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form f4("Form-4A", 50, 0);
		std::cout << f4 << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Form f5("Form-5A", 151, 120);
		std::cout << f5 << std::endl;	
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----TEST FORM SIGNATURE WITH SIGNFORM----" << std::endl;

	try
	{
		Bureaucrat Bureaucrat1("Boss", 1);
		Form f7("Form-7A", 100, 100);
		std::cout << f7;
		Bureaucrat1.signForm(f7);
		std::cout << f7;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;

	try
	{
		Bureaucrat Bureaucrat2("Minion", 150);
		Form f8("Form-8A", 150, 100);
		std::cout << f8;
		Bureaucrat2.signForm(f8);
		std::cout << f8;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << std::endl;


	try
	{
		Bureaucrat Bureaucrat3("Minion", 150);
		Form f9("Form-9A", 100, 100);
		std::cout << f9;
		Bureaucrat3.signForm(f9);
		std::cout << f9;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "----TEST FORM SIGNATURE WITH BESIGNED----" << std::endl;

	try
	{
		Bureaucrat Bureaucrat4("Boss", 1);
		Form f10("Form-10A", 100, 100);
		std::cout << f10;
		f10.beSigned(Bureaucrat4);
		std::cout << f10;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Bureaucrat Bureaucrat5("Minion", 150);
		Form f11("Form-11A", 100, 100);
		std::cout << f11;
		f11.beSigned(Bureaucrat5);
		std::cout << f11;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}