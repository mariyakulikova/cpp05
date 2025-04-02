/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkulikov <mkulikov@student.42berlin.de>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 13:48:11 by mkulikov          #+#    #+#             */
/*   Updated: 2025/04/02 16:49:03 by mkulikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <fstream>
#include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
private:

public:
	RobotomyRequestForm(const std::string &target);
	RobotomyRequestForm(const RobotomyRequestForm &f);
	RobotomyRequestForm &operator=(const RobotomyRequestForm &f);
	~RobotomyRequestForm();

	void executeAction() const;
};
