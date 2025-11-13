/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:11:22 by claudia           #+#    #+#             */
/*   Updated: 2025/11/13 15:23:07 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
    srand(time(NULL));

    std::cout << GREEN << "=== Creating Bureaucrats ===" << RESET << std::endl;
    Bureaucrat charlie("Charlie", 100);
    Bureaucrat diana("Diana", 5);
    std::cout << charlie << std::endl;
    std::cout << diana << std::endl;

    std::cout << GREEN << "=== Creating Forms ===" << RESET << std::endl;
    ShrubberyCreationForm shrub("home");
    RobotomyRequestForm robot("Bender");
    PresidentialPardonForm pardon("Marvin");

    std::cout << shrub << robot << pardon;

    try {
        std::cout << YELLOW << "=== Charlie tries to sign Shrubbery ===" << RESET << std::endl;
        charlie.signForm(shrub);
    } catch (std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << YELLOW << "=== Diana tries to sign Robotomy ===" << RESET << std::endl;
        diana.signForm(robot);
    } catch (std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << YELLOW << "=== Diana tries to sign Pardon ===" << RESET << std::endl;
        diana.signForm(pardon);
    } catch (std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "=== Executing Forms ===" << RESET << std::endl;

    try {
        std::cout << YELLOW << "--- Charlie executes Shrubbery ---" << RESET << std::endl;
        charlie.executeForm(shrub);
    } catch (std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << YELLOW << "--- Diana executes Robotomy ---" << RESET << std::endl;
        diana.executeForm(robot);
    } catch (std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    try {
        std::cout << YELLOW << "--- Diana executes Pardon ---" << RESET << std::endl;
        diana.executeForm(pardon);
    } catch (std::exception &e) {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
    }

    std::cout << GREEN << "=== Final state of the forms ===" << RESET << std::endl;
    std::cout << shrub << robot << pardon;

    return 0;
}

