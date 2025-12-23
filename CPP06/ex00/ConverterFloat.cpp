/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConverterFloat.cpp                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:46:12 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/09 15:28:39 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::checkFloat(const std::string parameter)
{
	size_t	len;
	size_t	start;
	bool	hasDot;
	bool	hasDigit;
	char	c;

	len = parameter.length();
	if (len < 2)
		return (false);
	start = 0;
	if (parameter[0] == '+' || parameter[0] == '-')
		start = 1;
	if (parameter[len - 1] != 'f' && parameter[len - 1] != 'F')
		return (false);
	hasDot = false;
	hasDigit = false;
	for (size_t i = start; i < len - 1; ++i)
	{
		c = parameter[i];
		if (c == '.')
		{
			if (hasDot)
				return (false);
			hasDot = true;
		}
		else if (std::isdigit(static_cast<unsigned char>(c)))
			hasDigit = true;
		else
			return (false);
	}
	return (hasDot && hasDigit);
}
void	printFloat(double value)
{
	float	c;

	std::cout << "float: ";
	if (std::isnan(value))
	{
		std::cout << "nanf" << std::endl;
		return ;
	}
	if (std::isinf(value))
	{
		std::cout << (value > 0 ? "+inff" : "-inff") << std::endl;
		return ;
	}
	c = static_cast<float>(value);
	std::cout << std::fixed;
	if (fabs(fmod(c, 1.0)) < 1e-6)
		std::cout << std::fixed << std::setprecision(1) << c << "f" << std::endl;
	else
	{
		std::cout.unsetf(std::ios::floatfield);
		std::cout << c << "f" << std::endl;
	}
}
