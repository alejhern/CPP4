/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:35:30 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/21 18:35:32 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : _type("WrongAnimal")
{
    std::cout << "WrongAnimal default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string &type) : _type(type)
{
    std::cout << "WrongAnimal parameterized constructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : _type(other._type)
{
    std::cout << "WrongAnimal copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
    std::cout << "WrongAnimal destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=(const WrongAnimal &other)
{
    if (this != &other)
        this->_type = other._type;
    std::cout << "WrongAnimal assignment operator called" << std::endl;
    return (*this);
}

std::string	WrongAnimal::getType(void) const
{
    return (this->_type);
}

void	WrongAnimal::makeSound(void) const
{
    std::cout << "WrongAnimal makes a sound!" << std::endl;
}
