/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:24:11 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 20:24:13 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : _type("Animal"), _brain(NULL)
{
	std::cout << "Animal default constructor called" << std::endl;
}

Animal::Animal(const Animal &other) : _type(other._type)
{
	std::cout << "Animal copy constructor called" << std::endl;
	if (other._brain)
		_brain = new Brain(*(other._brain));
	else
		_brain = NULL;
}

Animal::~Animal(void)
{
	delete _brain;
	std::cout << "Animal destructor called" << std::endl;
}

Animal::Animal(const string &type) : _type(type), _brain(NULL)
{
	std::cout << "Animal parameterized constructor called" << std::endl;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal assignment operator called" << std::endl;
	if (this != &other)
	{
		this->_type = other._type;
		if (this->_brain)
			delete this->_brain;
		if (other._brain)
			this->_brain = new Brain(*(other._brain));
		else
			this->_brain = NULL;
	}
	return (*this);
}

const string Animal::get_type() const
{
	return (this->_type);
}

Brain *Animal::get_brain(void) const
{
	return (this->_brain);
}
