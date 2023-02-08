/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 17:29:20 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/08 08:43:35 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"

Convert::Convert(void):
	_type(NONE),
	_input(""),
	_c('\0'),
	_i(0),
	_f(0.0f),
	_d(0.0)
{
	std::cout << "Convert default constructor called" << std::endl;
	return ;
}

Convert::Convert(char* arg):
	_type(NONE),
	_input(arg),
	_c('\0'),
	_i(0),
	_f(0.0f),
	_d(0.0)
{
	std::cout << "Convert constructor called" << std::endl;
	this->checkType(this->_input);
	if (this->_type == NONE)
		throw Convert::InputException();
	return ;
}

Convert::Convert(Convert const &obj)
{
	std::cout << "Convert copy constructor called" << std::endl;
	*this = obj;
	return ;
}

Convert::~Convert(void)
{
	std::cout << "Convert destructor called" << std::endl;
	return ;
}

Convert&	Convert::operator=(Convert const &obj)
{
	if (this != &obj)
	{
		this->_input = obj.getInput();
		this->_c = obj.getChar();
		this->_i = obj.getInt();
		this->_f = obj.getFloat();
		this->_d = obj.getDouble();
	}
	return (*this);
}

void	Convert::checkType(std::string str)
{
	if (isChar(str))
	{
		this->_type = CHAR;
		return ;
	}
	if (isInt(str))
	{
		this->_type = INT;
		return ;
	}
	if (isFloat(str))
	{
		this->_type = FLOAT;
		return ;
	}
	if (isDouble(str))
	{
		this->_type = DOUBLE;
		return ;
	}
	if (isPseudo(str))
	{
		this->_type = PSEUDO;
		return ;
	}
	this->_type = NONE;
	return ;
}

bool	Convert::isChar(std::string str)
{
	if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
		return (true);
	return (false);
}

bool	Convert::isInt(std::string str)
{
	long int	num;
	int			index;

	num = atol(this->_input.c_str());
	if (num > std::numeric_limits<int>::max() || num < std::numeric_limits<int>::min())
		return (false);
	index = 0;
	if (str[index] == '+' || str[index] == '-')
	{
		index++;
		if (str.length() == 1)
			return (false);
	}
	for (size_t i(index); i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return (false);
	}
	return (true);
}

bool	Convert::isFloat(std::string str)
{
	std::string::const_iterator	iterator;
	bool						decimalPoint = false;
	bool						letter_f = false;

	iterator = str.begin();
	if (str[0] == '+' || str[0] == '-')
	{
		iterator++;
		if (str.length() == 1)
			return (false);
	}
	while (iterator != str.end())
	{
		if (*iterator == '.')
		{
			if (!decimalPoint)
				decimalPoint = true;
			else
				break;
		}
		else if ((*iterator == 'f') && (iterator + 1 == str.end()))
		{
			letter_f = true;
		}
		else if (!isdigit(*iterator))
			break;
		iterator++;
	}
	return (iterator == str.end() && letter_f && decimalPoint);
}

bool	Convert::isDouble(std::string str)
{
	std::string::const_iterator	iterator;
	bool						decimalPoint = false;

	iterator = str.begin();
	if (str[0] == '+' || str[0] == '-')
	{
		iterator++;
		if (str.length() == 1)
			return (false);
	}
	while (iterator != str.end())
	{
		if (*iterator == '.')
		{
			if (!decimalPoint)
				decimalPoint = true;
			else
				break;
		}
		else if (!isdigit(*iterator))
			break;
		iterator++;
	}
	return (iterator == str.end() && decimalPoint);
}

bool	Convert::isPseudo(std::string str)
{
	return (str == "-inff" || str == "+inff" || str == "nanf" ||
		str == "-inf" || str == "+inf" || str == "nan");
}

void	Convert::convert(void)
{
	switch (this->_type)
	{
		case CHAR:
			this->_c = this->_input[0];
			this->_i = static_cast<int>(this->_c);
			this->_f = static_cast<float>(this->_c);
			this->_d = static_cast<double>(this->_c);
			break;
		case INT:
			this->_i = atoi(this->_input.c_str());
			this->_c = static_cast<char>(this->_i);
			this->_f = static_cast<float>(this->_i);
			this->_d = static_cast<double>(this->_i);
			break;
		case FLOAT:
			this->_f = static_cast<float>(atof(this->_input.c_str()));
			this->_c = static_cast<char>(this->_f);
			this->_i = static_cast<int>(this->_f);
			this->_d = static_cast<double>(this->_f);
			break;
		case DOUBLE:
			this->_d = atof(this->_input.c_str());
			this->_c = static_cast<char>(this->_d);
			this->_i = static_cast<int>(this->_d);
			this->_f = static_cast<float>(this->_d);
			break;
		default:
			break;
	}
}

int	Convert::getType(void) const
{
	return (this->_type);
}

std::string	Convert::getInput(void) const
{
	return (this->_input);
}

char	Convert::getChar(void) const
{
	return (this->_c);
}

int	Convert::getInt(void) const
{
	return (this->_i);
}

float	Convert::getFloat(void) const
{
	return (this->_f);
}

double	Convert::getDouble(void) const
{
	return (this->_d);
}

const char* Convert::InputException::what() const throw()
{
	return ("* Input parameter must be char, int, float or double *");
}

void	Convert::printChar(void) const
{
	if (this->_type == PSEUDO)
	{
		std::cout << "Impossible" << std::endl;
	}
	else if (!isprint(this->_c))
	{
		std::cout << "Non displayable" << std::endl;
	}
	else
	{
		std::cout << "'" << this->getChar() << "'" << std::endl;
	}
}

void	Convert::printInt(void) const
{
	long int	num;

	num = atol(this->_input.c_str());
	if (this->_type == PSEUDO || num > std::numeric_limits<int>::max() ||
		num < std::numeric_limits<int>::min())
	{
		std::cout << "Impossible" << std::endl;
	}
	else
	{
		std::cout << this->getInt() << std::endl;
	}
}

void	Convert::printFloat(void) const
{
	if (this->_type == PSEUDO)
	{
		if (this->_input == "nanf" || this->_input == "nan")
			std::cout << "nanf" << std::endl;
		else if (this->_input == "+inff" || this->_input == "+inf")
			std::cout << "+inff" << std::endl;
		else if (this->_input == "-inff" || this->_input == "-inf")
			std::cout << "-inff" << std::endl;
	}
	else
	{
		std::cout << this->getFloat();
		if ((this->_f - static_cast<int>(this->_f)) == 0)
			std::cout << ".0f" << std::endl;
		else
			std::cout << "f" << std::endl;
	}
}

void	Convert::printDouble(void) const
{
	if (this->_type == PSEUDO)
	{
		if (this->_input == "nanf" || this->_input == "nan")
			std::cout << "nan";
		else if (this->_input == "+inff" || this->_input == "+inf")
			std::cout << "+inf";
		else if (this->_input == "-inff" || this->_input == "-inf")
			std::cout << "-inf";
	}
	else
	{
		std::cout << this->getDouble();
		if ((this->_d - static_cast<int>(this->_d)) == 0)
			std::cout << ".0";
	}
	std::cout << std::endl;
}

std::ostream&	operator<<(std::ostream &stream, Convert const &obj)
{
	stream << "char: ";
	obj.printChar();
	stream << "int: ";
	obj.printInt();
	stream << "float: ";
	obj.printFloat();
	stream << "double: ";
	obj.printDouble();
	return (stream);
}
