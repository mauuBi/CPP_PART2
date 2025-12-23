/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:12:31 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/11 21:21:23 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

bool	validateFormat(const std::string &date, const std::string &dateVerif,
		size_t pos)
{
	int	month;
	int	day;
	int	year;
	int	maxDay;

	for (size_t i = 10; i < pos; i++)
	{
		if (dateVerif[i] != ' ')
			return (false);
	}
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
	{
		return (false);
	}
	month = std::atoi(date.substr(5, 2).c_str());
	day = std::atoi(date.substr(8, 2).c_str());
	year = std::atoi(date.substr(0, 4).c_str());
	if (month > 12 || month < 1)
	{
		return (false);
	}
	for (size_t i = 0; i < date.size(); i++)
	{
		if ((i != 4 && i != 7) && !std::isdigit(date[i]))
			return (false);
	}
	maxDay = 0;
	switch (month)
	{
	case 2:
		maxDay = (year % 4 == 0 && (year % 100 != 0 || year
					% 400 == 0)) ? 29 : 28;
		break ;
	case 4:
	case 6:
	case 9:
	case 11:
		maxDay = 30;
		break ;
	default:
		maxDay = 31;
		break ;
	}
	if (day < 1 || day > maxDay)
	{
		return (false);
	}
	return (true);
}

bool	validatePrice(const std::string &price)
{
	int	dot;

	dot = 0;
	for (size_t i = 0; i < price.size(); i++)
	{
		if (price[i] == '.' && dot == 0)
		{
			dot = 1;
		}
		else if (!std::isdigit(price[i]))
		{
			return (false);
		}
	}
	return (true);
}

void	print_database(const std::map<std::string, float> &database)
{
	for (std::map<std::string,
		float>::const_iterator it = database.begin(); it != database.end(); it++)
		std::cout << it->first << " => " << it->second << std::endl;
}

void	print_input(const std::map<std::string, std::pair<float,
		int> > &database)
{
	for (std::map<std::string, std::pair<float,
		int> >::const_iterator it = database.begin(); it != database.end(); it++)
		std::cout << it->first << " => " << it->second.first << std::endl;
}

void	calculateBitcoin(const std::map<std::string, float> &database,
		std::string dateInput, float priceInput)
{
	float	price;
	float	result;

	std::map<std::string,
		float>::const_iterator it = database.lower_bound(dateInput);
	price = 0;
	if (it != database.end() && it->first == dateInput)
	{
		price = it->second;
	}
	else
	{
		if (it == database.begin())
		{
			std::cerr << "Error: date too early" << std::endl;
			return ;
		}
		--it;
		price = it->second;
	}
	result = priceInput * price;
	std::cout << dateInput << " => " << priceInput << " = " << result << std::endl;
}

void	parsing_infile(std::string inputFile, std::map<std::string,
		float> &database)
{
	size_t	pos;
	float	price;

	std::ifstream infile(inputFile.c_str());
	if (!infile)
		throw std::runtime_error("Cannot open the input file");
	std::string line;
	while (std::getline(infile, line))
	{
		pos = line.find('|');
		if (pos == std::string::npos)
		{
			std::cerr << "Can't find the '|' (expected format: {DATE} | {Nb of bitcoin})" << std::endl;
			continue ;
		}
		std::string date = line.substr(0, 10);
		std::string dateVerif = line.substr(0, pos);
		std::string tmp = line.substr(pos + 2);
		price = std::atof(line.substr(pos + 2).c_str());
		if (validateFormat(date, dateVerif, pos) == false)
		{
			std::cerr << "Error : bad input : " << dateVerif << std::endl;
			continue ;
		}
		if (price < 0)
		{
			std::cerr << "Error : Not a positive number : " << price << std::endl;
			continue ;
		}
		else if (price > 1000)
		{
			std::cerr << "Error : The value is too high : " << price << std::endl;
			continue ;
		}
		else if (validatePrice(tmp) == false)
		{
			std::cerr << "Error : The format of the value is not good : " << tmp << std::endl;
			continue ;
		}
		calculateBitcoin(database, date, price);
	}
}

void	parsing_database(std::map<std::string, float> &database)
{
	std::ifstream infile("data.csv");
	if (!infile)
		throw std::runtime_error("Cannot open the file data.csv");
	std::string line;
	while (std::getline(infile, line))
	{
		if (line.size() < 12)
			continue ;

		size_t pos = line.find(',');
		if (pos == std::string::npos)
			continue ;
		std::string date = line.substr(0, 10);
		std::string priceStr = line.substr(pos + 1);
		if (!isdigit(date[0]))
			continue ;
		float price = std::atof(priceStr.c_str());
		database[date] = price;
	}
}