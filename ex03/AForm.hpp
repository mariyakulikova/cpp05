/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:16:02 by mkulikov          #+#    #+#             */
/*   Updated: 2025/04/02 18:20:58 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
#include <iostream>
#include <cstdlib>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
private:
	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;
	std::string _target;
	void _checkBeforeExecute(Bureaucrat const &executor) const;
public:
	AForm(const std::string &name, int gradeToSign, int gradeToExecute, std::string target);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm();
	bool getIsSigned() const;
	void setIsSigned(bool status);
	int getGradeToSign() const;
	int getGradeToExecute() const;
	std::string getTarget() const;
	void setTarget(const std::string &target);
	const std::string getName() const;
	void beSigned(Bureaucrat &b);
	void execute(Bureaucrat const &executor) const;
	virtual void executeAction() const = 0;

	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const throw();
	};

	class FormIsNotSigned : public std::exception
	{
	public:
		const char* what() const throw();
	};
};

std::ostream& operator<<(std::ostream& os, const AForm& f);

