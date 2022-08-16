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
	Bureaucrat	Bureaucrat1("Boss", 1);
	Bureaucrat	Bureaucrat2("Minion", 150);
	Bureaucrat	Bureaucrat3("Lieutenant", 35);
	Form		form1("Form-1A", 45, 40);
	Form		form2("Form-2A", 150, 151);
	Form		form3("Form-1B", 0, 1);

	std::cout << Bureaucrat1;
	std::cout << Bureaucrat2;
	std::cout << Bureaucrat3;
	std::cout << form1;

	try
	{
	//	Bureaucrat2.signForm(form1);
		Bureaucrat3.signForm(form1);
		Bureaucrat1.signForm(form1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	try
	{
		Bureaucrat2.signForm(form1);
		Bureaucrat3.signForm(form1);
		Bureaucrat1.signForm(form1);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}