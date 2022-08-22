/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:58:02 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/22 14:58:02 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
# define SERIALIZATION_HPP

#include <iostream>
#include <stdint.h>

typedef struct sData
{
	int			dataInt;
	std::string	dataString;
}				Data;

uintptr_t serialize(Data *ptr);

Data 	*deserialize(uintptr_t raw);

#endif