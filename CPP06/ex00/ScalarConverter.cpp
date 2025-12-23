/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 17:41:18 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/09 15:27:29 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"


void ScalarConverter::convert(std::string parameter)
{
	char	c;
	double	i;
	float	j;
	double	d;

	if (parameter == "+inf" || parameter == "+inff")
	{
		std::cout << "char: impossible\n"
					<< "int: impossible\n"
					<< "float: +inff\n"
					<< "double: +inf\n";
		return ;
	}
	if (parameter == "-inf" || parameter == "-inff")
	{
		std::cout << "char: impossible\n"
					<< "int: impossible\n"
					<< "float: -inff\n"
					<< "double: -inf\n";
		return ;
	}
	if (parameter == "nan" || parameter == "nanf")
	{
		std::cout << "char: impossible\n"
					<< "int: impossible\n"
					<< "float: nanf\n"
					<< "double: nan\n";
	}
	if (ScalarConverter::checkChar(parameter))
	{
		c = parameter[0];
		printChar(c);
		printInt(c);
		printFloat(c);
		printDouble(c);
	}
	else if (ScalarConverter::checkInt(parameter))
	{
		i = std::strtod(parameter.c_str(), NULL);
		printChar(i);
		printInt(i);
		printFloat(i);
		printDouble(i);
	}
	else if (ScalarConverter::checkFloat(parameter))
	{
		j = static_cast<float>(std::strtod(parameter.c_str(), NULL));
		printChar(j);
		printInt(j);
		printFloat(j);
		printDouble(j);
	}
	else if (ScalarConverter::checkDouble(parameter))
	{
		d = std::strtod(parameter.c_str(), NULL);
		printChar(d);
		printInt(d);
		printFloat(d);
		printDouble(d);
	}
}

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::~ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	if (this != &other)
	{
		(void)other;
	}
	return (*this);
}