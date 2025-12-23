/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:03:00 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/19 17:01:19 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "AForm.hpp"

class AForm;

class Bureaucrat{
	private:
		const std::string _name;
		int _grade;
	public:
	const std::string getName() const;
	int getGrade() const;
	Bureaucrat(const std::string name, int grade);
	~Bureaucrat();
	Bureaucrat(const Bureaucrat& other);
	Bureaucrat& operator=(const Bureaucrat& other);

	void upRank(int amount);
	void deRank(int amount);

	void	signForm(AForm& other);
	void	executeForm(AForm const & form) const;

	class BureaucratLowExecption : public std::exception{	
		public:
			const char* what() const throw();
	};
	class BureaucratHighExecption : public std::exception{	
		public:
			const char* what() const throw();
	};

	class CannotExecute : public std::exception{	
		public:
			const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other);