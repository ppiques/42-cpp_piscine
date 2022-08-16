/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 14:16:02 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 14:16:02 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <cstdlib>

class Bureaucrat;

class Form
{
	public :

	Form();
	Form(std::string name, int execGrade, int signGrade);
	Form(const Form &cpy);
	~Form();

	Form &operator=(const Form &rhs);

	std::string getName() const;
	bool		getSigned() const;
	int			getExecGrade() const;
	int			getSignedGrade() const;

	void		setSigned(bool isSigned);

	void		checkGrade() const;
	void		beSigned(Bureaucrat const &Bureaucrat);

	class GradeTooHighException : public std::exception
	{
		public :
				virtual const char *what() const throw()
				{
					return ("Grade required is too high !");
				}
	};

	class GradeTooLowException : public std::exception
	{
		public :
				virtual const char *what() const throw()
				{
					return ("Grade required is too low !");
				}
	};

	private :

	std::string const	_name;
	bool				_signed;
	int const			_signGrade;
	int const			_execGrade;

};

std::ostream	&operator<<(std::ostream &ostr, Form const &form);

#endif