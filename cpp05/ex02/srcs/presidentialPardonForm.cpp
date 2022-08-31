/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:33:44 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 15:33:44 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "presidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardonForm", 25, 5), _target("Undefined"), _signGrade(25), _execGrade(5)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : Form("PresidentialPardonForm", 25, 5), _target(target), _signGrade(25), _execGrade(5)
{
	return;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &PresidentialPardonForm) : _target(PresidentialPardonForm._target), _signGrade(PresidentialPardonForm._signGrade), _execGrade(PresidentialPardonForm._execGrade)
{
	return;
}

PresidentialPardonForm::~PresidentialPardonForm()
{
	return;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	this->_target = rhs._target;
	return (*this);
}

std::string	PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void	PresidentialPardonForm::execute(const Bureaucrat &executor) const
{
	this->checkIfExec(executor);
	std::cout << this->getTarget() << " was forgiven by Zaphod Beeblebrox" << std::endl;
}