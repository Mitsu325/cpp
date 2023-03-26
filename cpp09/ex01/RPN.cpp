/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 17:32:01 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/26 17:41:32 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void): _notation(NULL)
{
	std::cout << "RPN default constructor called" << std::endl;
	return ;
}

RPN::RPN(char* notation): _notation(notation)
{
	std::cout << "RPN constructor called" << std::endl;
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
	return (token.size() < 3 && (token.at(0) == '+' || token.at(0) == '-' ||
			token.at(0) == '*' || token.at(0) == '/'));
}

bool	RPN::validateNumber(std::string token)
{
	return (token.size() == 1 && std::isdigit(token.at(0)));
}

void	RPN::calculate(const char* arithmetic_operator)
{
	int	a, b;

	if (this->_stack.size() < 2)
	{
		throw RPN::RPNException("Error: no result");
	}
	b = this->_stack.top();
	this->_stack.pop();
	a = this->_stack.top();
	this->_stack.pop();
	switch (*arithmetic_operator)
	{
		case '+':
			this->_stack.push(a + b);
			break;
		case '-':
			this->_stack.push(a - b);
			break;
		case '*':
			this->_stack.push(a * b);
			break;
		case '/':
			if (b == 0)
				throw RPN::RPNException("Error: no result");
			this->_stack.push(a / b);
			break;
		default:
			break;
	}
}

void	RPN::compute(void)
{
	std::stringstream	buffer(this->_notation);
	std::string			token;
	std::string			temp;

	if (!this->_notation.size())
		return;
	while (buffer >> token)
	{
		if (this->validateOperator(token))
		{
			this->calculate(token.c_str());
			if (token.size() == 2)
			{
				temp = token.at(1);
				if (this->validateNumber(temp))
					this->_stack.push(atoi(temp.c_str()));
				else
					throw RPN::RPNException("Error: invalid expression");
			}
		}
		else if (this->validateNumber(token))
		{
			this->_stack.push(atoi(token.c_str()));
		}
		else
		{
			throw RPN::RPNException("Error: invalid expression");
		}
	}
	while (!this->_stack.empty())
	{
		std::cout << this->_stack.top() << std::endl;
		this->_stack.pop();
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
