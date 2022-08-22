/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truetype.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:18:46 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/22 15:18:46 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "truetype.hpp"

Base *generate(void)
{
	int	random;

	random = rand() % 3 + 1;
	if (random == 1)
		return (new A());
	else if (random == 2)
		return (new B());
	else
		return (new C());
}

void	identify(Base *p) // We make use of the fact that a dynamic cast can compile, then fail during runtime and return NULL
{
	A *aPtr = NULL;
	B *bPtr = NULL;
	C *cPtr = NULL;

	aPtr = dynamic_cast<A*>(p);
	if (aPtr != NULL)
		std::cout << "A" << std::endl;
	bPtr = dynamic_cast<B*>(p);
	if (bPtr != NULL)
		std::cout << "B" << std::endl;
	cPtr = dynamic_cast<C*>(p);
	if (cPtr != NULL)
		std::cout << "C" << std::endl;
}

void	identify(Base &p)
{
	try 
	{
		A &aRef = dynamic_cast<A&>(p);
		(void)aRef; // void cast to allow compilation and avoid unused variable error
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e)
	{
		;
	}

	try 
	{
		B &bRef = dynamic_cast<B&>(p);
		(void)bRef;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e)
	{
		;
	}

	try 
	{
		C &cRef = dynamic_cast<C&>(p);
		(void)cRef;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e)
	{
		;
	}
}