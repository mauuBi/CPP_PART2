/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConverterDouble.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:54:05 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/09 15:29:55 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::checkDouble(const std::string parameter)
{
	size_t	len;
	size_t	start;
	bool	hasDotOrE;
	bool	hasDigit;
	char	c;

	len = parameter.length();
	if (len == 0)
		return (false);
	start = 0;
	if (parameter[0] == '+' || parameter[0] == '-')
		start = 1;
	if (parameter[len - 1] == 'f' || parameter[len - 1] == 'F')
		return (false);
	hasDotOrE = false;
	hasDigit = false;
	for (size_t i = start; i < len; ++i)
	{
		c = parameter[i];
		if (c == '.' || c == 'e' || c == 'E')
		{
			if (hasDotOrE && c == '.')
				return (false);
			hasDotOrE = true;
		}
		else if (std::isdigit(static_cast<unsigned char>(c)))
			hasDigit = true;
		else
			return (false);
	}
	return (hasDotOrE && hasDigit);
}

void	printDouble(double value)
{
	std::cout << "double: ";
	if (std::isnan(value))
	{
		std::cout << "nan" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		std::cout << (value > 0 ? "+inf" : "-inf") << std::endl;
		return ;
	}

	std::cout << std::fixed;
	if (fabs(fmod(value, 1.0)) < 1e-9)
		std::cout << std::fixed << std::setprecision(1) << value << std::endl;
	else
	{
		std::cout.unsetf(std::ios::floatfield);
		std::cout << value << std::endl;
	}
}