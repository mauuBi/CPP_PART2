/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:13:16 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/11 18:11:10 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
	try
	{
		if (argc != 2)
		{
			throw std::runtime_error ("Usage : ./btc 'file.txt'");
		}
		std::map<std::string, float> database;
		parsing_database(database);
		parsing_infile(argv[1], database);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}