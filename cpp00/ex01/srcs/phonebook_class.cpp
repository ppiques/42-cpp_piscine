/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_class.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:48:00 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/19 14:48:00 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/phonebook_class.hpp"
# include "../includes/contact_class.hpp"
# include <iostream>
# include <iomanip>
# include <stdio.h>
# include <string.h>

int	Phonebook::_nb_inst = 0;
Contact Phonebook::users[8];

Phonebook::Phonebook(void)
{
	Phonebook::_nb_inst += 1;
	return ;
}

Phonebook::~Phonebook(void)
{
	Phonebook::_nb_inst -= 1;
	return ;
}

int	Phonebook::get_nb_inst(void)
{
	return (Phonebook::_nb_inst);
}

Contact *Phonebook::get_user(int i)
{
	return (&(this->users[i]));
}