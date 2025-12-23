/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:51:13 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/18 11:47:48 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Form{
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

		Form(const Form& other);
		Form(const std::string& name, int gradeToSign, int gradeToExecute);
		Form& operator=(const Form& other);
		~Form();


		Form& beSigned(const Bureaucrat& other);
		class GradeHighException : public std::exception{	
		public:
			const char* what() const throw();
		};
		class GradeLowException : public std::exception{	
		public:
			const char* what() const throw();
		};
};

std::ostream& operator<<(std::ostream& os, const Form& other);