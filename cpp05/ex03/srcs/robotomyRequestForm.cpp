/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   robotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 145:41:07 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 145:41:07 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "robotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequestForm", 45, 72), _target("Undefined"), _signGrade(72), _execGrade(45)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : Form("RobotomyRequestForm", 45, 72), _target(target), _signGrade(72), _execGrade(45)
{
	return;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &RobotomyRequestForm) : _target(RobotomyRequestForm._target), _signGrade(RobotomyRequestForm._signGrade), _execGrade(RobotomyRequestForm._execGrade)
{
	return;
}

RobotomyRequestForm::~RobotomyRequestForm()
{
	return;
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	this->_target = rhs._target;
	return (*this);
}

std::string	RobotomyRequestForm::getTarget() const
{
	return (this->_target);
}

void	RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	int	i;

	i = rand() % 1;
	this->checkIfExec(executor);
	std::cout << "*drill noises...*" << std::endl;
	if (i == 0)
		std::cout << executor.getName() << " has successfully been turned into a servitor ! Praise the Omnissiah !" << std::endl;
	else
		std::cout << executor.getName() << " perished during the operation... the Machine Spirit has forsaken us this day." << std::endl;
}