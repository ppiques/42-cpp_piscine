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

	bool	GradeTooHighException(int grade);
	bool	GradeTooLowException(int grade);

	void	IncrementGrade(void);
	void	DecrementGrade(void);

	private :

	std::string const _name; // const name makes it hard to overload
	int			_grade;
};

std::ostream &operator<<(std::ostream &ostr, Bureaucrat const &Bureaucrat);

#endif