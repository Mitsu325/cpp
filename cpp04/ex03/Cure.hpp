/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:04:41 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/31 19:09:44 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure(void);
		Cure(std::string const & type);
		Cure(Cure const &obj);
		~Cure(void);
		Cure&	operator=(Cure const &obj);

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

std::ostream&	operator<<(std::ostream &stream, Cure const &obj);

#endif
