/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:31:09 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 20:31:11 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

int	main(void)
{
	const Animal	*meta = new Animal();
	const Dog		*dog = new Dog();
	const Cat		*cat = new Cat();
    
	std::cout << std::endl;
	std::cout << dog->get_type() << " " << std::endl;
	dog->make_sound();
	std::cout << cat->get_type() << " " << std::endl;
	cat->make_sound();
	std::cout << meta->get_type() << " " << std::endl;
	meta->make_sound();
	std::cout << std::endl;
	delete			meta;
	delete			dog;
	delete			cat;
	return (0);
}
