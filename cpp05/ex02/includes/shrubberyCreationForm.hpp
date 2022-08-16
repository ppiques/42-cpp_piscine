/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:32:13 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 15:32:13 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <iostream>
#include <fstream>
#include "form.hpp"
#include "bureaucrat.hpp"

class ShrubberyCreationForm : public Form
{
	public :

	ShrubberyCreationForm();
	ShrubberyCreationForm(std::string target);
	ShrubberyCreationForm(const ShrubberyCreationForm &cpy);
	~ShrubberyCreationForm();

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &rhs);

	std::string	getTarget() const;

	virtual void	execute(const Bureaucrat &executor) const;

	private :

	std::string	_target;
	int const	_signGrade;
	int const	_execGrade;
};

#endif