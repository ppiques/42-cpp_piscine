/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:27:13 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/19 14:27:13 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>
# include <iomanip>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "../includes/contact_class.hpp"
# include "../includes/phonebook_class.hpp"


// Phonebook art taken from rchallie
// This function shows at startup to show the user the command list.
static void	startup_message(void)
{
	std::cout << std::endl;
	std::cout << "\033[1;93m██████╗ ██╗  ██╗ ██████╗ ███╗   ██╗███████╗██████╗  ██████╗  ██████╗ ██╗  ██╗\033[0m" << std::endl;
	std::cout << "\033[1;93m██╔══██╗██║  ██║██╔═══██╗████╗  ██║██╔════╝██╔══██╗██╔═══██╗██╔═══██╗██║ ██╔╝\033[0m" << std::endl;
	std::cout << "\033[1;93m██████╔╝███████║██║   ██║██╔██╗ ██║█████╗  ██████╔╝██║   ██║██║   ██║█████╔╝ \033[0m" << std::endl;
	std::cout << "\033[1;93m██╔═══╝ ██╔══██║██║   ██║██║╚██╗██║██╔══╝  ██╔══██╗██║   ██║██║   ██║██╔═██╗ \033[0m" << std::endl;
	std::cout << "\033[1;93m██║     ██║  ██║╚██████╔╝██║ ╚████║███████╗██████╔╝╚██████╔╝╚██████╔╝██║  ██╗\033[0m" << std::endl;
	std::cout << "\033[1;93m╚═╝     ╚═╝  ╚═╝ ╚═════╝ ╚═╝  ╚═══╝╚══════╝╚═════╝  ╚═════╝  ╚═════╝ ╚═╝  ╚═╝\033[0m" << std::endl;
	std::cout << std::endl;
	std::cout << "Hello ! Please choose an option below :" << std::endl;
	std::cout << std::endl;
	std::cout <<"\033[1;34mADD\033[0m - Add a new person to the phonebook." << std::endl;
	std::cout <<"\033[0;96mSEARCH\033[0m - Search for someone in the phonebook." << std::endl;
	std::cout <<"\033[0;31mEXIT\033[0m - Exit the program." << std::endl;

	return ;
}

static void	command_list(void)
{
	std::cout << std::endl;
	std::cout << "Please choose an option below :" << std::endl;
	std::cout << std::endl;
	std::cout <<"\033[1;34mADD\033[0m - Add a new person to the phonebook." << std::endl;
	std::cout <<"\033[0;96mSEARCH\033[0m - Search for someone in the phonebook." << std::endl;
	std::cout <<"\033[0;31mEXIT\033[0m - Exit the program." << std::endl;

	return ;
}

static void	search(Contact *contact, int total_inst)
{
	int	i;
	std::string	input;

	i = 0;
	if (total_inst == 0)
	{
		std::cout << std::endl;
		std::cout << "No user registered yet. Use \033[1;34mADD\033[0m to register a new user." << std::endl;
		command_list();
		return ;
	}
	std::cout << std::setfill (' ') << std::setw (10);
	std::cout << "Index" << "|";
	std::cout << std::setfill (' ') << std::setw (10);
	std::cout << "First name" << "|";
	std::cout << std::setfill (' ') << std::setw (10);
	std::cout << "Last name" << "|";
	std::cout << std::setfill (' ') << std::setw (10);
	std::cout << "Nickname" << "|" << std::endl;
	if (total_inst >= 8)
		total_inst = 8;
	while (i < total_inst)
	{
		contact[i].user_list();
		i++;
	}
	std::cout << "Please select an index you wish to display the contact details of" << std::endl;
	std::getline(std::cin, input);
	if (input.length() == 1 && (input[0] >= '0' && input[0] <= ('0' + total_inst - 1)))
	{
		contact[input[0] - '0'].search_user();
		command_list();
	}
	else
	{
		system("clear");
		command_list();
	}
	return ;
}

int	main()
{
	std::string	input;
	Phonebook	phonebook;
	Contact		*p_contact = NULL;
	int			i;
	int			j;

	i = 0;
	j = 0;
	startup_message();
	while (std::getline(std::cin, input))
	{
		if ((input.compare("EXIT")) == 0)
			return (0);
		if (i >= 8)
		{
			j = i % 8;
			std::cout << "Warning : Limit of 8 users reached. Next ADD command will remove user at index " << j << std::endl;
			std::cout << std::endl;
		}
		if (input.compare("ADD") == 0)
		{
			p_contact = phonebook.get_user(i % 8);
			(*p_contact).add(j);
			command_list();
			i++;
			j = i % 8;
		}
		else if (input.compare("SEARCH") == 0)
			search(Phonebook::users, i);
		else
			command_list();
	}
	return (0);
}