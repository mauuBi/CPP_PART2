/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/10 19:08:55 by mnassere          #+#    #+#             */
/*   Updated: 2025/10/10 20:48:04 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(void)
{
	try
	{
		Bureaucrat Jerome("Jerome", 149);
		Bureaucrat Lubna("Lubna", 2);
		std::cout << "PRE INCREMENTATION\n" << Jerome << std::endl;
		std::cout << Lubna << std::endl;
		Jerome.deRank(1);
		Lubna.upRank(1);
		std::cout << "POST INCREMENTATION\n" << Jerome << std::endl;
		std::cout << Lubna << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}
}