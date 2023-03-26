/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:11:18 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/26 17:33:26 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef P_MERGE_ME_H
# define P_MERGE_ME_H

# include <climits>
# include <cstdlib>
# include <cstdio>
# include <ctime>
# include <deque>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <string>
# include <vector>

# define LIMIT 5

class PmergeMe
{
	public:
		PmergeMe(void);
		PmergeMe(char** argv);
		PmergeMe(PmergeMe const &obj);
		~PmergeMe(void);
		PmergeMe&	operator=(PmergeMe const &obj);

		void	execute(void);

		class PmergeMeException: public std::exception
		{
			private:
				const char* _msg;

			public:
				PmergeMeException(const char* msg);
				virtual const char* what() const throw();
		};

	private:
		std::vector<int>	_vector;
		std::deque<int>		_deque;

		void	initContainers(char** argv);
		bool	isNumber(std::string &str);

		template<typename T>
		void	print(T &num)
		{
			typename T::iterator	iter;

			for (iter = num.begin(); iter != num.end(); ++iter) {
				std::cout << *iter << " ";
			}
			std::cout << std::endl;
		}

		template<typename T>
		void	mergeInsertSort(T &num, int start_pos, int end_pos)
		{
			int	middle_pos;

			if (start_pos - end_pos > LIMIT)
			{
				middle_pos = (start_pos + end_pos) / 2;
				mergeInsertSort(num, start_pos, middle_pos);
				mergeInsertSort(num, middle_pos + 1, end_pos);
				mergeSort(num, start_pos, middle_pos, end_pos);
			}
			else
				insertSort(num, start_pos, end_pos);
		}

		template<typename T>
		void	insertSort(T &num, int start_pos, int end_pos)
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
		void	mergeSort(T &num, int start_pos, int middle_pos, int end_pos)
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
};

#endif
