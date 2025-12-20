/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:22:39 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/19 15:09:30 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include "colors.h"
#include <iostream>

/* 🧪 Constructor */
MateriaSource::MateriaSource()
{
	int	i;

	i = -1;
	while (++i < 4)
		_materias[i] = NULL;
	std::cout << BOLD << GRN << "📦 [MateriaSource] Initialized and ready" << RST << std::endl;
}

/* ===================================================== */
/* 🧬 Copy Constructor */
MateriaSource::MateriaSource(const MateriaSource &other)
{
	int	i;

	i = -1;
	while (++i < 4)
		_materias[i] = NULL;
	*this = other;
	std::cout << BOLD << BLU << "🧬 [MateriaSource] Clone created" << RST << std::endl;
}

/* ===================================================== */
/* ☠️ Destructor */
MateriaSource::~MateriaSource()
{
	int	i;
	
	i = -1;
	while (++i < 4)
	{
		if (_materias[i])
		{
			std::cout << DIM << RED << "💀 [MateriaSource] Destroying materia → " << _materias[i]->getType() << RST << std::endl;
			delete _materias[i];
		}
	}
	std::cout << BOLD << RED << "☠️  [MateriaSource] Shutdown complete" << RST << std::endl;
}

/* ===================================================== */
/* 🔁 Assignment Operator */
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	int	i;
	
	if (this == &other)
	{
		std::cout << DIM << MAG << "⚠️ [MateriaSource] Self-assignment ignored" << RST << std::endl;
		return (*this);
	}
	std::cout << YEL << "🔁 [MateriaSource] Overwriting stored materias" << RST << std::endl;
	i = -1;
	while (++i < 4)
	{
		if (_materias[i])
			delete _materias[i];
		if (other._materias[i])
		{
			_materias[i] = other._materias[i]->clone();
			std::cout << GRN << "✔ Cloned materia [" << _materias[i]->getType() << "] into slot " << i << RST << std::endl;
		}
		else
			_materias[i] = NULL;
	}
	return (*this);
}

/* ===================================================== */
/* 📚 Learn Materia */
void MateriaSource::learnMateria(AMateria *m)
{
	int		i;
	
	if (!m)
	{
		std::cout << DIM << MAG << "⚠️ [MateriaSource] Cannot learn NULL materia" << RST << std::endl;
		return ;
	}
	i = -1;
	while (++i < 4)
	{
		if (!_materias[i])
		{
			_materias[i] = m;
			std::cout << BOLD << GRN << "📘 [MateriaSource] Learned " << CYN << m->getType() << GRN << " in slot " << i << RST << std::endl;
			return ;
		}
	}
	std::cout << BOLD << RED << "🚫 [MateriaSource] Storage FULL — rejected " << YEL << m->getType() << RST << std::endl;
	delete	m;
}

/* ===================================================== */
/* 🧪 Create Materia */
AMateria *MateriaSource::createMateria(std::string const &type)
{
	int i;

	i = -1;
	while (++i < 4)
	{
		if (_materias[i] && _materias[i]->getType() == type)
		{
			std::cout << BOLD << CYN << "🧪 [MateriaSource] Creating materia → " << YEL << type << RST << std::endl;
			return (_materias[i]->clone());
		}
	}
	std::cout << BOLD << RED << "❌ [MateriaSource] Materia type not found → " << YEL << type << RST << std::endl;
	return (NULL);
}
