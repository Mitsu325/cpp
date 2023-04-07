/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:14:49 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/04/07 10:57:50 by pmitsuko         ###   ########.fr       */
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

template<typename T>
void	PmergeMe::print(T &num)
{
	typename T::iterator	iter;

	for (iter = num.begin(); iter != num.end(); ++iter) {
		std::cout << *iter << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void	PmergeMe::mergeInsertSort(T &num, int start_pos, int end_pos)
{
	int	middle_pos;

	if (start_pos - end_pos > LIMIT)
	{
		middle_pos = (start_pos + end_pos) / 2;
		this->mergeInsertSort(num, start_pos, middle_pos);
		this->mergeInsertSort(num, middle_pos + 1, end_pos);
		this->mergeSort(num, start_pos, middle_pos, end_pos);
	}
	else
		this->insertSort(num, start_pos, end_pos);
}

template<typename T>
void	PmergeMe::insertSort(T &num, int start_pos, int end_pos)
{
	int	i, temp;

	for (int j = start_pos + 1; j < end_pos; j++)
	{
		temp = num[j];
		i = j - 1;
		while (i >= start_pos && num[i] > temp)
		{
			num[i + 1] = num[i];
			i--;
		}
		num[i + 1] = temp;
	}
}

template<typename T>
void	PmergeMe::mergeSort(T &num, int start_pos, int middle_pos, int end_pos)
{
	T	temp;
	int	temp_idx = start_pos;
	int	left_idx = start_pos;
	int	right_idx = middle_pos + 1;

	while ((left_idx <= middle_pos) && (right_idx <= end_pos))
	{
		if (num[left_idx] < num[right_idx])
		{
			temp[temp_idx] = num[left_idx];
			left_idx++;
		}
		else
		{
			temp[temp_idx] = num[right_idx];
			right_idx++;
		}
		temp_idx++;
	}
	for (; left_idx <= middle_pos; left_idx++, temp_idx++)
	{
		temp[temp_idx] = num[left_idx];
	}
	for (; right_idx <= end_pos; right_idx++, temp_idx++)
	{
		temp[temp_idx] = num[right_idx];
	}
	for (int i = start_pos; i <= end_pos; i++)
	{
		num[i] = temp[i];
	}
}

double	PmergeMe::elapsedTime(std::clock_t start, std::clock_t end)
{
	return (static_cast<double>(end - start) / (CLOCKS_PER_SEC / 1000));
}

void	PmergeMe::execute(void)
{
	std::clock_t				start, end;
	double						vec_elapsed_time, deque_elapsed_time;

	std::cout << std::left << std::setw(10) << "Before: ";
	this->print(this->_vector);
	start = std::clock();
	this->mergeInsertSort(this->_vector, 0, this->_vector.size());
	end = std::clock();
	vec_elapsed_time = this->elapsedTime(start, end);
	std::cout << std::left << std::setw(10) << "After: ";
	this->print(this->_vector);

	start = std::clock();
	this->mergeInsertSort(this->_deque, 0, this->_deque.size());
	end = std::clock();
	deque_elapsed_time = this->elapsedTime(start, end);

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
