/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact_class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:48:02 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/19 14:48:02 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
# include "../includes/contact_class.hpp"
# include <iostream>
# include <iomanip>
# include <string>
# include <stdio.h>
# include <stdlib.h>

int	Contact::_nb_inst = 0;

Contact::Contact(void)
{
	Contact::_nb_inst += 1;
	return ;
}

Contact::~Contact(void)
{
	Contact::_nb_inst -= 1;
	return ;
}

// Function to add an user to the database. std::getline reads input and stores it in this(contact)->variable.
// system("clear") allows us to use shell commands, like clear.
void	Contact::add(int i)
{
	std::cout << "Please enter the following information -" << std::endl;
	std::cout << std::endl;
	Contact::index = i;
	std::cout << "First name :" << std::endl;
	std::getline(std::cin, this->first_name);
	std::cout << "Last name :" << std::endl;
	std::getline(std::cin, this->last_name);
	std::cout << "Nickname :" << std::endl;
	std::getline(std::cin, this->nickname);
	std::cout << "Phone number :" << std::endl;
	std::getline(std::cin, this->phone_number);
	while (this->phone_number.find_first_not_of("0123456789") != std::string::npos)
	{
		std::cout <<"Invalid phone number, please try again" << std::endl;
		std::getline(std::cin, this->phone_number);
	}
	std::cout << "Darkest secret :" << std::endl;
	std::getline(std::cin, this->darkest_secret);
	system("clear");

	return ;
}


// Function to show the list of currently saved users.
// setfill and setw allows us to set a set width for shown string, and decide what to fill it with if the string is not long enough.
void	Contact::user_list(void) const
{
	std::cout << std::setfill (' ') << std::setw (10);
	std::cout << this->index << "|";
	std::cout << std::setfill(' ') << std::setw (10);
	if (this->first_name.length() < 10)
		std::cout << this->first_name << "|";
	else
		std::cout << this->first_name.substr(0, 9).insert(9, ".") << "|";
	std::cout << std::setfill(' ') << std::setw (10);
	if (this->last_name.length() < 10)
		std::cout << this->last_name << "|";
	else
		std::cout << this->last_name.substr(0, 9).insert(9, ".") << "|";
	std::cout << std::setfill(' ') << std::setw (10);
	if (this->nickname.length() < 10)
		std::cout << this->nickname << "|" <<std::endl;
	else
		std::cout << this->nickname.substr(0, 9).insert(9, ".") << "|" << std::endl;

	return ;
}

void	Contact::search_user(void) const
{
	std::cout << std::endl;
	std::cout << "\033[1;93mUser information -\033[0m" << std::endl;
	std::cout << "Index : " << this->index << std::endl;
	std::cout << "First name : " << this->first_name << std::endl;
	std::cout << "Last name : " << this->last_name << std::endl;
	std::cout << "Nickname : " << this->nickname << std::endl;
	std::cout << "Phone number : " << this->phone_number << std::endl;
	std::cout << "Darkest secret : " << this->darkest_secret << std::endl;

	return ;
}
