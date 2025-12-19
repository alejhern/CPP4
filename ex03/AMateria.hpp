/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:03:47 by alejhern          #+#    #+#             */
/*   Updated: 2025/12/18 13:03:53 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef AMATERIA_HPP
# define AMATERIA_HPP

# include <string>

class ICharacter;

class AMateria
{
  protected:
	std::string _type;

  public:
	AMateria(std::string const &type);
	AMateria(const AMateria &other);
	virtual ~AMateria(void);
	AMateria &operator=(const AMateria &other);
	int operator==(const AMateria &other);
	std::string const &getType() const;
	virtual AMateria *clone() const = 0;
	virtual void use(ICharacter &target);
};

class Ice : public AMateria
{
  public:
	Ice(void);
	Ice(const Ice &other);
	virtual ~Ice(void);
	Ice &operator=(const Ice &other);
	virtual AMateria *clone(void) const;
	virtual void use(ICharacter &target);
};

class Cure : public AMateria
{
  public:
	Cure(void);
	Cure(const Cure &other);
	virtual ~Cure(void);
	Cure &operator=(const Cure &other);
	virtual AMateria *clone(void) const;
	virtual void use(ICharacter &target);
};

#endif