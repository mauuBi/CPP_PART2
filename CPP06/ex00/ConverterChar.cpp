/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ConverterChar.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 19:34:23 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/29 09:31:24 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

bool ScalarConverter::checkChar(std::string parameter)
{
	if (parameter.length() != 1)
		return (false);
	char c = parameter[0];
	if (std::isdigit(static_cast<unsigned char>(c)))
		return (false);
	return (true);
}
void printChar(double value)
{
    std::cout << "char: ";

    if (std::isnan(value) || std::isinf(value))
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    if (fabs(fmod(value, 1.0)) >= 1e-9)
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    int intVal = static_cast<int>(value);

    if (intVal < std::numeric_limits<char>::min() ||
        intVal > std::numeric_limits<char>::max())
    {
        std::cout << "impossible" << std::endl;
        return;
    }
    char c = static_cast<char>(intVal);
    if (std::isprint(c))
        std::cout << "'" << c << "'" << std::endl;
    else
        std::cout << "Non displayable" << std::endl;
}

