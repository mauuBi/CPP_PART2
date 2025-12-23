/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 19:20:57 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/14 19:26:41 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc == 2)
	{
		try
		{
			processRPN(argv[1]);
		}
		catch(const std::exception& e)
		{
			std::cout << e.what() << '\n';
		}
	}
	else
		std::cout << "Usage : ./RPN {1 2 * ...}\n";
	return 0;
}
