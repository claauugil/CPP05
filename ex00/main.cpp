/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:11:22 by claudia           #+#    #+#             */
/*   Updated: 2025/11/06 12:51:06 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{   
    try
    {
        std::cout << YELLOW << "Test 1: Increment grade beyond the upper limit" << RESET << std::endl;
        Bureaucrat b1("Alice", 2);
        std::cout << b1;
        b1.incrementGrade();
        std::cout << b1;
        b1.incrementGrade();
        std::cout << b1;
    }
    catch(std::exception &e)
    {
        std::cerr << RED <<"Exception caught: " << e.what() << RESET << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    try
    {
        std::cout << YELLOW << "Test 2: Create bureaucrat with too low grade" << RESET << std::endl;
        Bureaucrat b2("Bob", 151);
        std::cout << b2;
    }
    catch(std::exception &e)
    {
        std::cerr << RED <<"Exception caught: " << e.what() << RESET << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    try
    {
        std::cout << YELLOW << "Test 3: Decrement grade beyond the lower limit" << RESET << std::endl;
        Bureaucrat b3("Charlie", 150);
        std::cout << b3;
        std::cout << "Try to decrement grade" << std::endl;
        b3.decrementGrade();
        std::cout << b3;
    }
    catch(std::exception &e)
    {
        std::cerr << RED <<"Exception caught: " << e.what() << RESET << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
    try
    {
        std::cout << YELLOW << "Test 4: Valid bureaucrat grade changes" << RESET << std::endl;
        Bureaucrat b4("Diana", 75);
        b4.incrementGrade();
        std::cout << b4;
        b4.decrementGrade();
        std::cout << b4;
    }
    catch(std::exception &e)
    {
        std::cerr << RED <<"Exception caught: " << e.what() << RESET << std::endl;
    }
    std::cout << "------------------------------------" << std::endl;
}
