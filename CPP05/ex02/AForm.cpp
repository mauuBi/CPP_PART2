/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 20:51:19 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/19 16:51:29 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string& name, int gradeToSign, int gradeToExecute)
	: _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeHighException();
	else if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeLowException();
}

const char* AForm::GradeHighException::what() const throw(){
	return ("Grade is too high");
};

void AForm::checkExecute(const Bureaucrat& other) const
{
	try
	{
		if (other.getGrade() <= this->getGradeToExecute() && this->_isSigned)
		{
			other.executeForm(*this);
		}
		else if (other.getGrade() > this->getGradeToExecute())
			throw GradeTooLowExecute();
		else if (!this->_isSigned)
			throw NotSigned();
	}
	catch(const std::exception& e)
	{
		std::cerr << other.getName() << " couldn't execute " << this->getName() << " because : " << e.what() << '\n';
	}
	

}

const char* AForm::GradeLowException::what() const throw(){
	return ("Grade is too low to sign.");
};

const char* AForm::GradeTooLowExecute::what() const throw(){
	return ("Grade is too low to execute. Give it to a higher ranked.");
};

const char* AForm::NotSigned::what() const throw(){
	return ("This Form is not signed yet.");
};

AForm& AForm::operator=(const AForm& other)
{
	if (this != &other) {
		this->_isSigned = other._isSigned;
	}
	return *this;
}

AForm::AForm(const AForm& other) : _name(other._name), _isSigned(other._isSigned), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{
}


const std::string AForm::getName() const
{
	return (this->_name);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}
int AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}
bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

std::ostream& operator<<(std::ostream& os, const AForm& other)
{
	os << "The name of the form is: " << other.getName() << ".\nIs it already signed : " << other.getIsSigned() <<  ".\nThe required grade to sign is : " << other.getGradeToSign() << ".\nThe required grade to execute is : " << other.getGradeToExecute() << ".";
	return (os);
}

AForm& AForm::beSigned(const Bureaucrat &other)
{
	if (other.getGrade() > this->getGradeToSign())
			throw GradeLowException();
	else if (other.getGrade() <= this->getGradeToSign())
	{
		this->_isSigned = true;
	}
	return *(this);
}

AForm::~AForm() {}