/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook_class.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 14:48:48 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/19 14:48:48 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP
# include "contact_class.hpp"

class Phonebook
{
	public :

	Phonebook(void);
	~Phonebook(void);

	static int	get_nb_inst(void);
	Contact	*get_user(int i);
	static Contact users[8];

	private :

	static int	_nb_inst;
};

#endif