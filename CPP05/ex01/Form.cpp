/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:51:19 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/18 11:59:28 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"


Form::Form(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeLowException();
}

const char* Form::GradeHighException::what() const throw(){
	return ("Grade is too high");
};

const char* Form::GradeLowException::what() const throw(){
	return ("Grade is too low to sign.");
};

Form& Form::operator=(const Form& other)
{
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}

Form::Form(const Form& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}


const std::string Form::getName() const
{
	return (this->_name);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}
int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}
bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

std::ostream& operator<<(std::ostream& os, const Form& other)
{
	os << "The name of the form is: " << other.getName() << ".\nIs it already signed : " << other.getIsSigned() <<  ".\nThe required grade to sign is : " << other.getGradeToSign() << ".\nThe required grade to execute is : " << other.getGradeToExecute() << ".";
	return (os);
}

Form& Form::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() > this->getGradeToSign())
			throw GradeLowException();
	else if (other.getGrade() <= this->getGradeToSign() && this->_isSigned == false)
	{
			this->_isSigned = true;
	}
	return *(this);
}

Form::~Form() {}