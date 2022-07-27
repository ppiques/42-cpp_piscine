/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:24:27 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/27 10:24:27 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLASSREPLACER_H
# define CLASSREPLACER_H

#include <iostream>
#include <fstream>
#include <sstream>

class Replacer
{
	public :

	Replacer();
	~Replacer();

	int		get_filename(std::string filename);
	int 	get_s1(std::string s1);
	int 	get_s2(std::string s2);
	int		new_file();
	void	replace_file(std::string filename, std::string s1, std::string s2);
	
	private :

	std::string _filename;
	std::string _s1;
	std::string _s2;
	std::string _output_filename;
};

#endif