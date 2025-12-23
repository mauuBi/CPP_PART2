/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:12:24 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/30 21:12:25 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base()
{
}

Base * generate(void)
{
	std::srand(std::time(0));
	int randomNum = std::rand() % 3;
	switch (randomNum)
	{
        case 0: return new A();
        case 1: return new B();
        case 2: return new C();
	}
	return NULL;
}

void identify(Base* p)
{
    if (dynamic_cast<A*>(p))
        std::cout << "A\n";
    else if (dynamic_cast<B*>(p))
        std::cout << "B\n";
    else if (dynamic_cast<C*>(p))
        std::cout << "C\n";
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A&>(p);
		std::cout << "A\n";
		return;
	}
	catch(...) {}
	try
	{
		(void)dynamic_cast<B&>(p);
		std::cout << "B\n";
		return;
	}
	catch(...) {}
	try
	{
		(void)dynamic_cast<C&>(p);
		std::cout << "C\n";
		return;
	}
	catch(...) {}
}