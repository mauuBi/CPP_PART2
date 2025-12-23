/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/03 16:57:16 by mnassere          #+#    #+#             */
/*   Updated: 2025/11/03 17:57:07 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
	public:
		MutantStack();
		~MutantStack();
		MutantStack(const MutantStack<T> &other);
		MutantStack<T> &operator=(const MutantStack<T> &other);

		typedef typename std::stack<T>::container_type::iterator iterator;
		typedef typename std::stack<T>::container_type::const_iterator const_iterator;

		iterator begin() {return this->c.begin();}
		iterator end() {return this->c.end();}

		const_iterator begin() const {return this->c.begin();}
		const_iterator end() const {return this->c.end();}
};

template <typename T>
MutantStack<T>::MutantStack()
{}

template <typename T>
MutantStack<T>::~MutantStack()
{}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack<T> &other) : std::stack<T>(other)
{
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack<T> &other)
{
    std::stack<T>::operator=(other);
    return *this;
}
