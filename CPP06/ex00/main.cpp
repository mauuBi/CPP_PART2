/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/23 18:04:25 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/29 09:54:13 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc > 1)
		ScalarConverter::convert(argv[1]);
	else
		std::cout << "Usage : ./convert {char or int or float or double}\n";
}