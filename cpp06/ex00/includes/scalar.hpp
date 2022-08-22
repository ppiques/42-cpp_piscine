/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scalar.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 13:27:51 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/22 13:27:51 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALAR_HPP
# define SCALAR_HPP

#include <iostream>
#include <stdlib.h>
#include <limits>

class Scalar
{
	public :

	Scalar();
	Scalar(char const *value);
	Scalar(const Scalar &cpy);
	virtual ~Scalar();

	Scalar &operator=(const Scalar &rhs);

	void	setInt(char const *value);
	void	setChar(char const *value);
	void	setFloat(char const *value);
	void	setDouble(char const *value);
	bool	setEdgeCases(std::string const &value);

	bool	isDigit(char c) const;
	int		scalarStrlen(char *str) const;
	
	void	printInt(void) const;
	void	printChar(void) const;
	void	printFloat(void) const;
	void	printDouble(void) const;

	void	findDot(void);
	void	errorHandler(char const *value);

	class ScalarError : public std::exception
	{
		public :

		virtual const char *what() const throw()
		{
			return ("Error : Input is not of type char | int | float | double");
		}
	};

	private :

	char const	*_srcValue;
	bool		_dot;
	bool		_notOnlyZero;
	bool		_dotFirst;
	bool		_error;
	bool		_errorValueChar;
	bool		_errorValueInt;
	int			_valueLen;
	std::string	_floatEdgeCases;
	std::string	_doubleEdgeCases;
	int			_valueInt;
	char		_valueChar;
	float		_valueFloat;
	double		_valueDouble;
};

#endif