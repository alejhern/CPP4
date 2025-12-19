/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:26:49 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/19 14:52:02 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>

// Character Constructor
Character::Character(std::string const &name) : _name(name)
{
	int	i;

	i = -1;
	while (++i < 4)
		_inventory[i] = NULL;
}

// Character Copy Constructor
Character::Character(const Character &other)
{
    int i;

    i = -1;
    while (++i < 4)
        this->_inventory[i] = NULL;
    *this = other;
}

// Character Destructor
Character::~Character()
{
	int	i;
    
	i = -1;
	while (++i < 4)
	{
        if (_inventory[i])
            delete _inventory[i];
	}
}

// Character Assignment Operator
Character &Character::operator=(const Character &other)
{
	int	i;

    if (this != &other)
    {
        this->_name = other._name;
        i = -1;
        while (++i < 4)
        {
            if (this->_inventory[i])
                delete this->_inventory[i];
            if (other._inventory[i])
                this->_inventory[i] = other._inventory[i]->clone();
            else
                this->_inventory[i] = NULL;
        }
    }
    return (*this);
}

// Returns the character's name
std::string const &Character::getName() const
{
	return (_name);
}

// Equip materia
void Character::equip(AMateria *m)
{
	int		i;

	if (!m)
		return ;
	i = -1;
	while (++i < 4)
	{
        if (!_inventory[i])
        {
            _inventory[i] = m;
            return ;
        }
	}
    std::cout << "Inventory full, cannot equip materia of type: " << m->getType() << std::endl;
    delete m;
}

// Unequip materia
void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
        return ;
    if (_inventory[idx])
	{
        delete _inventory[idx];
		_inventory[idx] = NULL;
	}
}

// Use materia
void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
		return ;
	if (_inventory[idx])
		_inventory[idx]->use(target);
}
