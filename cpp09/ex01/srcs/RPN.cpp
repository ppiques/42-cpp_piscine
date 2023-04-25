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

void RPN::operation()
{	
	std::istringstream	iss(_input);
	std::string			sign;
	int					a;
	int					b;
	int					value;

	if (_input.find_first_not_of("0123456789+-*/ ") != std::string::npos)
	{
		std::cout << "Error: wrong input" << std::endl;
		return;
	}
	while (iss >> sign) 
	{
		if (sign == "+") 
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
			_stack.push(a + b);
		} 
		else if (sign == "-") 
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
			_stack.push(a - b);
		} 
		else if (sign == "*") 
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
			_stack.push(a * b);
		} 
		else if (sign == "/") 
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
			_stack.push(value);
		}
	}
	std::cout << _stack.top() << std::endl;
	return;
}
