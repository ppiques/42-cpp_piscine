/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:37:50 by ppiques           #+#    #+#             */
/*   Updated: 2023/04/16 15:37:50 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <fstream>
# include <iostream>
# include <map>
# include <cstdlib>
# include <sstream>
# include <iomanip>
# include <ctime>
# include <cstring>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &cpy);
		~BitcoinExchange();

		BitcoinExchange &operator=(const BitcoinExchange &rhs);

		int 	parseDatabase();
		int 	parseInput(const char *file_path);
		void	printOutput();
	
	private:
		std::ifstream _csv_file;
		std::ifstream _input_file;

		std::multimap<std::string, float> _input;
		std::map<std::string, float> _database;

		bool	_checkDateFormat(const std::string &date);
		float 	_calculateValue(float amount, const std::string &date);

};

#endif