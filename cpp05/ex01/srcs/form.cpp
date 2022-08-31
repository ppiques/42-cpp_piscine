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

Form::Form() : _name("Undefined"), _signGrade(rand() % 150 + 1), _execGrade(rand() % 150 + 1)
{
	this->_signed = false;
	return;
}

Form::Form(std::string name, int signGrade, int execGrade) : _name(name), _signGrade(signGrade), _execGrade(execGrade)
{
	if (signGrade < 1 || execGrade < 1)
		throw GradeTooHighException();
	else if (signGrade > 150 || execGrade > 150)
		throw GradeTooLowException();
	this->_signed = false;
	return;
}

Form::Form(const Form &Form) : _name(Form.getName()), _signGrade(Form.getSignedGrade()), _execGrade(Form.getExecGrade())
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
	ostr << "The " << Form.getName() << " form requires grade " << Form.getSignedGrade() << " to be signed and grade " << Form.getExecGrade() << " to be executed.";
	if (Form.getSigned() == true)
		ostr << " It has been signed.";
	else
		ostr << " It has not been signed.";
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

void	Form::beSigned(Bureaucrat const &Bureaucrat)
{
	if (Bureaucrat.getGrade() <= this->getSignedGrade())
		this->setSigned(true);
	return;
}