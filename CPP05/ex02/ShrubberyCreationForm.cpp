/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/18 12:21:22 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/19 17:03:03 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: AForm("ShrubberyCreationForm", 145, 137), _target("default") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string const & target)
	: AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

const char* ShrubberyCreationForm::ErrorOpeningFile::what() const throw(){
	return ("There was an error creating the file.");
};

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other) {
	if (this != &other) {
		this->_target = other._target;
	}
	return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
	: AForm(other), _target(other._target) {}

std::string ShrubberyCreationForm::getTarget() const
{
	return this->_target;
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	std::string filename = this->getTarget() + "_shrubbery";
	std::ofstream File(filename);
	executor.getName();

	if (!File)
	{
		throw ErrorOpeningFile();
	}
	
    std::string tree =
        "       ###\n"
        "      #o###\n"
        "    #####o###\n"
        "   #o#\\#|#/###\n"
        "    ###\\|/#o#\n"
        "     # }|{  #\n"
        "       }|{\n";

    for (int i = 0; i < 3; ++i) {
        File << tree << std::endl;
    }
	File.close();
}

std::ostream& operator<<(std::ostream& os, const ShrubberyCreationForm& other)
{
	os << "The name of the form is: " << other.getName() << ".\nIs it already signed : " << other.getIsSigned() <<  ".\nThe required grade to sign is : " << other.getGradeToSign() << ".\nThe required grade to execute is : " << other.getGradeToExecute() << ".";
	return (os);
}

AForm& ShrubberyCreationForm::beSigned(const Bureaucrat &other)
{
	return AForm::beSigned(other);
}

ShrubberyCreationForm::~ShrubberyCreationForm() {}
