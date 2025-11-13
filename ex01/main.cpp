/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgil <cgil@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 11:11:22 by claudia           #+#    #+#             */
/*   Updated: 2025/11/13 15:13:22 by cgil             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
    std::cout << GREEN << "=== Creating Bureaucrats ===" << RESET << std::endl;
    Bureaucrat charlie("Charlie", 5);
    Bureaucrat diana("Diana", 10);
    std::cout << charlie << std::endl;
    std::cout << diana << std::endl;

    std::cout << GREEN << "=== Creating Forms ===" << RESET << std::endl;
    Form secretForm("SecretForm", 50, 30);
    std::cout << secretForm;

    try
    {
        std::cout << YELLOW << "\n=== Charlie tries to sign the form ===" << RESET << std::endl;
        charlie.signForm(secretForm);
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Exception caught: " << e.what() << RESET << std::endl;
        std::cerr << "State of isSigned: ";
        if (secretForm.getIsSigned())
            std::cerr << "true";
        else
            std::cerr << "false";
        std::cerr << std::endl;
    }
    try
    {
        std::cout << YELLOW << "=== Diana tries to sign the form ===" << RESET << std::endl;
        diana.signForm(secretForm);
    }
    catch (std::exception &e)
    {
        std::cerr << RED << "Exception caught: " << e.what() << RESET;
    }
    std::cout << GREEN << "=== Final state of the form ===" << RESET << std::endl;
    std::cout << secretForm << std::endl;
    return 0;
}
