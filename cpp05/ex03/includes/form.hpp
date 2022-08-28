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

class Bureaucrat;

class Form
{
	public :

	Form();
	Form(std::string name, int signGrade, int execGrade);
	Form(const Form &cpy);
	virtual ~Form();

	Form &operator=(const Form &rhs);

	std::string 		getName() const;
	bool				getSigned() const;
	int					getExecGrade() const;
	int					getSignedGrade() const;
	virtual	std::string	getTarget() const = 0;

	void		setSigned(bool isSigned);

	void		checkGrade() const;
	void		checkIfExec(const Bureaucrat &executor) const;
	void		beSigned(Bureaucrat const &Bureaucrat);

	virtual void	execute(Bureaucrat const &executor) const = 0;

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

	class CannotExecute : public std::exception
	{
		public :
			virtual const char *what() const throw()
			{
				return ("The form cannot be executed.");
			}
	};

	private :

	std::string const	_name;
	bool				_signed;
	int const			_execGrade;
	int const			_signGrade;

};

std::ostream	&operator<<(std::ostream &ostr, Form const &form);

#endif