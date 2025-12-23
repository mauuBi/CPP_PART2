/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:45:05 by mnassere          #+#    #+#             */
/*   Updated: 2025/11/03 00:24:58 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

int main()
{
	Span Array(5);
	std::vector<int> v;
	v.push_back(6);
	v.push_back(3);
	v.push_back(17);
	v.push_back(9);
	v.push_back(11);
	try
	{
		Array.addNumber(v.begin(), v.end());
		std::cout << Array.longestSpan() << std::endl;
		std::cout << Array.shortestSpan() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

}
