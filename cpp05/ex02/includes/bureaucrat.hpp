/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:33:33 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 13:33:33 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <cstdlib>

class Form;

class Bureaucrat
{
	public :

	Bureaucrat();
	Bureaucrat(std::string name, int grade);
	Bureaucrat(const Bureaucrat &cpy);
	~Bureaucrat();

	Bureaucrat &operator=(const Bureaucrat &rhs);

	std::string getName() const;
	int	getGrade() const;

	void	IncrementGrade(void);
	void	DecrementGrade(void);

	bool	signForm(Form &form);

	bool	executeForm(Form const &form);

	private :

	std::string const 	_name;
	int					_grade;

	class GradeTooHighException : public std::exception
	{
		public :
				virtual const char *what() const throw()
				{
					return ("Bureaucrat grade is too high !");
				}
	};

	class GradeTooLowException : public std::exception
	{
		public :
				virtual const char *what() const throw()
				{
					return ("Bureaucrat grade is too low !");
				}
	};
};

std::ostream &operator<<(std::ostream &ostr, Bureaucrat const &Bureaucrat);

#endif