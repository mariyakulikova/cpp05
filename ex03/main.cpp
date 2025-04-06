/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:06:52 by mkulikov          #+#    #+#             */
/*   Updated: 2025/04/06 15:50:34 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	Intern i;
	Bureaucrat b("Bob", 33);
	Bureaucrat a("Ann", 1);
	AForm *f1;
	AForm *f2;
	AForm *f3;
	f1 = i.makeForm("ShrubberyCreationForm", "target1");
	f2 = i.makeForm("RobotomyRequestForm", "target1");
	f3 = i.makeForm("PresidentialPardonForm", "target1");
	a.signForm(*f1);
	b.executeForm(*f1);
	b.signForm(*f3);
	a.signForm(*f3);
	b.executeForm(*f3);
	a.executeForm(*f3);
	a.executeForm(*f2);
	a.signForm(*f2);
	a.executeForm(*f2);
	delete f1;
	delete f2;
	delete f3;
	return 0;
}
