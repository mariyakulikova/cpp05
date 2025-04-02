/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 17:25:51 by mkulikov          #+#    #+#             */
/*   Updated: 2025/04/02 18:03:27 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

struct FormFactory
{
	std::string name;
	AForm *(*create)(std::string target);
};

class Intern
{
private:
	static AForm *_createShrubbery(std::string target);
	static AForm *_createRobotomy(std::string target);
	static AForm *_createPardon(std::string target);
public:
	Intern();
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern();
	AForm *makeForm(const std::string formName, const std::string target);
};

