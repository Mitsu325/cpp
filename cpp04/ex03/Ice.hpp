/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmitsuko <pmitsuko@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:41:31 by pmitsuko          #+#    #+#             */
/*   Updated: 2023/01/31 19:10:14 by pmitsuko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice(void);
		Ice(std::string const & type);
		Ice(Ice const &obj);
		~Ice(void);
		Ice&	operator=(Ice const &obj);

		AMateria*	clone(void) const;
		void		use(ICharacter& target);
};

std::ostream&	operator<<(std::ostream &stream, Ice const &obj);

#endif
