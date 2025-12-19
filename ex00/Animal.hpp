/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:21:32 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 20:21:34 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
typedef std::string string;

class Animal
{
  private:
	string _type;

  public:
	Animal(void);
	Animal(const string &type);
	Animal(const Animal &other);
	virtual ~Animal(void);
	Animal &operator=(const Animal &other);

	virtual void make_sound(void) const;
	const string get_type(void) const;
};

class Dog : public Animal
{
  public:
	Dog(void);
	Dog(const Dog &other);
	~Dog(void);
	Dog &operator=(const Dog &other);
	void make_sound(void) const;
};

class Cat : public Animal
{
  public:
	Cat(void);
	Cat(const Cat &other);
	~Cat(void);
	Cat &operator=(const Cat &other);
	void make_sound(void) const;
};

#endif