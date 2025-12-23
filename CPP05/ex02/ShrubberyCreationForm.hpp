/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:21:24 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/19 12:57:17 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	private:
        std::string _target;
	public:
        ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm& other);
		ShrubberyCreationForm(std::string const & target);
		ShrubberyCreationForm& operator=(const ShrubberyCreationForm& other);
		virtual ~ShrubberyCreationForm();

        std::string getTarget() const;

		void execute(Bureaucrat const &executor) const;
		AForm& beSigned(const Bureaucrat& other);
		class ErrorOpeningFile : public std::exception{	
		public:
			const char* what() const throw();
		};
};