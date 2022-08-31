/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:33:36 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 13:33:36 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Undefined")
{
	this->_grade = rand() % 150 + 1; // https://cplusplus.com/reference/cstdlib/rand/
	std::cout << this->getName() << ", Bureaucrat grade " << this->getGrade() << std::endl;
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy.getName()), _grade(cpy.getGrade())
{
	(*this) = cpy;
	return;
}

Bureaucrat::~Bureaucrat()
{
	return;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	this->_grade = rhs.getGrade();
	return (*this);
}

std::ostream	&operator<<(std::ostream &ostr, Bureaucrat const &Bureaucrat)
{
	ostr << Bureaucrat.getName() << ", Bureaucrat grade " << Bureaucrat.getGrade() << std::endl;
	return (ostr);
}

std::string	Bureaucrat::getName() const
{
	return (this->_name);
}

int	Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void	Bureaucrat::IncrementGrade()
{
	if (this->getGrade() - 1 < 1)
	{
		throw GradeTooHighException();
	}
	std::cout << "Incrementing grade" << std::endl;
	this->_grade--;
}

void	Bureaucrat::DecrementGrade()
{
	if (this->getGrade() + 1 > 150)
	{
		throw GradeTooLowException();
	}
	std::cout << "Decrementing grade" << std::endl;
	this->_grade++;
}