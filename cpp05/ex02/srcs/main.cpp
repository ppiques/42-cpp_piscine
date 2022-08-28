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
	Form		*RobotomyRequestForm = new class RobotomyRequestForm("Minion");
	Form		*PresidentialForm = new PresidentialPardonForm("Lieutenant");
	Form		*ShrubberyForm = new ShrubberyCreationForm("Garden");

	try
	{
		std::cout << "-----Robotomy Request Form-----" << std::endl;
		std::cout << "Signature Grade : " << RobotomyRequestForm->getSignedGrade() << std::endl;
		std::cout << "Execution Grade : " << RobotomyRequestForm->getExecGrade() << std::endl;
		RobotomyRequestForm->beSigned(Boss);
		//	RobotomyRequestForm->beSigned(Minion); // should catch an error
		Boss.executeForm(*RobotomyRequestForm);
		RobotomyRequestForm->execute(Ltn);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;
	
	try
	{
		std::cout << "-----Shrubbery Creation Form-----" << std::endl;
		std::cout << "Signature Grade : " << ShrubberyForm->getSignedGrade() << std::endl;
		std::cout << "Execution Grade : " << ShrubberyForm->getExecGrade() << std::endl;
		ShrubberyForm->beSigned(Ltn);
		Ltn.executeForm(*ShrubberyForm);
		ShrubberyForm->execute(Ltn);
		// ShrubberyForm->execute(Minion); // should catch an error
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		std::cout << "-----Presidential Pardon Form-----" << std::endl;
		std::cout << "Signature Grade : " << PresidentialForm->getSignedGrade() << std::endl;
		std::cout << "Execution Grade : " << PresidentialForm->getExecGrade() << std::endl;
		// PresidentialForm->beSigned(Minion); // should catch an error
		PresidentialForm->beSigned(Boss);
		Boss.executeForm(*PresidentialForm);
		PresidentialForm->execute(Boss);
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}

	delete RobotomyRequestForm;
	delete PresidentialForm;
	delete ShrubberyForm;

	return (0);
}