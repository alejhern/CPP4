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
#include "colors.h"
#include <iostream>

/* ===================================================== */
/* 🧙 Constructor */
Character::Character(std::string const &name) : _name(name)
{
	int	i;

	i = -1;
	while (++i < 4)
		_inventory[i] = NULL;
	std::cout << BOLD << GRN << "🧙 [Character] " << CYN << _name << GRN << " has entered the realm ✨" << RST << std::endl;
}

/* ===================================================== */
/* 🧬 Copy Constructor */
Character::Character(const Character &other)
{
	int	i;

	i = -1;
	while (++i < 4)
		_inventory[i] = NULL;
	*this = other;
	std::cout << BOLD << BLU << "🧬 [Character] Clone created from " << CYN << other._name << BLU << " 🧬" << RST << std::endl;
}

/* ===================================================== */
/* ☠️ Destructor */
Character::~Character()
{
	int	i;

	i = -1;
	while (++i < 4)
	{
        if (_inventory[i])
		{
            std::cout << DIM << RED << "💀 [Character] Destroying materia → " << _inventory[i]->getType() << RST << std::endl;
            delete _inventory[i];
		}
	}
	std::cout << BOLD << RED << "☠️  [Character] " << _name << " has fallen." << RST << std::endl;
}

/* ===================================================== */
/* 🔁 Assignment Operator */
Character &Character::operator=(const Character &other)
{
	int	i;
    
	if (this == &other)
	{
        std::cout << DIM << MAG << "⚠️ [Character] Self-assignment detected. Ignored." << RST << std::endl;
		return (*this);
	}
	std::cout << YEL << "🔁 [Character] Overwriting " << CYN << _name << YEL << " with " << CYN << other._name << RST << std::endl;
	_name = other._name;
	i = -1;
	while (++i < 4)
	{
        if (_inventory[i])
            delete _inventory[i];
		if (other._inventory[i])
		{
			_inventory[i] = other._inventory[i]->clone();
			std::cout << GRN << "✔ Cloned " << _inventory[i]->getType() << " into slot " << i << RST << std::endl;
		}
		else
			_inventory[i] = NULL;
	}
	return (*this);
}

/* ===================================================== */
/* 📛 getName */
std::string const &Character::getName() const
{
	return (_name);
}

/* ===================================================== */
/* 🎒 Equip */
void Character::equip(AMateria *m)
{
	int		i;
    
	if (!m)
	{
        std::cout << DIM << MAG << "⚠️ [Character] Tried to equip NULL materia." << RST << std::endl;
		return ;
	}
	i = -1;
	while (++i < 4)
	{
        if (!_inventory[i])
		{
            _inventory[i] = m;
			std::cout << BOLD << GRN << "🎒 [Character] " << CYN << _name << GRN << " equipped " << YEL << m->getType() << GRN << " in slot " << i << RST << std::endl;
			return ;
		}
	}
	std::cout << BOLD << RED << "🚫 [Character] Inventory FULL — cannot equip " << YEL << m->getType() << RST << std::endl;
    delete	m;
}

/* ===================================================== */
/* 🧤 Unequip */
void Character::unequip(int idx)
{
    if (idx < 0 || idx >= 4)
	{
        std::cout << RED << "💣 [Character] Invalid unequip slot → " << idx << RST << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
        std::cout << DIM << MAG << "🕳️ [Character] Slot " << idx << " already empty." << RST << std::endl;
		return ;
	}
	std::cout << YEL << "🧤 [Character] Unequipped " << _inventory[idx]->getType() << " from slot " << idx << RST << std::endl;
    delete	_inventory[idx];
	_inventory[idx] = NULL;
}

/* ===================================================== */
/* ⚔️ Use */
void Character::use(int idx, ICharacter &target)
{
	if (idx < 0 || idx >= 4)
	{
		std::cout << RED << "💥 [Character] Invalid use slot → " << idx << RST << std::endl;
		return ;
	}
	if (!_inventory[idx])
	{
		std::cout << DIM << MAG << "🚫 [Character] No materia in slot " << idx << " to use." << RST << std::endl;
		return ;
	}
	std::cout << BOLD << MAG << "⚔️  [Character] " << CYN << _name << MAG << " attacks " << YEL << target.getName() << MAG << " using " << CYN << _inventory[idx]->getType() << RST << std::endl;
	_inventory[idx]->use(target);
}
