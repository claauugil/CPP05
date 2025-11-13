/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/13 11:20:00 by claudia           #+#    #+#             */
/*   Updated: 2025/11/13 11:20:00 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "Intern.hpp"

#include <iostream>
#include "Intern.hpp"

int main()
{
    Intern intern;
    std::cout << YELLOW << "--- Creating ShrubberyCreationForm ---" << RESET << std::endl;
    AForm* form1 = intern.makeForm("shrubbery creation", "Home");
    std::cout << YELLOW << "\n--- Creating RobotomyRequestForm ---" << RESET << std::endl;
    AForm* form2 = intern.makeForm("robotomy request", "Bender");
    std::cout << YELLOW << "\n--- Creating PresidentialPardonForm ---" << RESET << std::endl;
    AForm* form3 = intern.makeForm("presidential pardon", "Marvin");
    std::cout << YELLOW << "\n--- Trying to create unknown form ---" << RESET << std::endl;
    AForm* form4 = intern.makeForm("unknown form", "Nobody");

    delete form1;
    delete form2;
    delete form3;
    delete form4;

    return 0;
}
