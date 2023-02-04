/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/03 20:57:28 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void	bureaucrat_test(void)
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
}

void	form_test(void)
{
	{
		std::cout << "========== CONSTRUCTOR ===========" << std::endl;
		Form form1;
		std::cout << form1 << std::endl;
		Form form2("Form 2", 5, 10);
		std::cout << form2 << std::endl;
		Form form3("Form 3", 50, 70);
		std::cout << form3 << std::endl;
		Bureaucrat teddy("Teddy", 10);
		std::cout << teddy << std::endl;
		Form form3_copy(form3);
		std::cout << form3_copy << std::endl;
		form3_copy.beSigned(teddy);
		std::cout << "--- Copy form 3 ---" << std::endl;
		std::cout << form3_copy << std::endl;
		std::cout << "--- Base form 3 ---" << std::endl;
		std::cout << form3 << std::endl;
		form1 = form3_copy;
		std::cout << form1 << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "============= GRADE ==============" << std::endl;
		int arr[] = {-20, -1, 0, 1, 3, 5, 80, 142, 149, 150, 151, 162};
		int arr_len = sizeof(arr) / sizeof (arr[0]);
		for (int i = 0; i < arr_len; ++i)
		{
			std::cout << "Test number = " << arr[i] << std::endl;
			try
			{
				Form form1("Form 1", arr[i], 10);
				std::cout << form1 << std::endl;
			}
			catch (std::exception& exc)
			{
				std::cerr << exc.what() << std::endl;
			}
			std::cout << "-------" << std::endl;
			try
			{
				Form form2("Form 2", 20, arr[i]);
				std::cout << form2 << std::endl;
			}
			catch (std::exception& exc)
			{
				std::cerr << exc.what() << std::endl;
			}
			std::cout << "-------" << std::endl;
		}
	}
	std::cout << std::endl;
	{
		std::cout << "========= SIGN FORM ==========" << std::endl;
		try
		{
			Bureaucrat july("July", 10);
			std::cout << july << std::endl;
			Form form1("Form 1", 10, 20);
			std::cout << form1 << std::endl;
			july.signForm(form1);
			std::cout << form1 << std::endl;
			july.signForm(form1);
			std::cout << "-------" << std::endl;

			Form form2("Form 2", 15, 20);
			std::cout << form2 << std::endl;
			july.signForm(form2);
			std::cout << form2 << std::endl;
			july.signForm(form2);
			std::cout << "-------" << std::endl;

			Form form3("Form 3", 5, 20);
			std::cout << form3 << std::endl;
			july.signForm(form3);
			std::cout << form3 << std::endl;
			july.signForm(form3);
			std::cout << "-------" << std::endl;

			Form form4("Form 4", 4, 20);
			std::cout << form4 << std::endl;
			form4.beSigned(july);
		}
		catch(const std::exception& e)
		{
			std::cerr << e.what() << '\n';
		}
	}
	std::cout << "==================================" << std::endl;
}

int	main(void)
{
	// bureaucrat_test();
	form_test();
	return (0);
}
