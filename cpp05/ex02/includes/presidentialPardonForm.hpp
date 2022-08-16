/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   presidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 15:27:19 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 15:27:19 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <iostream>
#include "form.hpp"
#include "bureaucrat.hpp"

class PresidentialPardonForm : public Form
{
	public :

	PresidentialPardonForm();
	PresidentialPardonForm(std::string target);
	PresidentialPardonForm(const PresidentialPardonForm &cpy);
	~PresidentialPardonForm();

	PresidentialPardonForm &operator=(const PresidentialPardonForm &rhs);

	std::string	getTarget() const;

	virtual void	execute(const Bureaucrat &executor) const;

	private :

	std::string	_target;
	int const	_signGrade;
	int const	_execGrade;
};

#endif