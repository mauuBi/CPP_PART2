/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 11:45:05 by mnassere          #+#    #+#             */
/*   Updated: 2025/11/02 23:09:45 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int main()
{
	std::vector<int> tmp;
	tmp.push_back(1);
	tmp.push_back(2);
	tmp.push_back(3);
	const std::vector<int> v = tmp;

	try {
		std::cout << "Found in vector: " << easytofind(v, 2) << std::endl;
		std::cout << "Found in vector: " << easytofind(v, 42) << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "\nVector: " << e.what() << std::endl;
	}

	std::list<int> lst;
	lst.push_back(10);
	lst.push_back(20);
	lst.push_back(30);

	try {
		std::cout << "Found in list: " << easytofind(lst, 30) << std::endl;
		std::cout << "Found in list: " << easytofind(lst, 99) << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "\nList: " << e.what() << std::endl;
	}

	std::deque<int> d;
	d.push_back(7);
	d.push_back(14);
	d.push_back(21);

	try {
		std::cout << "Found in deque: " << easytofind(d, 14) << std::endl;
		std::cout << "Found in deque: " << easytofind(d, -1) << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "\nDeque: " << e.what() << std::endl;
	}
	return 0;
}
