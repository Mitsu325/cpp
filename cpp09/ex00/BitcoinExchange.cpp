/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:53:09 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/19 11:36:40 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(void)
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
	this->loadDatabase();
	return ;
}

BitcoinExchange::BitcoinExchange(char* file): _file(file)
{
	std::cout << "BitcoinExchange default constructor called" << std::endl;
	this->loadDatabase();
	return ;
}

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
		this->_file = obj.getFile();
		this->_database = obj.getDatabase();
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
		throw BitcoinExchange::BitcoinExchangeException("could not open file");
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

std::string	BitcoinExchange::getFile(void) const
{
	return (this->_file);
}

std::map<std::string, float> BitcoinExchange::getDatabase(void) const
{
	return (this->_database);
}

BitcoinExchange::BitcoinExchangeException::BitcoinExchangeException(const char* msg):
	_msg(msg) {}

const char* BitcoinExchange::BitcoinExchangeException::what() const throw()
{
	return (this->_msg);
}
