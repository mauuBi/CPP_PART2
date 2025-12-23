/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:51:13 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/19 12:44:33 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm{
	private:
		const std::string _name;
		bool _isSigned;
		const int _gradeToSign;
		const int _gradeToExecute;
	public:
		const std::string getName() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		bool getIsSigned() const ;

		AForm();
		AForm(const AForm& other);
		AForm(const std::string& name, int gradeToSign, int gradeToExecute);
		AForm& operator=(const AForm& other);
		virtual ~AForm();


		virtual AForm& beSigned(const Bureaucrat& other) = 0;
		virtual void execute(Bureaucrat const &executor) const = 0;
		void checkExecute(const Bureaucrat& other) const;
		class GradeHighException : public std::exception{	
		public:
			const char* what() const throw();
		};
		class GradeLowException : public std::exception{	
		public:
			const char* what() const throw();
		};
		class NotSigned : public std::exception{	
		public:
			const char* what() const throw();
		};
		class GradeTooLowExecute : public std::exception{	
		public:
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const AForm& other);