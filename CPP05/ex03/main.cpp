/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:08:55 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/20 00:01:31 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Intern.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Jerome("Jerome", 1);
		Bureaucrat Carlos("Carlos", 1);
		// Bureaucrat Fred("Fred", 1);
		// PresidentialPardonForm Form1("Form1");
		// RobotomyRequestForm Form2("Form2");
		// ShrubberyCreationForm Form3("Form3");
		Intern Paul;
		AForm *form = Paul.makeForm("PresidentialPardonForm", "Home");
		if (form)
		{
			Jerome.signForm(*form);
			Carlos.executeForm(*form);
			delete form;
		}
		// Jerome.signForm(Form1);
		// Form1.checkExecute(Jerome);
		// Carlos.signForm(Form2);
		// Form2.checkExecute(Carlos);
		// Fred.signForm(Form3);
		// Form3.checkExecute(Fred);
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}