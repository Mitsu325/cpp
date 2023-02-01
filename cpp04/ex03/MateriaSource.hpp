/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 13:46:26 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/31 20:03:07 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef MATERIA_SOURCE_H
# define MATERIA_SOURCE_H

# include "IMateriaSource.hpp"
# define TEMPLATE_SIZE 4

class MateriaSource: public IMateriaSource
{
	private:
		AMateria*	_materia_template[TEMPLATE_SIZE];

	public:
		MateriaSource(void);
		MateriaSource(MateriaSource const &obj);
		~MateriaSource(void);
		MateriaSource&	operator=(MateriaSource const &obj);

		void		learnMateria(AMateria* materia);
		AMateria*	createMateria(std::string const & type);
};

#endif
