/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:11:18 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/04/07 10:55:51 by pmitsuko         ###   ########.fr       */
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
		double	elapsedTime(std::clock_t start, std::clock_t end);

		template<typename T>
		void	print(T &num);

		template<typename T>
		void	mergeInsertSort(T &num, int start_pos, int end_pos);

		template<typename T>
		void	insertSort(T &num, int start_pos, int end_pos);

		template<typename T>
		void	mergeSort(T &num, int start_pos, int middle_pos, int end_pos);
};

#endif
