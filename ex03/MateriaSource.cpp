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
#include <iostream>

// MateriaSource Constructor
MateriaSource::MateriaSource()
{
	int	i;

	i = -1;
	while (++i < 4)
		_materias[i] = NULL;
}

// MateriaSource Copy Constructor
MateriaSource::MateriaSource(const MateriaSource &other)
{
	*this = other;
}

// MateriaSource Destructor
MateriaSource::~MateriaSource()
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (_materias[i])
			delete _materias[i];
	}
}

// MateriaSource Assignment Operator
MateriaSource &MateriaSource::operator=(const MateriaSource &other)
{
	int	i;

	if (this != &other)
	{
		i = -1;
		while (++i < 4)
		{
			if (_materias[i])
				delete _materias[i];
			if (other._materias[i])
				_materias[i] = other._materias[i]->clone();
			else
				_materias[i] = NULL;
		}
	}
	return (*this);
}

// Learn materia method
void MateriaSource::learnMateria(AMateria *m)
{
	int		i;

	i = -1;
	while (++i < 4)
	{
		if (!_materias[i])
		{
			_materias[i] = m;
			return ;
		}
	}
	std::cout << "MateriaSource inventory full, cannot learn more materias." << std::endl;
	delete m;
}

// Create materia method
AMateria *MateriaSource::createMateria(std::string const &type)
{
	int		i;

	i = -1;
	while (++i < 4)
		if (_materias[i] && _materias[i]->getType() == type)
			return (_materias[i]->clone());
	std::cout << "Materia of type: " << type << " not found!" << std::endl;
	return (NULL);
}
