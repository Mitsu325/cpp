/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/22 20:38:19 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/31 22:26:13 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"

int main(void)
{
	{
		std::cout << "========= MATERIA SOURCE =========" << std::endl;
		IMateriaSource*	src = new MateriaSource();
		std::cout << std::endl;

		std::cout << "========= LEARN MATERIA ==========" << std::endl;
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << std::endl;

		std::cout << "========== CHARACTER ME ==========" << std::endl;
		ICharacter*	me = new Character("me");
		std::cout << std::endl;

		std::cout << "========= CREATE MATERIA =========" << std::endl;
		AMateria*	tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("fire");
		me->equip(tmp);
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		delete tmp;
		std::cout << std::endl;

		std::cout << "========== CHARACTER BOB =========" << std::endl;
		ICharacter*	bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(2, *bob);
		me->use(3, *bob);
		me->use(-42, *bob);
		me->use(21, *bob);
		std::cout << std::endl;

		std::cout << "======= DEEP COPY CHARACTER ======" << std::endl;
		Character*	meg = new Character("meg");
		tmp = src->createMateria("ice");
		meg->equip(tmp);
		tmp = src->createMateria("cure");
		meg->equip(tmp);
		Character*	meg_copy = new Character(*meg);
		std::cout << "--------" << std::endl;
		meg->use(0, *bob);
		meg->use(1, *bob);
		meg->use(2, *bob);
		meg->use(3, *bob);
		std::cout << "--------" << std::endl;

		AMateria*	tmp2;
		tmp2 = meg_copy->getMateria(1);
		meg_copy->unequip(1);
		delete tmp2;
		tmp = src->createMateria("ice");
		meg_copy->equip(tmp);
		tmp = src->createMateria("ice");
		meg_copy->equip(tmp);

		std::cout << "---- MEG ----" << std::endl;
		meg->use(0, *bob);
		meg->use(1, *bob);
		meg->use(2, *bob);
		meg->use(3, *bob);
		std::cout << "---- MEG COPY ----" << std::endl;
		meg_copy->use(0, *bob);
		meg_copy->use(1, *bob);
		meg_copy->use(2, *bob);
		meg_copy->use(3, *bob);
		std::cout << "--------" << std::endl;

		*meg_copy = *meg;
		tmp = src->createMateria("cure");
		meg_copy->equip(tmp);
		std::cout << "---- MEG ----" << std::endl;
		meg->use(0, *bob);
		meg->use(1, *bob);
		meg->use(2, *bob);
		meg->use(3, *bob);
		std::cout << "---- MEG COPY ----" << std::endl;
		meg_copy->use(0, *bob);
		meg_copy->use(1, *bob);
		meg_copy->use(2, *bob);
		meg_copy->use(3, *bob);
		std::cout << "--------" << std::endl;
		std::cout << std::endl;

		std::cout << "============= UNEQUIP ============" << std::endl;
		meg->use(1, *meg_copy);
		tmp2 = meg->getMateria(1);
		meg->unequip(1);
		delete tmp2;
		meg->use(1, *meg_copy);
		meg->unequip(-4);
		meg->unequip(42);
		meg->unequip(1);

		std::cout << std::endl;

		std::cout << "============= DELETE =============" << std::endl;
		delete meg_copy;
		delete meg;
		delete bob;
		delete me;
		delete src;
		std::cout << "==================================" << std::endl;
	}
	return (0);
}
