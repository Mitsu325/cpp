/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 20:13:03 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/25 16:47:49 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"
#include <iostream>
#include <list>

void	test_subject(void)
{
	std::cout << "================ Subject ================" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << "Top: " << mstack.top() << std::endl;
	mstack.pop();
	std::cout << "Size: " << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);
	return ;
}

void	test_iterator(void)
{
	std::cout << "================ Iterator ===============" << std::endl;
	MutantStack<int> mstack0;
	mstack0.push(10);
	mstack0.push(20);
	mstack0.push(30);
	mstack0.push(40);
	mstack0.push(50);
	MutantStack<int> mstack1(mstack0);
	MutantStack<int> mstack2 = mstack1;
	std::cout << "mstack0 Top: " << mstack0.top() << std::endl;
	std::cout << "mstack0 Size: " << mstack0.size() << std::endl;
	std::cout << "mstack1 Top: " << mstack1.top() << std::endl;
	std::cout << "mstack1 Size: " << mstack1.size() << std::endl;
	std::cout << "mstack2 Top: " << mstack2.top() << std::endl;
	std::cout << "mstack2 Size: " << mstack2.size() << std::endl;

	std::cout << "Iterator mstack0" << std::endl;
	for (MutantStack<int>::iterator it = mstack0.begin(); it != mstack0.end(); it++)
	{
		std::cout << *it << ' ';
	}
	std::cout << std::endl;
	return ;
}

void	test_list(void)
{
	std::cout << "================= List ==================" << std::endl;

	std::list<int> lst;
	lst.push_back(5);
	lst.push_back(17);
	std::cout << "Back: " << lst.back() << std::endl;
	lst.pop_back();
	std::cout << "Size: " << lst.size() << std::endl;
	lst.push_back(3);
	lst.push_back(5);
	lst.push_back(737);
	lst.push_back(0);
	std::list<int>::iterator it = lst.begin();
	std::list<int>::iterator ite = lst.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	return ;
}

int	main(void)
{
	test_subject();
	test_iterator();
	test_list();
	return (0);
}
