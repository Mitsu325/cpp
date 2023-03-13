/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/29 19:38:43 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	{
		Animal* dog = new Dog();
		Animal* cat = new Cat();

		std::cout << "========= BASIC TEST =========" << std::endl;
		std::cout << "Type: " << dog->getType() << std::endl;
		dog->makeSound();
		std::cout << "Type: " << cat->getType() << std::endl;
		cat->makeSound();
		std::cout << "===============================" << std::endl;
		delete cat;
		cat = NULL;
		delete dog;
		dog = NULL;
	}
	std::cout << std::endl;
	{
		Animal* dog = new Dog();
		Animal* cat = new Cat();

		std::cout << "========= TEST - BRAIN =========" << std::endl;
		dog->addIdea("Sleep");
		dog->addIdea("Eat");
		dog->addIdea("Run");
		cat->addIdea("Eat");
		cat->addIdea("Play");
		std::cout << "Dog ideas: " << std::endl;
		dog->printIdeas();
		std::cout << "Cat ideas: " << std::endl;
		cat->printIdeas();
		std::cout << "================================" << std::endl;
		delete cat;
		cat = NULL;
		delete dog;
		dog = NULL;
	}
	std::cout << std::endl;
	{
		Animal* cat = new Cat();
		Animal* cat_copy = new Cat();
		Dog dog;
		Dog dog_copy;

		std::cout << "===== TEST - DEEP COPY (ASSIGNMENT) =====" << std::endl;
		cat->addIdea("Sleep");
		cat->addIdea("Play");
		*cat_copy = *cat;
		cat->addIdea("Run");
		std::cout << "Cat ideas: " << std::endl;
		cat->printIdeas();
		delete cat;
		cat = NULL;
		std::cout << "Cat copy ideas: " << std::endl;
		cat_copy->printIdeas();
		std::cout << "---------" << std::endl;
		dog.addIdea("Eat");
		dog.addIdea("Play");
		dog_copy.~Dog();
		dog_copy = dog;
		dog.addIdea("Sleep");
		std::cout << "Dog ideas: " << dog.getBrain() << std::endl;
		dog.printIdeas();
		std::cout << "Dog copy ideas: " << dog_copy.getBrain() << std::endl;
		dog_copy.printIdeas();
		std::cout << "=========================================" << std::endl;
		delete cat_copy;
		cat_copy = NULL;
	}
	std::cout << std::endl;
	{
		Cat* cat;
		Cat* cat_copy;
		Dog dog;

		cat = new Cat();
		std::cout << "===== TEST - DEEP COPY (COPY CONSTRUCTOR) =====" << std::endl;
		cat->addIdea("Sleep");
		cat_copy = new Cat(*cat);
		cat->addIdea("Play");
		cat->addIdea("Run");
		std::cout << "Cat ideas: " << std::endl;
		cat->printIdeas();
		std::cout << "Cat copy ideas: " << std::endl;
		cat_copy->printIdeas();
		std::cout << "---------" << std::endl;
		dog.addIdea("Eat");
		Dog dog_copy(dog);
		dog.addIdea("Play");
		dog.addIdea("Sleep");
		std::cout << "Dog ideas: " << std::endl;
		dog.printIdeas();
		std::cout << "Dog copy ideas: " << std::endl;
		dog_copy.printIdeas();
		std::cout << "===============================================" << std::endl;
		delete cat;
		delete cat_copy;
	}
	std::cout << std::endl;
	{
		const int	animal_size = 4;
		Animal* animal[animal_size];

		std::cout << "===== TEST - ARRAY OF ANIMAL =====" << std::endl;
		for (size_t i = 0; i < animal_size; i++)
		{
			if (i % 2)
				animal[i] = new Cat();
			else
				animal[i] = new Dog();
		}
		std::cout << animal[0]->getType() << " " << animal[0] << std::endl;
		animal[0]->addIdea("Sleep");
		animal[0]->addIdea("Eat");
		animal[0]->printIdeas();
		std::cout << "---------" << std::endl;
		*(animal[1]) = *(animal[0]);
		std::cout << animal[1]->getType() << " " << animal[1] << std::endl;
		animal[1]->printIdeas();
		std::cout << "==================================" << std::endl;
		for (size_t i = 0; i < animal_size; i++)
		{
			delete animal[i];
			animal[i] = NULL;
		}
	}
	return (0);
}
