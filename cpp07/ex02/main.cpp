/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 19:35:25 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/02/14 19:59:47 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int main(void)
{
	Array<int> arr1(8);
	Array<int> arr2(4);

	for (unsigned int i = 0; i < arr1.size(); i++) {
		arr1[i] = i + 2;
	}

	std::cout << "arr1: " << arr1 << std::endl;

	arr2 = arr1;

	std::cout << "arr2: " << arr2 << std::endl;

	Array<double> arr3(4);
	Array<double> arr4(6);

	for (unsigned int i = 0; i < arr3.size(); i++) {
		arr3[i] = i + 2.5;
	}

	std::cout << "arr3: " << arr3 << std::endl;

	arr4 = arr3;

	std::cout << "arr4: " << arr4 << std::endl;

	Array<std::string> arr5(3);

	arr5[0] = "Hey";
	arr5[1] = "this";
	arr5[2] = "ok!";

	std::cout << "arr5: " << arr5 << std::endl;

	Array<std::string> arr6(arr5);

	std::cout << "arr6: " << arr6 << std::endl;

	try
	{
		std::cout << "arr1[5]: " << arr1[5] << std::endl;
		std::cout << "arr1[10]: " << arr1[10] << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	return (0);
}
