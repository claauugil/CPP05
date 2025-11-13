/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:29:48 by claudia           #+#    #+#             */
/*   Updated: 2025/11/13 12:35:21 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern()
{
    
}

Intern::Intern(const Intern &other)
{ 
    (void)other;
}

Intern &Intern::operator=(const Intern &other)
{
    (void)other;
    return *this;
}

Intern::~Intern()
{
    
}

AForm* createShrubbery(const std::string &target) 
{ 
    return new ShrubberyCreationForm(target);
}

AForm* createRobotomy(const std::string &target)
{ 
    return new RobotomyRequestForm(target);
}

AForm* createPardon(const std::string &target)
{
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string &formName, const std::string &target) const
{
    const std::string names[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
    AForm* (*creators[3])(const std::string&) = {createShrubbery, createRobotomy, createPardon};

    int i = 0;
    while (i < 3 && formName != names[i])
        i++;

    if (i < 3)
    {
        std::cout << "Intern creates " << formName << std::endl;
        return creators[i](target);
    }
    std::cout << "Intern couldn't create form: " << formName << " does not exist." << std::endl;
    return NULL;

}

