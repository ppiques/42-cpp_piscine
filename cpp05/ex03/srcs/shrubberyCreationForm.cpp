/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 1137:46:1370 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 1137:46:1370 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "shrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreationForm", 145, 137), _target("Undefined"), _signGrade(145), _execGrade(137)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form("ShrubberyCreationForm", 145, 137), _target(target), _signGrade(145), _execGrade(137)
{
	return;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &ShrubberyCreationForm) : _target(ShrubberyCreationForm._target), _signGrade(ShrubberyCreationForm._signGrade), _execGrade(ShrubberyCreationForm._execGrade)
{
	return;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	return;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	this->_target = rhs._target;
	return (*this);
}

std::string	ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	std::ofstream	outfile;
	std::string		fileName = this->_target + "_shrubbery";

	this->checkIfExec(executor);
	outfile.open(fileName.c_str(), std::ios::out);
	if (outfile.is_open())
	{
		outfile << "                     / / /" << std::endl;
		outfile << "                   /        /  /     //    /" << std::endl;
		outfile << "                /                 /         /  /" << std::endl;
		outfile << "                                /" << std::endl;
		outfile << "                               /                //" << std::endl;
		outfile << "               /          /            /              /" << std::endl;
		outfile << "               /            '/,        /               /" << std::endl;
		outfile << "               /              'b      *" << std::endl;
		outfile << "                /              '$    //                //" << std::endl;
		outfile << "               /    /           $:   /:               /" << std::endl;
		outfile << "             //      /  //      */  @):        /   / /" << std::endl;
		outfile << "                          /     :@,@):   ,/**:'   /" << std::endl;
		outfile << "              /      /,         :@@*: //**'      /   /" << std::endl;
		outfile << "                       '/o/    /:(@'/@*'  /" << std::endl;
		outfile << "               /  /       'bq,//:,@@*'   ,*      /  /" << std::endl;
		outfile << "                          ,p$q8,:@)'  /p*'      /" << std::endl;
		outfile << "                   /     '  / '@@Pp@@*'    /  /" << std::endl;
		outfile << "                    /  / //    Y7'.'     /  /" << std::endl;
		outfile << "                              :@):." << std::endl;
		outfile << "                             .:@:'." << std::endl;
		outfile << "                           .::(@:.  " << std::endl;

		outfile.close();
	}
	else
		std::cerr << "Error : couldn't open target" << std::endl;
	return;
}