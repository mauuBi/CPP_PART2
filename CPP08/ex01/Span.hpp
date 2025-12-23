/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 23:14:21 by mnassere          #+#    #+#             */
/*   Updated: 2025/11/03 00:24:17 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <vector>
#include <stdexcept>
#include <iostream>
#include <limits.h>
#include <list>
#include <algorithm>
#include <vector>
#include <list>
#include <deque>

class Span {
private:
    unsigned int _size;
    std::vector<int> _array;

public:
    explicit Span(unsigned int N);
    void addNumber(int x);
    int shortestSpan() const;
    int longestSpan() const;
    template <typename It>
    void addNumber(It begin, It end);
};

template <typename It>
void Span::addNumber(It begin, It end)
{
    unsigned int amount = std::distance(begin, end);

    if (_array.size() + amount > _size)
        throw std::runtime_error("Span capacity exceeded");

    _array.insert(_array.end(), begin, end);
}
