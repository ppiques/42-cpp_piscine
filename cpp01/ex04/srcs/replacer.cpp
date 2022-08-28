/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replacer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 10:32:46 by ppiques           #+#    #+#             */
/*   Updated: 2022/07/27 10:32:46 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "replacer.hpp"

Replacer::Replacer()
{
	return;
}

Replacer::~Replacer()
{
	return;
}

int		Replacer::get_filename(std::string filename)
{
	if (filename == "")
	{
		std::cout << "Error : empty filename." << std::endl;
		return (0);
	}
	this->_filename = filename;
	return (1);
}

int		Replacer::get_s1(std::string s1)
{
	if (s1 == "")
	{
		std::cout << "Error : empty s1" << std::endl;
		return (0);
	}
	this->_s1 = s1;
	return (1);
}

int		Replacer::get_s2(std::string s2)
{
	if (s2 == "")
	{
		std::cout << "Error : empty s2" << std::endl;
		return (0);
	}
	this->_s2 = s2;
	return (1);
}


// ostringstream: https://cplusplus.com/reference/sstream/ostringstream/ -> allows operation on strings
int 	Replacer::new_file()
{
	size_t				i;
	std::ostringstream	output;

	i = 0;
	this->_output_filename = this->_filename;
	output.str(this->_output_filename);
	this->_output_filename = output.str();
	this->_output_filename += ".replace";
	return (0);
}

// ifstream: https://cplusplus.com/reference/fstream/ifstream/ -> operate on files, input
// ofstream: https://cplusplus.com/reference/fstream/ofstream/ -> operate on files, output
// c_str: https://cplusplus.com/reference/string/string/c_str/ -> returns a pointer to an array
void	Replacer::replace_file(std::string filename, std::string s1, std::string s2)
{
	size_t		s1_len;
	std::string	line;

	if (this->get_filename(filename) == 0)
		return ;
	if (this->get_s1(s1) == 0)
		return;
	if (this->get_s2(s2) == 0)
		return;
	s1_len = s1.length();
	this->new_file();
	std::ifstream	infile(this->_filename.c_str());
	std::ofstream	outfile(this->_output_filename.c_str());
	while (std::getline(infile, line, '\n'))
	{
		for (size_t pos = 0; pos < line.length(); pos++)
		{
			if (line.compare(pos, s1_len, _s1) == 0)
			{
				line.erase(pos, s1_len);
				line.insert(pos, _s2);
				pos += s1_len;
			}
		}
		outfile << line << std::endl;
	}
	infile.close();
	outfile.close();
}
