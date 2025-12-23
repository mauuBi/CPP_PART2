/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:38:35 by mnassere          #+#    #+#             */
/*   Updated: 2025/11/02 11:19:24 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <stdexcept>

template <typename T> class Array
{
	private:
		T* _array;
		unsigned int _size;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array<T> &other);
		Array& operator=(const Array<T>& other);
		~Array();

		unsigned int size() const;

		T &operator[](unsigned int index);
		const T &operator[](unsigned int index) const;
};

template <typename T> 
Array<T>::Array() : _array(NULL), _size(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n)
{
}

template <typename T>
Array<T>::Array(const Array<T> &other) : _array(NULL), _size(other._size)
{
	if (this->_size > 0)
		this->_array = new T[this->_size];
	for (unsigned int i = 0; i < this->_size; i++)
		this->_array[i] = other._array[i];
}

template <typename T>
Array<T>& Array<T>::operator=(const Array<T>& other)
{
	if (this != &other)
	{
		delete[] this->_array;
		this->_size = other._size;
		this->_array = (this->_size > 0) ? new T[this->_size] : NULL;
		for (unsigned int i = 0; i < this->_size; i++)
			this->_array[i] = other._array[i];
	}
	return *this;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= this->_size)
		throw std::out_of_range("Index out of bounds");
	else
		return _array[index];
}

template <typename T>
const T &Array<T>::operator[](unsigned int index) const
{
	if (index >= this->_size)
		throw std::out_of_range("Index out of bounds");
	else
		return _array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	 return (_size);
}

template <typename T>
Array<T>::~Array()
{
	delete[] this->_array;
}




