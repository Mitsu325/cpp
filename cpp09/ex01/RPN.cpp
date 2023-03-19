/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:32:01 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/19 18:16:42 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
	std::cout << "RPN default constructor called" << std::endl;
	return ;
}

RPN::RPN(char* notation): _notation(notation)
{
	std::cout << "RPN default constructor called" << std::endl;
	return ;
}

RPN::RPN(RPN const &obj)
{
	std::cout << "RPN copy constructor called" << std::endl;
	*this = obj;
	return ;
}

RPN::~RPN(void)
{
	std::cout << "RPN destructor called" << std::endl;
	return ;
}

RPN&	RPN::operator=(RPN const &obj)
{
	if (this != &obj)
	{
		this->_notation = obj.getNotation();
	}
	return (*this);
}

bool	RPN::validateOperator(std::string token)
{
	return (token.size() == 1 &&
			(token.at(0) == '+' || token.at(0) == '-' ||
			token.at(0) == '*' || token.at(0) == '/'));
}

bool	RPN::validateNumber(std::string token)
{
	if (token.size() == 1 && std::isdigit(token.at(0)))
	{
		return (true);
	}
	else if (token.size() == 2)
	{
		if ((token.at(0) == '+' || token.at(0) == '-') && std::isdigit(token.at(1)))
		{
			return (true);
		}
	}
	return (false);
}

void	RPN::calculate(void)
{
	std::stringstream	buffer(this->_notation);
	std::string			token;
	int					num;

	while (buffer >> token)
	{
		if (this->validateOperator(token))
		{
			std::cout << token << std::endl;
		}
		else if (this->validateNumber(token))
		{
			num = atoi(token.c_str());
			std::cout << num << std::endl;
		}
		else
		{
			throw RPN::RPNException("Error");
		}
	}
	return ;
}

std::string	RPN::getNotation(void) const
{
	return (this->_notation);
}

RPN::RPNException::RPNException(const char* msg):
	_msg(msg) {}

const char* RPN::RPNException::what() const throw()
{
	return (this->_msg);
}
