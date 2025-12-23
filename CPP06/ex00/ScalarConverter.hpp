/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:41:15 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/09 15:27:32 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once 
#include <iostream>
#include <ctype.h>
#include <cctype>
#include <limits>
#include <iomanip>
#include <cmath>
#include <string>
#include <cstdlib>

void printChar(double value);
void printInt(double value);
void printFloat(double value);
void printDouble(double value);

class ScalarConverter {
	private:

	public:
	ScalarConverter();
	~ScalarConverter();
	ScalarConverter(const ScalarConverter& other);
	ScalarConverter& operator=(const ScalarConverter& other);

	static void convert(std::string parameter);
	static bool checkChar(std::string parameter);
	static bool checkInt(std::string parameter);
	static bool checkDouble(std::string parameter);
	static bool checkFloat(std::string parameter);
};