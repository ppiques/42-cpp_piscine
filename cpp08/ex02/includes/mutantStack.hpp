/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 14:04:44 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/25 14:04:44 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <stack>
#include <iostream>

template<typename T>
class MutantStack : public std::stack<T>
{
	public :

	MutantStack<T>()
	{
		return;
	}

	MutantStack<T>(const MutantStack &cpy)
	{
		(*this) = cpy;
		return;
	}

	~MutantStack<T>()
	{
		return;
	}

	MutantStack	&operator=(const MutantStack &rhs);
	
	typedef typename std::stack<T>::container_type::iterator iterator;

	iterator	begin(void)
	{
		return (this->c.begin());
	}

	iterator	end(void)
	{
		return (this->c.end());
	}
};

#endif