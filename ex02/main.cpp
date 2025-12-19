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
	const Animal	*dog = new Dog();
	const Animal	*cat = new Cat();
    
	std::cout << std::endl;
	std::cout << dog->get_type() << " " << std::endl;
	dog->make_sound();
	std::cout << cat->get_type() << " " << std::endl;
	cat->make_sound();
	std::cout << std::endl;

	Brain *dog_brain = dog->get_brain();
	Brain *cat_brain = cat->get_brain();

	dog_brain->set_idea(0, "Chasing cats");
	cat_brain->set_idea(0, "Chasing mice");

	std::cout << "Dog's first idea: " << dog_brain->get_idea(0) << std::endl;
	std::cout << "Cat's first idea: " << cat_brain->get_idea(0) << std::endl;

	std::cout << "Deep copy test:" << std::endl;
	Animal *another_dog = new Dog();
	Brain *another_dog_brain = another_dog->get_brain();
	std::cout << "Another Dog's first idea (before copy): " << another_dog_brain->get_idea(0) << std::endl;
	*another_dog_brain = *dog_brain; // Using Brain's assignment operator
	std::cout << "Another Dog's first idea (after copy): " << another_dog_brain->get_idea(0) << std::endl;

	
	std::cout << std::endl;
	
	Dog *c_dog(new Dog(*static_cast<const Dog *>(dog)));
	Brain *c_dog_brain = c_dog->get_brain();
	std::cout << "c_dog's first idea (before modification): " << c_dog_brain->get_idea(0) << std::endl;
	c_dog_brain->set_idea(0, "Playing fetch");
	std::cout << "c_dog's first idea (after modification): " << c_dog_brain->get_idea(0) << std::endl;
	std::cout << "Original dog's first idea (should be unchanged): " << dog_brain->get_idea(0) << std::endl;

	std::cout << std::endl;

	delete			dog;
	delete			cat;
	delete 			another_dog;
	delete			c_dog;
	return (0);
}
