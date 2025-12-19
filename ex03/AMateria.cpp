/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:24:56 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/19 14:24:58 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"
#include <iostream>

// Constructor
AMateria::AMateria(std::string const &type) : _type(type)
{
}

// Copy constructor
AMateria::AMateria(const AMateria &other) : _type(other._type)
{
}

// Destructor
AMateria::~AMateria(void)
{
}

// Assignment operator
AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		_type = other._type;
	}
	return (*this);
}

int AMateria::operator==(const AMateria &other)
{
    return (this->_type == other._type);
}

// Returns the materia type
std::string const &AMateria::getType(void) const
{
	return (_type);
}

// Use method
void AMateria::use(ICharacter &target)
{
	std::cout << "* uses " << _type << " on " << target.getName() << " *" << std::endl;
}
