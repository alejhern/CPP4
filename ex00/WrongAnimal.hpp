/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/21 18:34:11 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/21 18:34:15 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
    protected:
        std::string	_type;

    public:
        WrongAnimal(void);
        WrongAnimal(const std::string &type);
        WrongAnimal(const WrongAnimal &other);
        virtual ~WrongAnimal(void);

        WrongAnimal	&operator=(const WrongAnimal &other);

        std::string	getType(void) const;
        void		makeSound(void) const;
};

class WrongCat : public WrongAnimal
{
    public:
        WrongCat(void);
        WrongCat(const WrongCat &other);
        ~WrongCat(void);

        WrongCat	&operator=(const WrongCat &other);

        void		makeSound(void) const;
};

#endif