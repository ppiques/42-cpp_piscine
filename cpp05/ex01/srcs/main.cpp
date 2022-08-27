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
	Bureaucrat	Boss("Boss", 1);
	Bureaucrat	Minion("Minion", 150);
	Bureaucrat	Ltn("Lieutenant", 35);
	Form		form1("Form-1A", 45, 40);
	Form		form2("Form-2A", 150, 151); // too low error
	Form		form3("Form-1B", 0, 1); // too high error
	Form		form4;

	std::cout << std::endl;

	std::cout << Boss;
	std::cout << Minion;
	std::cout << Ltn;
	std::cout << form1;
	std::cout << form4;

	std::cout << std::endl;

	try
	{
		Ltn.signForm(form1);
		Boss.signForm(form1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		Minion.signForm(form1); // should catch an error error, skipping the rest
		Ltn.signForm(form1);
		Boss.signForm(form1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}