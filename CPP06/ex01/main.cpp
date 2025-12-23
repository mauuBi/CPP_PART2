/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 09:58:40 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/09 15:36:21 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "Data.hpp"
// #include "Serialization.hpp"

// int main()
// {
// 	Data data;

// 	data.age = 21;
// 	data.name = "Mohamed";
// 	data.score = 100;
// 	std::cout << data.age;
// 	Serializer::serialize(&data);
// 	std::cout << data.age;
// }

#include <iostream>
#include "Serialization.hpp"

int main() {
    Data data = {"Moha", 21, 98.5};

    uintptr_t raw = Serializer::serialize(&data);
    Data* ptr = Serializer::deserialize(raw);

    std::cout << "Address de base: " << &data << std::endl;
    std::cout << "Serialized : " << raw << std::endl;
    std::cout << "Deserialized : " << ptr << std::endl;

    if (ptr == &data)
        std::cout << "Pointers match!" << std::endl;
    else
        std::cout << "Pointers differ." << std::endl;

    std::cout << "Name: " << ptr->name << ", Age: " << ptr->age 
              << ", Score: " << ptr->score << std::endl;

    return 0;
}
