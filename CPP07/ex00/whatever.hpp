/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 23:23:52 by mnassere          #+#    #+#             */
/*   Updated: 2025/11/01 21:44:37 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>

template <typename T>  T min(T a, T b)
{
	if (a == b || b < a)
		return (b);
	return (a);
}

template <typename T> T max(T a, T b)
{
	if (a == b || b > a)
		return (b);
	return (a);
}

template <typename T> void swap(T &a, T &b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}