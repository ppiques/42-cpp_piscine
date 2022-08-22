/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 14:58:14 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/22 14:58:14 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// https://isocpp.org/wiki/faq/serialization // Like the Transporter on Star Trek, it’s all about taking something complicated and turning it into a flat sequence of 1s and 0s, then taking that sequence of 1s and 0s (possibly at another place, possibly at another time) and reconstructing the original complicated “something.”

#include "serialization.hpp"

int	main(void)
{
	Data		data;
	Data		*dataPtr;
	uintptr_t	raw;

	data.dataString = "Data";
	data.dataInt = 42;
	raw = serialize(&data);
	dataPtr = deserialize(raw);
	std::cout << "dataString : " << dataPtr->dataString << std::endl;
	std::cout << "dataInt : " << dataPtr->dataInt << std::endl;

	return (0);
}