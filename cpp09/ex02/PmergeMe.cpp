/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:14:49 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/26 17:36:10 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(void)
{
	std::cout << "PmergeMe default constructor called" << std::endl;
	return ;
}

PmergeMe::PmergeMe(char** argv)
{
	std::cout << "PmergeMe constructor called" << std::endl;
	this->initContainers(argv);
	return ;
}

PmergeMe::PmergeMe(PmergeMe const &obj)
{
	std::cout << "PmergeMe copy constructor called" << std::endl;
	*this = obj;
	return ;
}

PmergeMe::~PmergeMe(void)
{
	std::cout << "PmergeMe destructor called" << std::endl;
	return ;
}

PmergeMe&	PmergeMe::operator=(PmergeMe const &obj)
{
	if (this != &obj)
	{
		this->_vector = obj._vector;
		this->_deque = obj._deque;
	}
	return (*this);
}

bool	PmergeMe::isNumber(std::string &str)
{
	return (!str.empty() &&
		str.find_first_not_of("0123456789") == std::string::npos);
}

void	PmergeMe::initContainers(char** argv)
{
	std::string			str, token;
	int					num;

	for (char **p_argv = argv + 1; *p_argv != NULL; p_argv++)
	{
		str = *p_argv;
		std::stringstream	buffer(str);
		while (buffer >> token)
		{
			if (isNumber(token))
			{
				num = atoi(token.c_str());
				if (num > INT_MAX || num < 0)
				{
					throw PmergeMe::PmergeMeException("Error: invalid range number");
				}
				this->_vector.push_back(num);
				this->_deque.push_back(num);
			}
			else
			{
				throw PmergeMe::PmergeMeException("Error: invalid number");
			}
		}
	}
	return ;
}

void	PmergeMe::execute(void)
{
	std::clock_t				start, end;
	double						vec_elapsed_time, deque_elapsed_time;

	std::cout << std::left << std::setw(10) << "Before: ";
	this->print(this->_vector);
	start = std::clock();
	mergeInsertSort(this->_vector, 0, this->_vector.size());
	end = std::clock();
	vec_elapsed_time = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000);
	std::cout << std::left << std::setw(10) << "After: ";
	this->print(this->_vector);

	start = std::clock();
	mergeInsertSort(this->_deque, 0, this->_deque.size());
	end = std::clock();
	deque_elapsed_time = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000);

	std::cout << "Time to process a range of " << this->_vector.size();
	std::cout << " elements with std::vector : " << vec_elapsed_time << " ms";
	std::cout << std::endl;
	std::cout << "Time to process a range of " << this->_deque.size();
	std::cout << " elements with std::deque : " << deque_elapsed_time << " ms";
	std::cout << std::endl;
}

PmergeMe::PmergeMeException::PmergeMeException(const char* msg):
	_msg(msg) {}

const char* PmergeMe::PmergeMeException::what() const throw()
{
	return (this->_msg);
}
