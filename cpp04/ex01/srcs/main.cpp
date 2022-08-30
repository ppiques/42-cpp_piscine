/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 14:16:54 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/11 14:16:54 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* https://www.delftstack.com/fr/howto/cpp/deep-copy-in-cpp/ 
** Les copies profondes ont leurs propres membres alloués sur 
** la mémoire dynamique et ne le partage pas avec l'objet d'origine.
*/

#include "animal.hpp"
#include "wrongAnimal.hpp"
#include "cat.hpp"
#include "dog.hpp"
#include "wrongCat.hpp"
#include "brain.hpp"

int main()
{
	const Animal	*j = new Dog();
	const Animal	*i = new Cat();

	delete j;
	delete i;
	
	const Animal	*animals[10];
	Brain	*brain;

	std::cout << std::endl;

	for (int k = 0; k < 10; k++)
	{
		if (k <= 4)
			animals[k] = new Dog();
		else
			animals[k] = new Cat();
	}

	std::cout << std::endl;

	for (int k = 0; k < 10; k++)
		std::cout << k << " : " << animals[k]->getType() << std::endl;

	std::cout << std::endl;

	for (int k = 0; k < 10; k++)
	{
		if (k <= 4)
		{
			brain = animals[k]->getBrain();
			brain->ideas[99] = "I'm happy !";
			std::cout << animals[k]->getType() << " thinks : " << brain->ideas[99] << std::endl;
		}
		else
		{
			brain = animals[k]->getBrain();
			brain->ideas[0] = "I'm hungry...";
			std::cout << animals[k]->getType() << " thinks : " << brain->ideas[0] << std::endl;
		}
	}
	
	std::cout << std::endl;

	for (int k = 0; k < 10; k++)
		delete animals[k];

	std::cout << std::endl;

	std::cout << "----DEEP COPIES TEST----" << std::endl;

	std::cout << std::endl;

	Cat	cat;
	Cat	cat2(cat);

	std::cout << "CatRef : " << cat.getRef() << std::endl;
	std::cout << "Cat2Ref : " << cat2.getRef() << std::endl;

	std::cout << std::endl;
	
	return (0);
}