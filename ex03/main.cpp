/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 14:33:46 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/19 14:33:48 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "AMateria.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include "ICharacter.hpp"
#include "colors.h"
#include <iostream>

#define LINE CYN << "════════════════════════════════════════════════════════════" << RST

void banner(const std::string &title)
{
	std::cout << "\n" << LINE << std::endl;
	std::cout << BOLD << MAG << "💥 " << title << " 💥" << RST << std::endl;
	std::cout << LINE << "\n" << std::endl;
}

int main(void)
{
	std::cout << BOLD << RED;
	std::cout <<
	"███╗   ███╗ █████╗ ████████╗███████╗██████╗ ██╗ █████╗ \n"
	"████╗ ████║██╔══██╗╚══██╔══╝██╔════╝██╔══██╗██║██╔══██╗\n"
	"██╔████╔██║███████║   ██║   █████╗  ██████╔╝██║███████║\n"
	"██║╚██╔╝██║██╔══██║   ██║   ██╔══╝  ██╔══██╗██║██╔══██║\n"
	"██║ ╚═╝ ██║██║  ██║   ██║   ███████╗██║  ██║██║██║  ██║\n"
	"╚═╝     ╚═╝╚═╝  ╚═╝   ╚═╝   ╚══════╝╚═╝  ╚═╝╚═╝╚═╝  ╚═╝\n";
	std::cout << RST << std::endl;

	std::cout << BOLD << YEL << "🧙‍♂️ CPP04 - EX03 | MATERIA SYSTEM: FINAL BOSS TEST\n" << RST;

	/* ===================================================== */
	banner("📦 MATERIA SOURCE BOOT SEQUENCE");

	IMateriaSource *src = new MateriaSource();

	std::cout << GRN << "➕ Learning ICE" << RST << std::endl;
	src->learnMateria(new Ice());

	std::cout << GRN << "➕ Learning CURE" << RST << std::endl;
	src->learnMateria(new Cure());

	std::cout << GRN << "➕ Learning ICE (again)" << RST << std::endl;
	src->learnMateria(new Ice());

	std::cout << GRN << "➕ Learning CURE (again)" << RST << std::endl;
	src->learnMateria(new Cure());

	std::cout << RED << "💀 Attempting forbidden 5th materia..." << RST << std::endl;
	src->learnMateria(new Cure());

	/* ===================================================== */
	banner("🧬 CHARACTER CLONING EXPERIMENT");

	Character *alice = new Character("Alice");
	std::cout << BLU << "🧪 Cloning Alice..." << RST << std::endl;

	ICharacter *clone = new Character(*alice);

	std::cout << GRN << "✅ Clone created" << RST << std::endl;
	delete alice;
	delete clone;

	/* ===================================================== */
	banner("🎒 EQUIP PHASE – LOADOUT MADNESS");

	ICharacter *me = new Character("Neo");

	AMateria *tmp;

	std::cout << CYN << "⚙️ Creating ICE materia" << RST << std::endl;
	tmp = src->createMateria("ice");
	me->equip(tmp);

	std::cout << CYN << "⚙️ Creating CURE materia" << RST << std::endl;
	tmp = src->createMateria("cure");
	me->equip(tmp);

	std::cout << RED << "❓ Summoning UNKNOWN materia [hi]" << RST << std::endl;
	tmp = src->createMateria("hi");
	me->equip(tmp);

	std::cout << YEL << "⚠️ Forcing equip overflow..." << RST << std::endl;
	me->equip(new Cure());
	me->equip(new Ice());
	me->equip(new Ice());

	/* ===================================================== */
	banner("🧤 UNEQUIP CHAOS TEST");

	std::cout << MAG << "🧤 Unequip slot 2" << RST << std::endl;
	me->unequip(2);

	std::cout << MAG << "🧤 Unequip slot 2 again (ghost slot)" << RST << std::endl;
	me->unequip(2);

	std::cout << RED << "💣 Unequip slot 6 (out of bounds)" << RST << std::endl;
	me->unequip(6);

	std::cout << RED << "💣 Unequip slot -1 (illegal)" << RST << std::endl;
	me->unequip(-1);

	/* ===================================================== */
	banner("⚔️ COMBAT SIMULATION");

	ICharacter *bob = new Character("Bob");

	std::cout << GRN << "🎯 Valid attacks" << RST << std::endl;
	me->use(0, *bob);
	me->use(1, *bob);

	std::cout << RED << "🚫 Invalid attacks" << RST << std::endl;
	me->use(2, *bob);
	me->use(6, *bob);
	me->use(-42, *bob);

	/* ===================================================== */
	banner("🧹 MEMORY PURGE");

	delete bob;
	delete me;
	delete src;

	std::cout << BOLD << GRN << "🏁 ALL TESTS COMPLETE — NO SURVIVORS\n" << RST;
	std::cout << DIM << "Run Valgrind to confirm absolute dominance.\n" << RST;

	return 0;
}
