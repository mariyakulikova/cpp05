/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 16:06:52 by mkulikov          #+#    #+#             */
/*   Updated: 2025/03/31 17:38:08 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	std::cout << "Trying create bureaucrat with invalid grade" << std::endl;
	try
	{
		Bureaucrat b1("Me", 666);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	try
	{
		Bureaucrat b1("Me", -666);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Creating bureaucrat with the highest grade" << std::endl;
	Bureaucrat t("Tom", 1);
	std::cout << t << std::endl;
	std::cout << "Increacing Tom's grade" << std::endl;
	try
	{
		t.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Creating bureaucrat with the smallest grade" << std::endl;
	Bureaucrat b("Bob", 150);
	std::cout << b << std::endl;
	std::cout << "Decreacing Bob's grade" << std::endl;
	try
	{
		b.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	std::cout << "Regular bureaucrat" << std::endl;
	Bureaucrat ann("Ann", 77);
	std::cout << ann << std::endl;
	std::cout << "Ann got promoted two times at once. Good job, Ann" << std::endl;
	ann.incrementGrade();
	ann.incrementGrade();
	std::cout << ann << std::endl;
	for (int i = 0; i < 5; i++)
	{
		ann.decrementGrade();
	}
	std::cout << "What did you do, Ann?" << std::endl;
	std::cout << ann << std::endl;
	return 0;
}
