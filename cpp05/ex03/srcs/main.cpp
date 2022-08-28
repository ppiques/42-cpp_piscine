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
#include "intern.hpp"

int main()
{
	srand (time(NULL));
	Intern someRandomIntern;
	Bureaucrat Boss("Boss", 1);
	Form* rrf;

	rrf = someRandomIntern.makeForm("robotomy request form", "Boss");
	if (rrf != NULL)
	{
		rrf->beSigned(Boss);
		rrf->execute(Boss);
		delete rrf;
	}

	std::cout << std::endl;

	rrf = someRandomIntern.makeForm("shrubbery creation form", "Boss");
	if (rrf != NULL)
	{
		rrf->beSigned(Boss);
		rrf->execute(Boss);
		delete rrf;
	}

	std::cout << std::endl;

	rrf = someRandomIntern.makeForm("presidential pardon form", "Boss");
	if (rrf != NULL)
	{
		rrf->beSigned(Boss);
		rrf->execute(Boss);
		delete rrf;
	}

	std::cout << std::endl;

	rrf = someRandomIntern.makeForm("Formol", "Boss");

	return (0);
}