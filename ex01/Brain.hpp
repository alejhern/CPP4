/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejhern <alejhern@student.42barcelona.co  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/28 20:58:11 by alejhern          #+#    #+#             */
/*   Updated: 2025/11/28 20:58:13 by alejhern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# define NUM_IDEAS 100

# include <iostream>

typedef std::string string;

class Brain
{
private:
    string _ideas[NUM_IDEAS];

public:
    Brain();
    Brain(const Brain &other);
    ~Brain();

    Brain &operator=(const Brain &other);
    void set_idea(size_t index, const string &idea);
    const string &get_idea(size_t index) const;
};

#endif
