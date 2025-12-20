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
#include "colors.h"
#include <iostream>

/* ===================================================== */
/* 🧪 Constructor */
AMateria::AMateria(std::string const &type) : _type(type)
{
	std::cout << BOLD << GRN << "✨ [AMateria] Summoned materia of type → " << CYN << _type << GRN << " ✨" << RST << std::endl;
}

/* ===================================================== */
/* 🧬 Copy constructor */
AMateria::AMateria(const AMateria &other) : _type(other._type)
{
	std::cout << BOLD << BLU << "🧬 [AMateria] Cloning materia → " << CYN << _type << BLU << " 🧬" << RST << std::endl;
}

/* ===================================================== */
/* ☠️ Destructor */
AMateria::~AMateria(void)
{
	std::cout << DIM << RED << "💀 [AMateria] Materia of type " << _type << " has been annihilated." << RST << std::endl;
}

/* ===================================================== */
/* 🔁 Assignment operator */
AMateria &AMateria::operator=(const AMateria &other)
{
	std::cout << YEL << "🔁 [AMateria] Assignment operator invoked" << RST << std::endl;
	if (this != &other)
	{
		_type = other._type;
		std::cout << GRN << "✔ [AMateria] Type overwritten → " << CYN << _type << RST << std::endl;
	}
	else
		std::cout << DIM << MAG << "⚠️ [AMateria] Self-assignment detected, skipping." << RST << std::endl;
	return (*this);
}

/* ===================================================== */
/* 📖 getType */
std::string const &AMateria::getType(void) const
{
	return (_type);
}

/* ===================================================== */
/* ⚔️ Use */
void AMateria::use(ICharacter &target)
{
	std::cout << BOLD << MAG << "⚔️  [AMateria] " << CYN << _type << MAG << " unleashed on " << YEL << target.getName() << MAG << "!" << RST << std::endl;
}
