/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 18:03:07 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/19 16:59:42 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name)
{
	if (grade < 1)
		throw BureaucratHighExecption();
	else if (grade > 150)
		throw BureaucratLowExecption();
	else
		this->_grade = grade;
}

const char* Bureaucrat::BureaucratLowExecption::what() const throw(){
	return ("Grade is too low");
};

const char* Bureaucrat::BureaucratHighExecption::what() const throw(){
	return ("Grade is too high");
};

void Bureaucrat::executeForm(AForm const & form) const
{
	try
	{
		form.execute(*this);
		std::cout << this->getName() << " executed : " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	
	
	
}

const std::string Bureaucrat::getName() const 
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

Bureaucrat::~Bureaucrat()
{
}
Bureaucrat::Bureaucrat(const Bureaucrat& other) : _name(other._name), _grade(other._grade)
{
}

void	Bureaucrat::signForm(AForm& other)
{
	try
	{
		other.beSigned(*this);
		std::cout << this->_name << " signed " << other.getName() << " !\n";
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn't sign " << other.getName() << " because : " << e.what() << '\n';
	}
}

void Bureaucrat::upRank(int amount)
{
	if ((this->_grade - amount) < 1)
		throw BureaucratHighExecption();
	else
		this->_grade -= amount;
}


void Bureaucrat::deRank(int amount)
{
	if ((this->_grade + amount) > 150)
		throw BureaucratLowExecption();
	else
		this->_grade += amount;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& other)
{
	if (this != &other)
	{
		this->_grade = other._grade;
	}
	return *this;
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& other)
{
	os << other.getName() << ", bureaucrat grade " << other.getGrade();
	return (os);
}