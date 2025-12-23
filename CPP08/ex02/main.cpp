/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:45:05 by mnassere          #+#    #+#             */
/*   Updated: 2025/11/03 17:51:44 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

int main()
{
	MutantStack<int> Stack;
	
	std::cout << Stack.size() << std::endl;
	Stack.push(1);
	std::cout << Stack.size() << std::endl;
	Stack.pop();
	std::cout << Stack.size() << std::endl;
	Stack.push(22);
	Stack.push(12);
	std::cout << Stack.top() << std::endl;
	Stack.top() = 99;
	std::cout << "Inside the stack :\n";
	for (MutantStack<int>::iterator it = Stack.begin(); it != Stack.end(); it++)
		std::cout << *it << std::endl;
}
