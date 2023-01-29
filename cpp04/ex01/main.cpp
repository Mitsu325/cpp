/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/29 18:29:16 by pmitsuko         ###   ########.fr       */
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
		Cat cat;
		Cat cat_copy;
		Dog dog;
		Dog dog_copy;

		std::cout << "===== TEST - DEEP COPY (ASSIGNMENT) =====" << std::endl;
		cat.addIdea("Sleep");
		cat.addIdea("Play");
		cat_copy = cat;
		cat.addIdea("Run");
		std::cout << "Cat ideas: " << cat.getBrain() << std::endl;
		cat.printIdeas();
		std::cout << "Cat copy ideas: " << cat_copy.getBrain() << std::endl;
		cat_copy.printIdeas();
		std::cout << "---------" << std::endl;
		dog.addIdea("Eat");
		dog.addIdea("Play");
		dog_copy = dog;
		dog.addIdea("Sleep");
		std::cout << "Dog ideas: " << dog.getBrain() << std::endl;
		dog.printIdeas();
		std::cout << "Dog copy ideas: " << dog_copy.getBrain() << std::endl;
		dog_copy.printIdeas();
		std::cout << "=========================================" << std::endl;
	}
	std::cout << std::endl;
	{
		Cat cat;
		Dog dog;

		std::cout << "===== TEST - DEEP COPY (COPY CONSTRUCTOR) =====" << std::endl;
		cat.addIdea("Sleep");
		Cat cat_copy(cat);
		cat.addIdea("Play");
		cat.addIdea("Run");
		std::cout << "Cat ideas: " << cat.getBrain() << std::endl;
		cat.printIdeas();
		std::cout << "Cat copy ideas: " << cat_copy.getBrain() << std::endl;
		cat_copy.printIdeas();
		std::cout << "---------" << std::endl;
		dog.addIdea("Eat");
		Dog dog_copy(dog);
		dog.addIdea("Play");
		dog.addIdea("Sleep");
		std::cout << "Dog ideas: " << dog.getBrain() << std::endl;
		dog.printIdeas();
		std::cout << "Dog copy ideas: " << dog_copy.getBrain() << std::endl;
		dog_copy.printIdeas();
		std::cout << "===============================================" << std::endl;
	}
	return (0);
}
