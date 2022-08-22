/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:27:17 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/22 15:27:17 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "truetype.hpp"

int	main() {

	Base *base;

	std::cout << "------Ptr Tests------" << std::endl;
	base = generate();
	identify(base);
	delete base;
	base = generate();
	identify(base);
	delete base;
	base = generate();
	identify(base);
	delete base;
	base = generate();
	identify(base);
	delete base;
	base = generate();
	identify(base);
	delete base;

	std::cout << "------Ref Tests------" << std::endl;
	base = generate();
	identify(*base);
	delete base;
	base = generate();
	identify(*base);
	delete base;
	base = generate();
	identify(*base);
	delete base;
	base = generate();
	identify(*base);
	delete base;
	base = generate();
	identify(*base);
	delete base;
}