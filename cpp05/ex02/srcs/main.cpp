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
#include "presidentialPardonForm.hpp"
#include "robotomyRequestForm.hpp"
#include "shrubberyCreationForm.hpp"

int	main()
{
	srand (time(NULL));
	Bureaucrat	Boss("Boss", 1);
	Bureaucrat	Minion("Minion", 150);
	Bureaucrat	Ltn("Lieutenant", 35);
	ShrubberyCreationForm ShrubberyForm("Garden");

	std::cout << "-----Robotomy Request Form-----" << std::endl;
	try
	{
		RobotomyRequestForm RobotomyRequestForm("Minion");
		std::cout << "Signature Grade : " << RobotomyRequestForm.getSignedGrade() << std::endl;
		std::cout << "Execution Grade : " << RobotomyRequestForm.getExecGrade() << std::endl;
		RobotomyRequestForm.beSigned(Boss);
		Boss.executeForm(RobotomyRequestForm);
		RobotomyRequestForm.execute(Ltn);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		RobotomyRequestForm RobotomyRequestForm("Minion");
		std::cout << "Signature Grade : " << RobotomyRequestForm.getSignedGrade() << std::endl;
		std::cout << "Execution Grade : " << RobotomyRequestForm.getExecGrade() << std::endl;
		RobotomyRequestForm.beSigned(Minion);
		Boss.executeForm(RobotomyRequestForm);
		RobotomyRequestForm.execute(Ltn);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	std::cout << std::endl;
	std::cout << "-----Shrubbery Creation Form-----" << std::endl;

	try
	{
		std::cout << "Signature Grade : " << ShrubberyForm.getSignedGrade() << std::endl;
		std::cout << "Execution Grade : " << ShrubberyForm.getExecGrade() << std::endl;
		ShrubberyForm.beSigned(Ltn);
		Ltn.executeForm(ShrubberyForm);
		ShrubberyForm.execute(Ltn);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	std::cout << "-----Presidential Pardon Form-----" << std::endl;

	try
	{
		PresidentialPardonForm PresidentialForm("Lieutenant");
		std::cout << "Signature Grade : " << PresidentialForm.getSignedGrade() << std::endl;
		std::cout << "Execution Grade : " << PresidentialForm.getExecGrade() << std::endl;
		PresidentialForm.beSigned(Boss);
		Boss.executeForm(PresidentialForm);
		PresidentialForm.execute(Boss);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		PresidentialPardonForm PresidentialForm("Lieutenant");
		std::cout << "Signature Grade : " << PresidentialForm.getSignedGrade() << std::endl;
		std::cout << "Execution Grade : " << PresidentialForm.getExecGrade() << std::endl;
		PresidentialForm.beSigned(Boss);
		Ltn.executeForm(PresidentialForm);
		PresidentialForm.execute(Boss);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		PresidentialPardonForm PresidentialForm("Lieutenant");
		std::cout << "Signature Grade : " << PresidentialForm.getSignedGrade() << std::endl;
		std::cout << "Execution Grade : " << PresidentialForm.getExecGrade() << std::endl;
		Boss.executeForm(PresidentialForm);
		PresidentialForm.execute(Boss);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}