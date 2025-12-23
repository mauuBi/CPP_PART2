/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:21:24 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/19 01:15:21 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include <ctime>
#include <cstdlib>

class RobotomyRequestForm : public AForm
{
	private:
        std::string _target;
	public:
        RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm& other);
		RobotomyRequestForm(std::string const & target);
		RobotomyRequestForm& operator=(const RobotomyRequestForm& other);
		virtual ~RobotomyRequestForm();

        std::string getTarget() const;

		void execute(Bureaucrat const &executor) const;
		AForm& beSigned(const Bureaucrat& other);
		class GradeHighException : public std::exception{	
		public:
			const char* what() const throw();
		};
		class GradeLowException : public std::exception{	
		public:
			const char* what() const throw();
		};
};