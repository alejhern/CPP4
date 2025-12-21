/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:37:01 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/21 18:37:18 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongCat::WrongCat(void): WrongAnimal("WrongCat")
{
    std::cout << "WrongCat default constructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other): WrongAnimal(other)
{
    std::cout << "WrongCat copy constructor called" << std::endl;
    *this = other;
}

WrongCat::~WrongCat(void)
{
    std::cout << "WrongCat destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=(const WrongCat &other)
{
    if (this != &other)
        WrongAnimal::operator=(other);
    std::cout << "WrongCat assignment operator called" << std::endl;
    return (*this);
}

void	WrongCat::makeSound(void) const
{
    std::cout << "Woff Woff" << std::endl;
}
