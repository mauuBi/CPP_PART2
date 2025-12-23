/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:23:54 by mnassere          #+#    #+#             */
/*   Updated: 2025/11/01 22:31:09 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

void	Increment(int &a)
{
	a += 1;
}

void	print(const int &a)
{
	std::cout << "ICI LA : "<< a << std::endl;
}

int main( void ) 
{
	const int array[] = {1,2,3,4,5};
	const int len = 5;
	
	iter(array, len, print);
	return 0;
}