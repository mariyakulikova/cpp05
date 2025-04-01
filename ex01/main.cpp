/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:06:52 by mkulikov          #+#    #+#             */
/*   Updated: 2025/04/01 15:12:29 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat b("Bob", 33);
	Bureaucrat a("Ann", 1);
	Form f1("F1", 22, 27);
	Form f2("F2", 40, 55);
	Form f3("F3", 150, 150);
	b.signForm(f1);
	b.signForm(f2);
	b.signForm(f3);
	a.signForm(f1);
	return 0;
}
