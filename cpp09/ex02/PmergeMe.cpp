/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:14:49 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/26 13:14:18 by pmitsuko         ###   ########.fr       */
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
	this->initVector(argv);
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
	}
	return (*this);
}

bool	PmergeMe::isNumber(std::string &str)
{
	return (!str.empty() &&
		str.find_first_not_of("0123456789") == std::string::npos);
}

void	PmergeMe::initVector(char** argv)
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
			}
			else
			{
				throw PmergeMe::PmergeMeException("Error: invalid number");
			}
		}
	}
	return ;
}

void	PmergeMe::insertSort(int start_pos, int end_pos)
{
	int	i, temp;

	for (int j = start_pos + 1; j < end_pos; j++)
	{
		temp = this->_vector[j];
		i = j - 1;
		while (i >= start_pos && this->_vector[i] > temp)
		{
			this->_vector[i + 1] = this->_vector[i];
			i--;
		}
		this->_vector[i + 1] = temp;
	}
}

void	PmergeMe::mergeSort(int start_pos, int middle_pos, int end_pos)
{
	std::vector<int>	temp;
	int					temp_idx = start_pos;
	int					left_idx = start_pos;
	int					right_idx = middle_pos + 1;

	while ((left_idx <= middle_pos) && (right_idx <= end_pos))
	{
		if (this->_vector[left_idx] < this->_vector[right_idx])
		{
			temp[temp_idx] = this->_vector[left_idx];
			left_idx++;
		}
		else
		{
			temp[temp_idx] = this->_vector[right_idx];
			right_idx++;
		}
		temp_idx++;
	}
	for (; left_idx <= middle_pos; left_idx++, temp_idx++)
	{
		temp[temp_idx] = this->_vector[left_idx];
	}
	for (; right_idx <= end_pos; right_idx++, temp_idx++)
	{
		temp[temp_idx] = this->_vector[right_idx];
	}
	for (int i = start_pos; i <= end_pos; i++)
	{
		this->_vector[i] = temp[i];
	}
}

void	PmergeMe::mergeInsertSort(int start_pos, int end_pos)
{
	int	middle_pos;

	if (start_pos - end_pos > LIMIT)
	{
		middle_pos = (start_pos + end_pos) / 2;
		mergeInsertSort(start_pos, middle_pos);
		mergeInsertSort(middle_pos + 1, end_pos);
		mergeSort(start_pos, middle_pos, end_pos);
	}
	else
		insertSort(start_pos, end_pos);
}

void	PmergeMe::execute(void)
{
	std::vector<int>::iterator	iter;
	std::clock_t				start, end;
	double						elapsed_time;

	std::cout << std::left << std::setw(10) << "Before: ";
	for (iter = this->_vector.begin(); iter != this->_vector.end(); ++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	start = std::clock();
	mergeInsertSort(0, this->_vector.size());
	end = std::clock();
	elapsed_time = static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000);

	std::cout << std::left << std::setw(10) << "After: ";
	for (iter = this->_vector.begin(); iter != this->_vector.end(); ++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;

	std::cout << "Time to process a range of " << this->_vector.size();
	std::cout << " elements with std::vector : " << elapsed_time << " ms";
	std::cout << std::endl;
}

PmergeMe::PmergeMeException::PmergeMeException(const char* msg):
	_msg(msg) {}

const char* PmergeMe::PmergeMeException::what() const throw()
{
	return (this->_msg);
}
