/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:15:39 by mkulikov          #+#    #+#             */
/*   Updated: 2025/04/01 15:11:53 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(const std::string &name, int gradeToExecute, int gradeToSign)
	: _name(name)
	, _isSigned(false)
	, _gradeToSign(gradeToSign)
	, _gradeToExecute(gradeToExecute)
{
	std::cout << "Form parameterized constructor called" << std::endl;
}

Form::Form(const Form &other)
	: _name(other._name)
	, _isSigned(other._isSigned)
	, _gradeToSign(other._gradeToSign)
	, _gradeToExecute(other._gradeToExecute)
{
	std::cout << "Form copy constructor called" << std::endl;
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	std::cout << "Form assign operator called" << std::endl;
	return *this;
}

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;;
}

bool Form::getIsSigned() const
{
	return _isSigned;
}

void Form::_setIsSigned(bool status)
{
	_isSigned = status;
}

int Form::getGradeToSign() const
{
	return _gradeToSign;
}

int Form::getGradeToExecute() const
{

	return _gradeToExecute;
}

const std::string Form::getName() const
{
	return _name;
}

void Form::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw Bureaucrat::GradeTooLowException();
	_setIsSigned(true);
}

std::ostream &operator<<(std::ostream &os, const Form &f)
{
	os << "Form name - " << f.getName()
		<< " form status - " << f.getIsSigned()
		<< " grade to execute - " << f.getGradeToExecute()
		<< " grade to sign - " << f.getGradeToSign();
	return os;
}
