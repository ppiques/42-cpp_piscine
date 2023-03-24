/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:42:14 by ppiques           #+#    #+#             */
/*   Updated: 2023/03/24 14:42:14 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <sstream>
#include <iostream>
#include <cstring>

class RPN 
{
	public:
		RPN();
		RPN(const std::string input);
		RPN(const RPN &cpy);
		~RPN();

		RPN &operator=(const RPN &rhs);

		int operation();

	private:
		std::string 	_input;
		std::stack<int>	_stack;
};

#endif