/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:21:22 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/19 16:55:16 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: AForm("RobotomyRequestForm", 72, 45), _target("default") {}

RobotomyRequestForm::RobotomyRequestForm(std::string const & target)
	: AForm("RobotomyRequestForm", 72, 45), _target(target) {}

const char* RobotomyRequestForm::GradeHighException::what() const throw(){
	return ("Grade is too high");
};

const char* RobotomyRequestForm::GradeLowException::what() const throw(){
	return ("Grade is too low to sign.");
};

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& other)
	: AForm(other), _target(other._target) {}

std::string RobotomyRequestForm::getTarget() const
{
	return this->_target;
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	std::cout << "*Drilling noises*\n";
	std::srand(std::time(nullptr));
	int random = std::rand() % 2;
	executor.getName();
	if (random == 0)
	{
		std::cout << this->getTarget() << " has been robotomized successfully\n";
	}
	else if (random == 1)
	{
		std::cout << this->getTarget() << " robotomized has failed\n";
	}
}

std::ostream& operator<<(std::ostream& os, const RobotomyRequestForm& other)
{
	os << "The name of the form is: " << other.getName() << ".\nIs it already signed : " << other.getIsSigned() <<  ".\nThe required grade to sign is : " << other.getGradeToSign() << ".\nThe required grade to execute is : " << other.getGradeToExecute() << ".";
	return (os);
}

AForm& RobotomyRequestForm::beSigned(const Bureaucrat &other)
{
	return AForm::beSigned(other);
}

RobotomyRequestForm::~RobotomyRequestForm() {}
