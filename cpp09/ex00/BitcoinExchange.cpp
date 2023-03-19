/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:53:09 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/19 11:03:55 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	this->loadDatabase();
	std::cout << "BitcoinExchange default constructor called" << std::endl;
	return ;
}

BitcoinExchange::BitcoinExchange(char* file): _file(file)
{
	this->loadDatabase();
	std::cout << "BitcoinExchange default constructor called" << std::endl;
	return ;
}

// BitcoinExchange::BitcoinExchange(std::string name): _name(name), _grade(150)
// {
// 	std::cout << "BitcoinExchange constructor called" << std::endl;
// 	return ;
// }

BitcoinExchange::BitcoinExchange(BitcoinExchange const &obj)
{
	std::cout << "BitcoinExchange copy constructor called" << std::endl;
	*this = obj;
	return ;
}

BitcoinExchange::~BitcoinExchange(void)
{
	std::cout << "BitcoinExchange destructor called" << std::endl;
	return ;
}

BitcoinExchange&	BitcoinExchange::operator=(BitcoinExchange const &obj)
{
	if (this != &obj)
	{
		// this->_grade = obj.getGrade();
	}
	return (*this);
}

bool	BitcoinExchange::checkFormat(std::string line, std::string delimiter, int num)
{
	size_t	found = 0;
	int		count = 0;

	found = line.find(delimiter, found);
	while (found != std::string::npos)
	{
		count++;
		found += delimiter.length();
		found = line.find(delimiter, found);
	}
	return (count == num);
}

int	BitcoinExchange::loadDatabase(void)
{
	std::string		line, date, delimiter = ",";
	std::fstream	fs_in;
	size_t			pos = 0;
	tm				time_info;

	fs_in.open(DATABASE_FILE, std::fstream::in);
	if (!fs_in.is_open())
	{
		std::cerr << "Error: " << std::strerror(errno) << std::endl;
		return (1);
	}
	while (std::getline(fs_in, line))
	{
		if (this->checkFormat(line, delimiter, 1))
		{
			pos = line.find(delimiter);
			date = line.substr(0, pos);
			line.erase(0, pos + delimiter.length());
			if (!strptime(date.c_str(), "%Y-%m-%d", &time_info))
				continue;
			_database[date] = static_cast<float>(atof(line.c_str()));
		}
	}
	fs_in.close();
	// std::map<std::string, float>::iterator it;
	// for (it = this->_database.begin(); it != this->_database.end(); ++it){
	// 	std::cout << it->first << " => " << it->second << '\n';
	// }
	return (0);
}

// std::string	BitcoinExchange::getName(void) const
// {
// 	return (this->_name);
// }

// const char* BitcoinExchange::GradeTooHighException::what() const throw()
// {
// 	return ("* Grade too high *");
// }

// const char* BitcoinExchange::GradeTooLowException::what() const throw()
// {
// 	return ("* Grade too low *");
// }
