/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 22:38:37 by mnassere          #+#    #+#             */
/*   Updated: 2025/11/02 11:38:34 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main()
{
    std::cout << "Constructeur Vide" << std::endl;
    Array<int> a;
    std::cout << "Taille de a: " << a.size() << std::endl;

    std::cout << "\nConstructeur Rempli" << std::endl;
    Array<int> b(5);
    std::cout << "Taille de b: " << b.size() << std::endl;
    for (unsigned int i = 0; i < b.size(); i++)
        b[i] = i * 10;

    std::cout << "B:";
    for (unsigned int i = 0; i < b.size(); i++)
        std::cout << b[i] << " ";
    std::cout << std::endl;

    std::cout << "\nIndex out of bound" << std::endl;
    try {
        std::cout << b[10] << std::endl; // doit throw
    }
    catch (const std::exception &e) {
        std::cout << "Catch : " << e.what() << std::endl;
    }

    std::cout << "\nConstructeur de copie" << std::endl;
    Array<int> c(b);
    std::cout << "C: (copie de b): ";
    for (unsigned int i = 0; i < c.size(); i++)
        std::cout << c[i] << " ";
    std::cout << std::endl;

    std::cout << "\nJe modifie C mais pas B" << std::endl;
    c[0] = 999;
    std::cout << "c[0] = " << c[0] << std::endl;
    std::cout << "b[0] = " << b[0] << std::endl;

    std::cout << "\nOperateur d'assignation" << std::endl;
    Array<int> d;
    d = b; // affectation
    std::cout << "D: (copie de b)\n";
    for (unsigned int i = 0; i < d.size(); i++)
        std::cout << d[i] << " ";
    std::cout << std::endl;

    std::cout << "\nTemplate avec string" << std::endl;
    Array<std::string> e(3);
    e[0] = "Hello";
    e[1] = "Template";
    e[2] = "World";

    for (unsigned int i = 0; i < e.size(); i++)
        std::cout << e[i] << " ";
    std::cout << std::endl;

    return 0;
}
