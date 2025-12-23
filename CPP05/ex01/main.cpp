/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:08:55 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/18 12:01:09 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Jerome("Jerome", 151);
		Bureaucrat Carlos("Carlos", 2);
		Form SFP("SFP", 149, 1);
		std::cout << SFP << std::endl;
		//SFP.beSigned(Jerome);
		Jerome.signForm(SFP);
		std::cout << SFP << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}