/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:15:56 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 14:15:56 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "form.hpp"
#include "bureaucrat.hpp"

Form::Form() : _name("Undefined"), _execGrade(rand() % 150 + 1), _signGrade(rand() % 150 + 1)
{
	this->_signed = false;
	return;
}

Form::Form(std::string name, int execGrade, int signGrade) : _name(name), _execGrade(execGrade), _signGrade(signGrade)
{
	this->_signed = false;
	this->checkGrade();
	return;
}

Form::Form(const Form &Form) : _name(Form.getName()), _execGrade(Form.getExecGrade()), _signGrade(Form.getSignedGrade())
{
	(*this) = Form;
	return;
}

Form::~Form()
{
	return;
}

Form	&Form::operator=(const Form &rhs)
{
	this->setSigned(rhs._signed);
	return (*this);
}

std::ostream &operator<<(std::ostream &ostr, Form const &Form)
{
	ostr << "The " << Form.getName() << " form requires grade " << Form.getSignedGrade() << " to be signed and grade " << Form.getExecGrade() << " to be executed." << std::endl;
	return (ostr);
}

std::string Form::getName() const
{
	return (this->_name);
}

bool		Form::getSigned() const
{
	return (this->_signed);
}

int			Form::getExecGrade() const
{
	return (this->_execGrade);
}

int			Form::getSignedGrade() const
{
	return (this->_signGrade);
}

void		Form::setSigned(bool isSigned)
{
		this->_signed = isSigned;
}

void	Form::checkGrade() const
{
	try
	{
		if (this->_execGrade < 1 ||this->_signGrade < 1)
			throw Form::GradeTooHighException();
		if (this->_execGrade > 150 ||this->_signGrade > 150)
			throw Form::GradeTooLowException();
	}
	catch(const std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
}

void	Form::checkIfExec(const Bureaucrat &executor) const
{
	if (this->_signed == false || executor.getGrade() > this->_execGrade)
		throw Form::CannotExecute();
}

void	Form::beSigned(Bureaucrat const &Bureaucrat)
{
	if (Bureaucrat.getGrade() < this->getSignedGrade())
		this->_signed = true;
	else
	{
		this->_signed = false;
	}
}