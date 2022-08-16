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
#include "form.hpp"

Bureaucrat::Bureaucrat() : _name("Undefined")
{
	this->_grade = rand() % 150 + 1; // https://cplusplus.com/reference/cstdlib/rand/
	return;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	this->GradeTooHighException(grade);
	this->GradeTooLowException(grade);
	this->_grade = grade;
	return;
}

Bureaucrat::Bureaucrat(const Bureaucrat &cpy) : _name(cpy.getName())
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

bool	Bureaucrat::GradeTooHighException(int grade)
{
	try
	{
		if (grade < 1)
			throw std::exception();
	}
	catch (const std::exception &e)
	{
		std::cout << "Bureaucrat grade is too high" << std::endl;
		return (true);
	}
	return (false);
}

bool	Bureaucrat::GradeTooLowException(int grade)
{
	try
	{
		if (grade > 150)
			throw std::exception();
	}
	catch (const std::exception &e)
	{
		std::cerr << "Bureaucrat grade is too low" << std::endl; 
		return (true);
	}
	return (false);
}

void	Bureaucrat::IncrementGrade()
{
	if (this->GradeTooHighException(this->getGrade() - 1) == false)
	{
		std::cout << "Incrementing grade" << std::endl;
		this->_grade--;
	}
}

void	Bureaucrat::DecrementGrade()
{
	if (this->GradeTooLowException(this->getGrade() + 1) == false)
	{
		std::cout << "Decrementing grade" << std::endl;
		this->_grade++;
	}
}

bool	Bureaucrat::signForm(Form form)
{
	form.beSigned(*this);
	if (form.getSigned() == true)
	{
		std::cout << this->getName() << " signed " << form.getName() << std::endl;
		return (true);
	}
	else
	{
		std::cout << this->getName() << " couldn't sign " << form.getName() << " because ";
		throw Form::GradeTooHighException();
		return (false);
	}
}

bool	Bureaucrat::executeForm(Form const &form)
{
	if (form.getSigned() == true && this->getGrade() < form.getExecGrade())
	{
		std::cout << this->getName() << " has executed " << form.getName() << std::endl;
		return (true);
	}
	else
		std::cout << this->getName() << " was unable to execute " << form.getName() << std::endl;
	return (false);
}