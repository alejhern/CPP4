/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:28:12 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/19 14:28:29 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

// Ice Constructor
Ice::Ice(void) : AMateria("ice")
{
}

// Ice Copy Constructor
Ice::Ice(const Ice &other) : AMateria(other)
{
}

// Ice Destructor
Ice::~Ice(void)
{
}

// Ice Assignment Operator
Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		AMateria::operator=(other);
	}
	return (*this);
}

// Clone method
AMateria *Ice::clone(void) const
{
	return (new Ice(*this));
}

// Use method
void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
