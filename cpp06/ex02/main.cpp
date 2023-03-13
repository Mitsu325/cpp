/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 16:44:41 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/12 17:53:12 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"
# include <cstdlib>

Base	*generate(void)
{
	srand(time(0));
	if ((rand() % 3) == 0)
	{
		return (new A);
	}
	else if ((rand() % 3) == 1)
	{
		return (new B);
	}
	return (new C);
}

void	identify(Base* p)
{
	if (dynamic_cast<A*>(p))
	{
		std::cout << "A" << std::endl;
	}
	else if (dynamic_cast<B*>(p))
	{
		std::cout << "B" << std::endl;
	}
	else if (dynamic_cast<C*>(p))
	{
		std::cout << "C" << std::endl;
	}
}

void	identify(Base& p)
{
	try
	{
		A& a = dynamic_cast<A&>(p);
		std::cout << "A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{}
	try
	{
		B& b = dynamic_cast<B&>(p);
		std::cout << "B" << std::endl;
		(void)b;
	}
	catch(const std::exception& e)
	{}
	try
	{
		C& c = dynamic_cast<C&>(p);
		std::cout << "C" << std::endl;
		(void)c;
	}
	catch(const std::exception& e)
	{}
}

int	main(void)
{
	Base	*ptr1 = generate();

	std::cout << "==================================" << std::endl;

	std::cout << "*ptr1 = ";
	identify(ptr1);
	std::cout << "&ptr1 = ";
	identify(*ptr1);
	std::cout << std::endl;

	std::cout << "==================================" << std::endl;

	delete ptr1;
	return (0);
}
