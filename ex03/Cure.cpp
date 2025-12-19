/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:30:57 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/19 14:30:59 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

// Cure Constructor
Cure::Cure() : AMateria("cure")
{
}

// Cure Copy Constructor
Cure::Cure(const Cure &other) : AMateria(other)
{
}
// Cure Destructor
Cure::~Cure()
{
}

// Cure Assignment Operator
Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

// Clone method
AMateria *Cure::clone() const
{
	return (new Cure(*this));
}

// Use method
void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}
