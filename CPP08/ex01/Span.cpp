/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:14:19 by mnassere          #+#    #+#             */
/*   Updated: 2025/11/03 00:22:08 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

Span::Span(unsigned int N): _size(N)
{
}

void Span::addNumber(int x)
{
    if (_array.size() >= _size) 
		throw std::runtime_error("Span is full");
    _array.push_back(x);
}

int Span::longestSpan() const
{
	if (_array.size() < 2)
		throw std::runtime_error("Not enough variable for the Span");
	unsigned int len = _array.size();
	int max = std::numeric_limits<int>::min();
	int min = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < len; i++)
	{
		if (_array[i] > max)
		{
			max = _array[i];
		}
		if (_array[i] < min)
		{
			min = _array[i];
		}
	}
	return (max - min);
}

int Span::shortestSpan() const
{
	if (_array.size() < 2)
		throw std::runtime_error("Not enough variable for the Span");
	std::vector<int> tmp = _array;
	std::sort(tmp.begin(), tmp.end());
	unsigned int len = _array.end() - _array.begin();
	int shortestSpan = std::numeric_limits<int>::max();
	for (unsigned int i = 0; i < len - 1; i++)
	{
		if (tmp[i + 1] - tmp[i] < shortestSpan)
		{
			shortestSpan = tmp[i + 1] - tmp[i];
		}
	}
	return (shortestSpan);
}