/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/28 22:44:11 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	{
		const Animal* dog = new Dog();
		const Animal* cat = new Cat();
		const Animal* animal = new Animal();

		std::cout << "========= BASIC TEST =========" << std::endl;
		std::cout << "Type: " << dog->getType() << std::endl;
		dog->makeSound();
		std::cout << "Type: " << cat->getType() << std::endl;
		cat->makeSound();
		std::cout << "Type: " << animal->getType() << std::endl;
		animal->makeSound();
		std::cout << "===============================" << std::endl;
		delete cat;
		cat = NULL;
		delete dog;
		dog = NULL;
		delete animal;
		animal = NULL;
	}
	std::cout << std::endl;
	{
		const WrongAnimal* cat = new WrongCat();
		const WrongAnimal* animal = new WrongAnimal();
		const WrongCat* cat_2 = new WrongCat();
		std::cout << "======= WRONG CLASS TEST ======" << std::endl;
		std::cout << "Type: " << cat->getType() << std::endl;
		cat->makeSound();
		std::cout << "Type: " << animal->getType() << std::endl;
		animal->makeSound();
		std::cout << "Type: " << cat_2->getType() << std::endl;
		cat_2->makeSound();
		std::cout << "===============================" << std::endl;
		delete cat;
		cat = NULL;
		delete animal;
		animal = NULL;
		delete cat_2;
		cat_2 = NULL;
	}
	return (0);
}
