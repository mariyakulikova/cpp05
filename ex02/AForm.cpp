/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 20:15:39 by mkulikov          #+#    #+#             */
/*   Updated: 2025/04/02 10:55:47 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm(const std::string &name, int gradeToExecute, int gradeToSign, std::string target)
	: _name(name)
	, _isSigned(false)
	, _gradeToSign(gradeToSign)
	, _gradeToExecute(gradeToExecute)
	, _target(target)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
	std::cout << "AForm parameterized constructor called" << std::endl;
}

AForm::AForm(const AForm &other)
	: _name(other._name)
	, _isSigned(other._isSigned)
	, _gradeToSign(other._gradeToSign)
	, _gradeToExecute(other._gradeToExecute)
	, _target(other._target)
{
	std::cout << "AForm copy constructor called" << std::endl;
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
		_target = other._target;
	}
	std::cout << "AForm assign operator called" << std::endl;
	return *this;
}

AForm::~AForm()
{
	std::cout << "AForm destructor called" << std::endl;;
}

bool AForm::getIsSigned() const
{
	return _isSigned;
}

int AForm::getGradeToSign() const
{
	return _gradeToSign;
}

int AForm::getGradeToExecute() const
{

	return _gradeToExecute;
}

const std::string AForm::getName() const
{
	return _name;
}

void AForm::beSigned(Bureaucrat &b)
{
	if (b.getGrade() > _gradeToSign)
		throw AForm::GradeTooHighException();
	setIsSigned(true);
}

std::string AForm::getTarget() const
{
	return _target;
}

void AForm::setTarget(const std::string &target)
{
	_target = target;
}

void AForm::_checkBeforeExecute(Bureaucrat const &executor) const
{
	if (!getIsSigned())
		throw AForm::FormIsNotSigned();
	if (executor.getGrade() > getGradeToExecute())
		throw AForm::GradeTooHighException();
}

void AForm::execute(Bureaucrat const &executor) const
{
	_checkBeforeExecute(executor);
	executeAction();
}

std::ostream &operator<<(std::ostream &os, const AForm &f)
{
	os << "AForm name - " << f.getName()
		<< " AForm status - " << f.getIsSigned()
		<< " grade to execute - " << f.getGradeToExecute()
		<< " grade to sign - " << f.getGradeToSign();
	return os;
}

void AForm::setIsSigned(bool status)
{
	_isSigned = status;
}

const char* AForm::GradeTooLowException::what() const throw() {
	return "Form's grade is too low!";
}

const char* AForm::GradeTooHighException::what() const throw() {
	return "Form's grade is too high!";
}

const char* AForm::FormIsNotSigned::what() const throw() {
	return "Form is not signed!";
}
