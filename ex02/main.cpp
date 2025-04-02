/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:06:52 by mkulikov          #+#    #+#             */
/*   Updated: 2025/04/02 17:22:29 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	srand (time(NULL));
	Bureaucrat b("Bob", 33);
	Bureaucrat a("Ann", 1);
	ShrubberyCreationForm f1("target1");
	RobotomyRequestForm f2("target2");
	PresidentialPardonForm f3("target3");
	a.signForm(f1);
	b.executeForm(f1);
	b.signForm(f3);
	a.signForm(f3);
	b.executeForm(f3);
	a.executeForm(f3);
	a.executeForm(f2);
	a.signForm(f2);
	a.executeForm(f2);
	return 0;
}
