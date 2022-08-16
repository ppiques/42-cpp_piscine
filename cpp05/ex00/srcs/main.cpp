/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 13:53:17 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/16 13:53:17 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bureaucrat.hpp"

int	main()
{
	Bureaucrat	Bureaucrat1("Boss", 1);
	Bureaucrat	Bureaucrat2("Minion", 150);
	Bureaucrat	Bureaucrat3("toolow", 0);
	Bureaucrat	Bureaucrat4("toohigh", 151);
	Bureaucrat	Bureaucrat5;
	Bureaucrat	Bureaucrat6;

	std::cout << std::endl;

	Bureaucrat1.IncrementGrade();
	std::cout << Bureaucrat1.getGrade() << std::endl;
	Bureaucrat2.DecrementGrade();
	std::cout << Bureaucrat2.getGrade() << std::endl;

	std::cout << std::endl;

	Bureaucrat1.DecrementGrade();
	std::cout << Bureaucrat1.getGrade() << std::endl;
	Bureaucrat2.IncrementGrade();
	std::cout << Bureaucrat2.getGrade() << std::endl;

	std::cout << std::endl;

	std::cout << Bureaucrat1;
	std::cout << Bureaucrat2;
	std::cout << Bureaucrat5;
	std::cout << Bureaucrat6;

	return (0);
}