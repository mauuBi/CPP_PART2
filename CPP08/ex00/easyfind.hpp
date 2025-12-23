/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:45:03 by mnassere          #+#    #+#             */
/*   Updated: 2025/11/02 23:09:38 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

template <typename T> int easytofind(T &a, int b)
{
	typename T::iterator it = std::find(a.begin(), a.end(), b);
	if (it != a.end())
		return (*it);
	throw std::runtime_error("Target not found in the container");
}

template <typename T> int easytofind(const T &a, int b)
{
	typename T::const_iterator it = std::find (a.begin(), a.end(), b);
	if (it != a.end())
		return (*it);
	throw std::runtime_error("Const Target not found in the container");
	return (-1);
}