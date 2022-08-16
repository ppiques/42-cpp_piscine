/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   robotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:30:48 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 15:30:48 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <iostream>
#include <cstdlib>
#include "form.hpp"
#include "bureaucrat.hpp"

class RobotomyRequestForm : public Form
{
	public :

	RobotomyRequestForm();
	RobotomyRequestForm(std::string target);
	RobotomyRequestForm(const RobotomyRequestForm &cpy);
	~RobotomyRequestForm();

	RobotomyRequestForm &operator=(const RobotomyRequestForm &rhs);

	std::string	getTarget() const;

	virtual void	execute(const Bureaucrat &executor) const;

	private :

	std::string	_target;
	int const	_signGrade;
	int const	_execGrade;
};

#endif