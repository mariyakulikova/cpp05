/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:26:22 by mkulikov          #+#    #+#             */
/*   Updated: 2025/04/02 18:41:50 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm *Intern::_createShrubbery(std::string target)
{
	return new ShrubberyCreationForm(target);
}

AForm *Intern::_createRobotomy(std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::_createPardon(std::string target)
{
	return new PresidentialPardonForm(target);
}

Intern::Intern()
{
	std::cout << "Intern default constructor called" << std::endl;
}

Intern::Intern(const Intern &other)
{
	(void)other;
	std::cout << "Intern copy constucot called" << std::endl;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	std::cout << "Intern assign operator called" << std::endl;
	return *this;
}

Intern::~Intern()
{
	std::cout << "Intern destructor called" << std::endl;
}

AForm *Intern::makeForm(const std::string formName, const std::string target)
{
	FormFactory formFactory[] = {
		{ "ShrubberyCreationForm", _createShrubbery },
		{ "RobotomyRequestForm", _createRobotomy },
		{ "PresidentialPardonForm", _createPardon }
	};

	for (int i = 0; i < 3; i++)
	{
		if (formFactory[i].name == formName)
		{
			std::cout << "Intern creates form " << formName << std::endl;
			return formFactory[i].create(target);
		}
	}
	std::cout << "Form name " << formName << " not recognized" << std::endl;
	return NULL;
}
