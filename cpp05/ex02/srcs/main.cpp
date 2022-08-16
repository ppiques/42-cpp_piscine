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
	Bureaucrat	Bureaucrat1("Boss", 1);
	Bureaucrat	Bureaucrat2("Minion", 150);
	Bureaucrat	Bureaucrat3("Lieutenant", 35);
	Form		*RobotomyRequestForm = new class RobotomyRequestForm("Minion");
	Form		*PresidentialForm = new PresidentialPardonForm("Lieutenant");
	Form		*ShrubberyForm = new ShrubberyCreationForm("Boss");

	try
	{
		std::cout << "-----Robotomy Request Form-----" << std::endl;
		std::cout << "Signature Grade : " << RobotomyRequestForm->getSignedGrade() << std::endl;
		std::cout << "Execution Grade : " << RobotomyRequestForm->getExecGrade() << std::endl;
		RobotomyRequestForm->beSigned(Bureaucrat1);
		//	RobotomyRequestForm->beSigned(Bureaucrat2);
		Bureaucrat1.executeForm(*RobotomyRequestForm);
		RobotomyRequestForm->execute(Bureaucrat3);
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
		std::cout << "Execution Grade : " << RobotomyRequestForm->getExecGrade() << std::endl;
		ShrubberyForm->beSigned(Bureaucrat3);
		Bureaucrat3.executeForm(*ShrubberyForm);
		ShrubberyForm->execute(Bureaucrat3);
		// ShrubberyForm->execute(Bureaucrat2);
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
		// PresidentialForm->beSigned(Bureaucrat2);
		PresidentialForm->beSigned(Bureaucrat1);
		Bureaucrat1.executeForm(*PresidentialForm);
		PresidentialForm->execute(Bureaucrat1);
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