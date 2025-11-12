/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: claudia <claudia@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/11 13:09:26 by claudia           #+#    #+#             */
/*   Updated: 2025/11/12 19:16:39 by claudia          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToSign, int gradeToExecute) : _name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
    if (gradeToSign < 1 || gradeToExecute < 1)
        throw GradeTooHighException();
    if (gradeToSign > 150 || gradeToExecute > 150)
        throw GradeTooLowException();
}

AForm:: AForm(const AForm &other): _name(other._name), _gradeToSign(other._gradeToSign), _gradeToExecute(other._gradeToExecute)
{

}

AForm &AForm::operator=(const AForm &other)
{
    _isSigned = other._isSigned;
    return (*this);
}

AForm:: ~AForm()
{

}

std::string AForm::getName() const
{
    return (_name);
}

bool AForm::getIsSigned() const
{
    return (_isSigned);
}

int AForm::getGradeToSign() const
{
    return (_gradeToSign);
}

int AForm::getGradeToExecute() const
{
    return (_gradeToExecute);
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
    if (bureaucrat.getGrade() <= _gradeToSign)
        _isSigned = true;
    else
        throw GradeTooLowException();
}

const char *AForm::GradeTooHighException::what() const throw()
{
    return ("Grade too high!");
}

const char *AForm::GradeTooLowException::what() const throw()
{
    return ("Grade too low!");
}

const char *AForm::FormNotSignedException:: what() const throw()
{
    return ("Form not signed");
}

std::ostream &operator<<(std::ostream &os, AForm const &other)
{
    os << "Name: " << other.getName() << "\n";
    os << "isSigned: ";
    if (other.getIsSigned())
        os << "true";
    else
        os << "false";
    os << "\n";
    os << "Grade to sign: " << other.getGradeToSign() << "\n";
    os << "Grade to execute: " << other.getGradeToExecute() << "\n"; // <- salto de línea final
    return os;
}
