/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 18:11:47 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/11 21:19:41 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <map>
#include <fstream>
#include <unistd.h>
#include <stdlib.h>
#include <sstream>

void parsing_database(std::map<std::string, float> &database);
void print_database(const std::map<std::string, float> &database);
void parsing_infile(std::string inputFile, std::map<std::string, float>  &database);
void print_input(const std::map<std::string, std::pair<float, int> > &database);

