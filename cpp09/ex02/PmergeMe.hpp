/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/25 19:11:18 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/03/26 13:15:15 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef P_MERGE_ME_H
# define P_MERGE_ME_H

# include <climits>
# include <cstdlib>
# include <cstdio>
# include <ctime>
# include <iomanip>
# include <iostream>
# include <sstream>
# include <stdexcept>
# include <string>
# include <vector>

# define LIMIT 5

class PmergeMe
{
	private:
		std::vector<int>	_vector;

		void	initVector(char** argv);
		bool	isNumber(std::string &str);
		void	mergeInsertSort(int start_pos, int end_pos);
		void	insertSort(int start_pos, int end_pos);
		void	mergeSort(int start_pos, int middle_pos, int end_pos);

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
};

#endif
