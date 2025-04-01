/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:16:02 by mkulikov          #+#    #+#             */
/*   Updated: 2025/04/01 14:45:17 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
	void _setIsSigned(bool status);
public:
	Form(const std::string &name, int gradeToExecute, int gradeToSign);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form();
	bool getIsSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;
	const std::string getName() const;
	void beSigned(Bureaucrat &b);
};

std::ostream& operator<<(std::ostream& os, const Form& f);

