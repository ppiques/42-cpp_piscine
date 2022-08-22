/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   truetype.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/22 15:16:40 by ppiques           #+#    #+#             */
/*   Updated: 2022/08/22 15:16:40 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRUETYPE_HPP
# define TRUETYPE_HPP

#include "classA.hpp"
#include "classB.hpp"
#include "classC.hpp"
#include "base.hpp"
#include <iostream>
#include <cstdlib>

Base	*generate(void);
void	identify(Base *p);
void	identify(Base &p);

#endif