/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:59:06 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/09 15:37:21 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serializer::Serializer()
{
}

Serializer::~Serializer()
{
}

Serializer& Serializer::operator=(const Serializer& other)
{
	if (this != &other)
	{
		(void)other;
	}
    return (*this);
}

Serializer::Serializer(const Serializer& other)
{
    (void)other;
}

uintptr_t Serializer::serialize(Data* ptr) {
    return reinterpret_cast<uintptr_t>(ptr);
}

Data* Serializer::deserialize(uintptr_t raw) {
    return reinterpret_cast<Data*>(raw);
}
