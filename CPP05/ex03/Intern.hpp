/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:05:12 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/19 23:47:59 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

class Intern {
	private:
	    static AForm* createShrubbery(std::string const &target);
    	static AForm* createRobotomy(std::string const &target);
    	static AForm* createPresidential(std::string const &target);
	public:
		Intern();
		Intern(const Intern &other);      
		Intern &operator=(const Intern &other); 
		~Intern();
		AForm* makeForm(std::string const nameOfForm, std::string const target);
};