/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 21:47:57 by mnassere          #+#    #+#             */
/*   Updated: 2025/11/01 22:29:06 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T> void iter(T *array, const size_t len, void (*func)(T &arg))
{
	std::cout << "Len of the array is : " << len << std::endl;
	std::cout << "Inside the array before Func : \n";
	for (size_t i = 0 ; i < len; i++)
	{
		std::cout << array[i] << std::endl;
	}
	std::cout << "Inside the array after Func : \n";
	for (size_t i = 0 ; i < len; i++)
	{
		func(array[i]);
		std::cout << array[i] << std::endl;
	}
}

template <typename T> void iter(const T *array, const size_t len, void (*func)(const T &arg))
{
	std::cout << "Len of the array is : " << len << std::endl;
	std::cout << "Inside the array before Func : \n";
	for (size_t i = 0 ; i < len; i++)
	{
		std::cout << array[i] << std::endl;
	}
	std::cout << "Inside the array after Func : \n";
	for (size_t i = 0 ; i < len; i++)
	{
		func(array[i]);
		std::cout << array[i] << std::endl;
	}
}