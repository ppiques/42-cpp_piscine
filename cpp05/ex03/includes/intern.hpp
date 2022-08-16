/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 16:20:31 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 16:20:31 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include <iostream>
#include "robotomyRequestForm.hpp"
#include "shrubberyCreationForm.hpp"
#include "presidentialPardonForm.hpp"

class Intern
{
	public :

	Intern();
	Intern(const Intern &cpy);
	virtual ~Intern();

	Intern &operator=(const Intern &rhs);

	Form *makeForm(std::string formName, std::string formTarget);
	
	private :

	typedef struct s_formIntern
	{
		std::string	formName;
		Form	*formType;
	}				t_formIntern;
};

#endif