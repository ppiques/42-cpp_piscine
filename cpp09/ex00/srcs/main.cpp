/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ppiques <ppiques@students.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 14:18:43 by ppiques           #+#    #+#             */
/*   Updated: 2023/03/24 14:18:43 by ppiques          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <sstream>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        std::cerr << "Usage: btc <input_file>\n";
        return 1;
    }
    std::ifstream csv_file("data.csv");
    if (!csv_file.is_open()) {
        std::cerr << "Failed to open data.csv\n";
        return 1;
    }
    std::map<std::string, float> exchange_rates;
    std::string line;
    while (std::getline(csv_file, line)) {
        std::istringstream iss(line);
        std::string date_str;
        float exchange_rate;
        std::getline(iss, date_str, ',');
        iss >> exchange_rate;
        exchange_rates[date_str] = exchange_rate;
    }
    csv_file.close();

    std::ifstream input_file(argv[1]);
    if (!input_file.is_open()) {
        std::cerr << "Failed to open input file\n";
        return 1;
    }
    while (std::getline(input_file, line)) {
        std::istringstream iss(line);
        std::string date_str;
        float value;
        std::getline(iss, date_str, '|');
        iss >> value;
        float exchange_rate = exchange_rates[date_str];
        std::cout << value * exchange_rate << '\n';
    }
    input_file.close();

    return 0;
}