/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/23 12:02:33 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/23 12:02:33 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <cstdlib>

template<typename T>
class Array
{
	public :

	Array<T>(void) : _size(0), _array(NULL)
	{
		return;
	}

	Array<T>(unsigned int n) : _size(n)
	{
		if (n <= 0)
		{
			this->_array = NULL;
			throw std::range_error("Range Error");
			return;
		}
		this->_array = new T[n];
		for (int i = 0; i < this->_size; i++)
			this->_array[i] = 0;
		return;
	}

	Array<T>(Array<T> const &cpy)
	{
		this->_size = 0;
		(*this) = cpy;
		return;
	}

	~Array<T>(void)
	{
		if (this->_size > 0)
			delete [] this->_array;
		return;
	}

	Array<T> &operator=(Array<T> const &rhs)
	{
		if (this == &rhs)
			return (*this);
		if (this->_size > 0)
			delete [] this->_array;
		this->_size = rhs._size;
		this->_array = new T[rhs._size];
		for (int i = 0; i < rhs._size; i++)
			this->_array[i] = rhs._array[i];
		return (*this);
	}

	T	&operator[](int const index) const
	{
		if (index < 0 || index > this->_size || index == this->_size)
			throw std::overflow_error("Overflow Error");
		return (this->_array[index]);
	}

	int	size(void) const
	{
		return (this->_size);
	}

	private :

	int	_size;
	T *_array;
};

#endif