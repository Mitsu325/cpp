/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/18 13:53:09 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/19 16:23:53 by pmitsuko         ###   ########.fr       */
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

bool	BitcoinExchange::checkFormat(std::string line, std::string delimiter,
	int num)
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

bool BitcoinExchange::checkDate(std::string date)
{
	int					year, month, day;
	time_t				raw_time;
	struct tm			*time_info, *time_norm;

	time(&raw_time);
	time_info = localtime(&raw_time);
	if (strptime(date.c_str(), "%Y-%m-%d", time_info))
	{
		year = time_info->tm_year;
		month = time_info->tm_mon;
		day = time_info->tm_mday;
		raw_time = mktime(time_info);
		time_norm = localtime(&raw_time);
		return (time_norm->tm_mday == day &&
				time_norm->tm_mon == month &&
				time_norm->tm_year == year);
	}
	return (false);
}

void	BitcoinExchange::loadDatabase(void)
{
	std::string		line, date, delimiter = ",";
	std::fstream	fs_in;
	size_t			pos = 0;

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
			if (!this->checkDate(date))
				continue;
			this->_database[date] = strtof(line.c_str(), NULL);
		}
	}
	return ;
}

void	BitcoinExchange::getFileData(std::string line, std::string delimiter,
	std::string &date, float &bitcoin)
{
	size_t	pos = 0;

	pos = line.find(delimiter);
	date = line.substr(0, pos);
	pos = pos + delimiter.length();
	bitcoin = strtof(line.c_str() + pos, NULL);
}

bool	BitcoinExchange::validateFileData(std::string date, float bitcoin)
{
	if (!this->checkDate(date))
	{
		std::cout << "Error: invalid date => " << date << std::endl;
		return (false);
	}
	if (bitcoin < 0)
	{
		std::cout << "Error: not a positive number." << std::endl;
		return (false);
	}
	if (bitcoin > 1000)
	{
		std::cout << "Error: too large a number." << std::endl;
		return (false);
	}
	return (true);
}

void	BitcoinExchange::displayFileData(std::string date, float bitcoin)
{
	std::map<std::string, float>::iterator	it;

	it = this->_database.upper_bound(date);
	if (it != this->_database.begin())
		it--;
	std::cout << date << " => " << bitcoin << " = " << (*it).second * bitcoin;
	std::cout << std::endl;
}

void	BitcoinExchange::displayExchange(void)
{
	std::string		line, date, delimiter = " | ";
	std::fstream	fs_in;
	float			bitcoin;

	fs_in.open(this->_file.c_str(), std::fstream::in);
	if (!fs_in.is_open())
	{
		throw BitcoinExchange::BitcoinExchangeException("could not open file");
	}
	while (std::getline(fs_in, line))
	{
		if (this->checkFormat(line, delimiter, 1))
		{
			this->getFileData(line, delimiter, date, bitcoin);
			if (!this->validateFileData(date, bitcoin)) continue;
			this->displayFileData(date, bitcoin);
		}
		else
		{
			std::cout << "Error: bad input => " << line << std::endl;
		}
	}
	fs_in.close();
	return ;
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
