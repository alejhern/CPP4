/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 21:03:16 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 21:03:18 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
    std::cout << "Brain default constructor called" <<  std::endl;
    for (size_t i = 0; i < NUM_IDEAS; i++)
    {
        _ideas[i] = "Empty idea";
    }
}

Brain::Brain(const Brain &other)
{
    std::cout << "Brain copy constructor called" <<  std::endl;
    *this = other;
}

Brain::~Brain(void)
{
    std::cout << "Brain destructor called" <<  std::endl;
}

Brain &Brain::operator=(const Brain &other)
{
    std::cout << "Brain assignment operator called" <<  std::endl;
    if (this != &other)
    {
        for (size_t i = 0; i < NUM_IDEAS; i++)
        {
            this->_ideas[i] = other._ideas[i];
        }
    }
    return (*this);
}

void Brain::set_idea(size_t index, const string &idea)
{
    if (index < NUM_IDEAS)
    {
        _ideas[index] = idea;
    }
}

const string &Brain::get_idea(size_t index) const
{
    if (index < NUM_IDEAS)
    {
        return (_ideas[index]);
    }
    static const string empty = "";
    return (empty);
}
