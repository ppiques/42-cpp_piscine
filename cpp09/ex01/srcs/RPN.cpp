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

int RPN::operation()
{	
	std::istringstream	iss(_input);
	std::string			token;

	while (iss >> token) 
	{
		if (token == "+") 
		{
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			_stack.push(a + b);
		} 
		else if (token == "-") 
		{
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			_stack.push(a - b);
		} 
		else if (token == "*") 
		{
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			_stack.push(a * b);
		} 
		else if (token == "/") 
		{
			int b = _stack.top();
			_stack.pop();
			int a = _stack.top();
			_stack.pop();
			if (b == 0) 
				{
					std::cerr << "Error : cannot divide by 0" << std::endl;
					return -1;
				}
			_stack.push(a / b);
		} 
		else 
		{
			int value;
			std::istringstream(token) >> value;
			_stack.push(value);
		}
	}
	return _stack.top();
}