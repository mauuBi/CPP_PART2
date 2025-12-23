/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:12:21 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/30 21:20:10 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <cstdlib>
#include <ctime>
#include <iostream>


class Base {
	public:
	virtual ~Base();
};

Base * generate(void);
void identify(Base* p);
void identify(Base& p);