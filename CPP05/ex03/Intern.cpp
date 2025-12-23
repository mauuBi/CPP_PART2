/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/19 18:05:16 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/19 23:59:31 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern& other) {
	(void)other;
}

Intern& Intern::operator=(const Intern& other) {
	(void)other;
	return *this;
}

Intern::~Intern() {
}

AForm* Intern::createPresidential(std::string const &target)
{
	return (new PresidentialPardonForm(target));
}

AForm* Intern::createRobotomy(std::string const &target)
{
	return (new RobotomyRequestForm(target));
}

AForm* Intern::createShrubbery(std::string const &target)
{
	return (new ShrubberyCreationForm(target));
}


AForm* Intern::makeForm(std::string const nameOfForm, std::string const target)
{
	std::string formNames[3] = {
		"PresidentialPardonForm",
		"RobotomyRequestForm",
		"ShrubberyCreationForm"
	};

	AForm* (*formCreator[3])(std::string const &) = {
		&Intern::createPresidential,
		&Intern::createRobotomy,
		&Intern::createShrubbery
	};
	for (int i = 0; i < 3; i++)
	{
		if (formNames[i] == nameOfForm)
		{
			std::cout << "Intern creates " << formNames[i] << std::endl;
			return(formCreator[i](target));
		}
	}
	std::cout << "The name of this form doesn't exist\n";
	return nullptr;
}
