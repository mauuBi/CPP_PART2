/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConverterInt.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:36:41 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/29 09:43:04 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::checkInt(std::string parameter)
{
	size_t len = parameter.length();
	if (len == 0)
		return (false);
	size_t start = 0;
	if (parameter[0] == '+' || parameter[0] == '-') 
	{
		if (len == 1)
			return (false);
		start = 1;
	}
	for (size_t i = start; i < len; ++i) {
		if (!std::isdigit(static_cast<unsigned char>(parameter[i])))
			return (false);
	}
	return (true);
}

void printInt(double value)
{
    std::cout << "int: ";
    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
	if (value < static_cast<double>(std::numeric_limits<int>::min()) - 0.0001 ||
		value > static_cast<double>(std::numeric_limits<int>::max()) + 0.0001)
	{
		std::cout << "impossible" << std::endl;
		return;
	}
    int c = static_cast<int>(value);
    std::cout << c << std::endl;
}
