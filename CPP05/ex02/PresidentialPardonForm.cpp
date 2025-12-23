/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:21:22 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/19 16:54:42 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: AForm("PresidentialPardonForm", 25, 5), _target("default") {}

PresidentialPardonForm::PresidentialPardonForm(std::string const & target)
	: AForm("PresidentialPardonForm", 25, 5), _target(target) {}

const char* PresidentialPardonForm::GradeHighException::what() const throw(){
	return ("Grade is too high");
};

const char* PresidentialPardonForm::GradeLowException::what() const throw(){
	return ("Grade is too low to sign.");
};

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& other)
	: AForm(other), _target(other._target) {}

std::string PresidentialPardonForm::getTarget() const
{
	return this->_target;
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox and\n";
	executor.getName();
}

std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& other)
{
	os << "The name of the form is: " << other.getName() << ".\nIs it already signed : " << other.getIsSigned() <<  ".\nThe required grade to sign is : " << other.getGradeToSign() << ".\nThe required grade to execute is : " << other.getGradeToExecute() << ".";
	return (os);
}

AForm& PresidentialPardonForm::beSigned(const Bureaucrat &other)
{
	return AForm::beSigned(other);
}

PresidentialPardonForm::~PresidentialPardonForm() {}
