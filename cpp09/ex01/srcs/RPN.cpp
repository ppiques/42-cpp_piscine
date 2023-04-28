/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:42:17 by ppiques           #+#    #+#             */
/*   Updated: 2023/03/24 14:42:17 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN() 
{
	return;
}

RPN::RPN(std::string input) : _input(input)
{
	return;
}

RPN::RPN(const RPN &cpy)
{
	(*this) = cpy;
	return;
}

RPN::~RPN() 
{
	return;
}

RPN &RPN::operator=(const RPN &rhs)
{
	this->_input = rhs._input;
	this->_stack = rhs._stack;
	return (*this);
}

int RPN::_checkinput()
{
	if (_input.find_first_not_of("0123456789+-*/ ") != std::string::npos)
		return (-1);

	if (_input.find("  ") != std::string::npos)
		return (-1);

	return (0);
}

void RPN::operation()
{	
	std::istringstream	iss(_input);
	std::string			sign;
	int					a;
	int					b;
	int					value;

	if (_checkinput() == -1)
	{
		std::cout << "Error" << std::endl;
		return;
	}
	while (iss >> sign) 
	{
		if (sign.at(0) != '-' && sign.length() > 1)
		{
			std::cout << "Error" << std::endl;
			return;
		}
		if (sign.find_first_of("+-*/") == 0 && sign.size() == 1)
		{
			b = _stack.top();
			_stack.pop();
			if (_stack.empty())
			{
				std::cout << "Error" << std::endl;
				return;
			}
			a = _stack.top();
			_stack.pop();
		}
		if (sign == "+") 
			_stack.push(a + b);
		else if (sign == "-") 
			_stack.push(a - b);
		else if (sign == "*") 
			_stack.push(a * b);
		else if (sign == "/") 
		{
			if (b == 0) 
				{
					std::cerr << "Error : cannot divide by 0" << std::endl;
					return;
				}
			_stack.push(a / b);
		} 
		else 
		{
			std::istringstream(sign) >> value;
			if (value > 9)
			{
				std::cerr << "Error" << std::endl;
				return;
			}
			_stack.push(value);
		}
	}
	if (_stack.size() != 1)
	{
		std::cout << "Error" << std::endl;
		return;
	}
	std::cout << _stack.top() << std::endl;
	return;
}
