/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:20:26 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 16:20:26 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "intern.hpp"

Intern::Intern()
{
	return;
}

Intern::Intern(const Intern &cpy)
{
	(*this) = cpy;
	return;
}

Intern::~Intern()
{
	return;
}

Intern	&Intern::operator=(const Intern &rhs)
{
	(void)rhs;
	return (*this);
}

Form	*Intern::makeForm(std::string formName, std::string formTarget)
{
	Form *formReturn = NULL;
	t_formIntern formList[3] =
	{
		{"Robotomy Request Form", new RobotomyRequestForm(formTarget)},
		{"Shrubbery Creation Form", new ShrubberyCreationForm(formTarget)},
		{"Presidential Pardon Form", new PresidentialPardonForm(formTarget)}
	};

	for (int i = 0; i < 3 ; i++)
	{
		if (formList[i].formName == formName)
		{
			formReturn = formList[i].formType;
			std::cout << "Intern creates " << formList[i].formName << std::endl;
		}
	}

	if (formReturn == NULL)
		std::cout << "Intern couldn't create the following form : " << formName << std::endl;

	for (int i = 0; i < 3; i++)
	{
		if (formReturn != formList[i].formType)
			delete formList[i].formType;
	}

	return (formReturn);
}