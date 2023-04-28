/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 15:49:50 by ppiques           #+#    #+#             */
/*   Updated: 2023/04/16 15:49:50 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange()
{
}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &cpy)
{
	(*this) = cpy;
	return;
}

BitcoinExchange::~BitcoinExchange()
{
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &rhs)
{
	this->_input = rhs._input;
	this->_database = rhs._database;
	return (*this);
}

int BitcoinExchange::parseDatabase()
{

	_csv_file.open("data.csv", std::ifstream::in);
	if (_csv_file.good())
	{
		std::string line;
		std::string	date;
		std::string	value;
		while (std::getline(_csv_file, line))
		{
			std::stringstream ss(line);
			std::getline(ss, date, ',');
			std::getline(ss, value);
			if (value.find_first_not_of("0123456789-,.") != std::string::npos)
				continue;
			if (date.find_first_not_of("0123456789-") != std::string::npos)
				continue;
			if (value.empty() || std::strstr(date.c_str(), "date"))
				continue;
			else
				this->_database.insert(std::pair<std::string, float>(date, atof(value.c_str())));
		}
		return 0;
	}
	std::cerr << "Error: invalid data file" << std::endl;
	return 1;
}

int	BitcoinExchange::parseInput(const char *file_path)
{
	_input_file.open(file_path, std::ifstream::in);
	if (_input_file.good())
	{
		std::string	line;
		std::string	date;
		std::string	value;
		while (std::getline(_input_file, line))
		{
			std::stringstream ss(line);
			if (line.length() == 1)
				continue;
			std::getline(ss, date, '|');
			std::getline(ss, value);
			if (value.empty() || date.empty() || std::strstr(date.c_str(), "date"))
				continue;
			else
				this->_input.insert(std::pair<std::string, float>(date, atof(value.c_str())));
		}
		return 0;
	}
	std::cerr << "Error: invalid input file" << std::endl;
	return 1;
}

bool BitcoinExchange::_checkDateFormat(const std::string &date)
{
	int	year;
	int	month;
	int	day;

	sscanf(date.c_str(), "%d-%d-%d", &year, &month, &day);
	if (year < 2009 )
		return false;
	if (year == 2009 && month == 1 && day <= 2)
		return false;
	if (month < 1 || month > 12)
		return false;
	if (day < 1 || day > 31)
		return false;
	if (month == 2 && day >= 29)
	{
		if (((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) && day == 29)
			return true;
		return false;
	}
	if (month == 4 && day > 30)
		return false;
	if (month == 6 && day > 30)
		return false;
	if (month == 9 && day > 30)
		return false;
	if (month == 11 && day > 30)
		return false;
	return true;
}

float BitcoinExchange::_calculateValue(float amount, const std::string &date)
{
	std::map<std::string, float>::const_iterator it = _database.find(date);
	if (it != _database.end())
		return it->second * amount;
	it = _database.lower_bound(date);
	if (it == _database.begin())
		return 0.00;
	it--;
	return it->second * amount;
}

void BitcoinExchange::printOutput()
{
	for (std::multimap<std::string, float>::iterator it = _input.begin(); it != _input.end(); ++it)
	{
		if (_checkDateFormat(it->first) == false)
			std::cout << "Error: Wrong input for date -> " << it->first << std::endl;
		else if (it->second < 0)
			std::cout << "Error: not a positive number." << std::endl;
		else if (it->second > 1000.00)
			std::cout << "Error: too large a number." << std::endl;
		else if (!it->second)
			std::cout << "Error: Wrong input" << std::endl;
		else
			std::cout << it->first << " -> " << it->second << " = " << _calculateValue(it->second, it->first) << std::endl;
	}
}
