/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnassere <mnassere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 12:29:50 by mnassere          #+#    #+#             */
/*   Updated: 2025/12/11 18:37:08 by mnassere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <cstdlib>   
#include <cctype>
#include <cstdio>    

bool validateToken(const char &vectorString)
{
	std::string validateTokenCalc = "+-/*";

	for (size_t j = 0; j < validateTokenCalc.size(); j++)
	{
		if (vectorString == validateTokenCalc[j])
			return true;
	}
	return false;
}

bool validateNumber(const char &vectorString)
{
	std::string validateNumber = "0123456789";
	
	for (size_t i = 0; i < validateNumber.size(); i++)
	{
		if (vectorString == validateNumber[i])
			return true;
	}
	return false;
}

void calculateRPN(std::stack<int> &st, char tokenMath)
{
	int first = st.top();
	st.pop();
	int second = st.top();
	st.pop();
	int sum = 0;
	switch (tokenMath)
	{
	case ('+'):
		sum = second + first;
		st.push(sum);
		break;
	case ('-'):
		sum = second - first;
		st.push(sum);
		break;
	case ('/'):
		if (first == 0)
			throw std::runtime_error("Error no possible to divide by 0");
		sum = second / first;
		st.push(sum);
		break;
	case ('*'):
		sum = second * first;
		st.push(sum);
		break;
	default:
		break;
	}
}

void processRPN(const char *input)
{
	std::stack<int> st;
	const char *p = input;
	size_t tokenCount = 0;

	while (*p)
	{
		while (*p == ' ') ++p;
		if (*p == '\0') break;

		if ((*p == '+' || *p == '/' || *p == '*') && (p[1] == ' ' || p[1] == '\0'))
		{
			if (st.size() > 1)
			{
				calculateRPN(st, *p);
			}
			else
			{
				throw std::runtime_error("A token math is appearing too early, not enough number to do the operation ");
			}
			++tokenCount;
			++p;
			continue;
		}

		if (*p == '-')
		{
			if (std::isdigit(static_cast<unsigned char>(p[1])) && (p[2] == ' ' || p[2] == '\0'))
			{
				int val = - (p[1] - '0');
				st.push(val);
				tokenCount++;
				p += 2;
				continue;
			}
			if (p[1] == ' ' || p[1] == '\0')
			{
				if (st.size() > 1)
					calculateRPN(st, '-');
				else
					throw std::runtime_error("A token math is appearing too early, not enough number to do the operation ");
				tokenCount++;
				++p;
				continue;
			}
			throw std::runtime_error("This input is not good : -");
		}

		if (std::isdigit(static_cast<unsigned char>(*p)) && (p[1] == ' ' || p[1] == '\0'))
		{
			int val = *p - '0';
			st.push(val);
			tokenCount++;
			++p;
			continue;
		}

		throw std::runtime_error("This input is not good : invalid token");
	}

	if (tokenCount < 3)
		throw std::runtime_error("A token math is missing");
	if (st.size() != 1)
		throw std::runtime_error("A token math is missing");

	std::stack<int> tmp(st);
	while (!tmp.empty())
	{
		std::printf("%d\n", tmp.top());
		tmp.pop();
	}
}
