/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/02 20:48:52 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	{
		std::cout << "========== CONSTRUCTOR ===========" << std::endl;
		Bureaucrat bob;
		std::cout << bob << std::endl;
		Bureaucrat john("John");
		std::cout << john << std::endl;
		Bureaucrat ted("Ted", 20);
		std::cout << ted << std::endl;
		Bureaucrat ted_copy(ted);
		std::cout << ted_copy << std::endl;
		bob = ted_copy;
		std::cout << bob << std::endl;
	}
	{
		std::cout << "============= GRADE ==============" << std::endl;
		int arr[] = {-20, -1, 0, 1, 3, 5, 80, 142, 149, 150, 151, 162};
		int arr_len = sizeof(arr) / sizeof (arr[0]);
		for (int i = 0; i < arr_len; ++i)
		{
			std::cout << "Test number = " << arr[i] << std::endl;
			try
			{
				Bureaucrat jimmy("Jimmy", arr[i]);
				std::cout << jimmy << std::endl;
			}
			catch (std::exception& exc)
			{
				std::cerr << exc.what() << std::endl;
			}
		}
	}
	{
		std::cout << "=========== INCREMENT ============" << std::endl;
		try
		{
			Bureaucrat judy("Judy", 2);
			std::cout << judy << std::endl;
			judy.decrementGrade();
			std::cout << judy << std::endl;
			judy.incrementGrade();
			std::cout << judy << std::endl;
			judy.incrementGrade();
			std::cout << judy << std::endl;
			judy.incrementGrade();
			std::cout << judy << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	{
		std::cout << "=========== DECREMENT ============" << std::endl;
		try
		{
			Bureaucrat judy("Judy", 149);
			std::cout << judy << std::endl;
			judy.incrementGrade();
			std::cout << judy << std::endl;
			judy.decrementGrade();
			std::cout << judy << std::endl;
			judy.decrementGrade();
			std::cout << judy << std::endl;
			judy.decrementGrade();
			std::cout << judy << std::endl;
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "==================================" << std::endl;
	return (0);
}
