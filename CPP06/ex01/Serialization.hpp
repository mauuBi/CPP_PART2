/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:59:04 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/09 15:33:53 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include "Data.hpp"


class Serializer
{
  private:
	Serializer();
	~Serializer();
	Serializer(const Serializer &other);
	Serializer &operator=(const Serializer &other);

  public:
	static uintptr_t serialize(Data *ptr);
	static Data *deserialize(uintptr_t raw);
};