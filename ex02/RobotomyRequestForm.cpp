/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:03:29 by lylrandr          #+#    #+#             */
/*   Updated: 2026/02/02 17:14:18 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45){
	_target = target;
	std::cout << "Default RobotomyRequestForm constructor called." << std::endl;
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm& src) : AForm(src){
	_target = src._target;
	std::cout << "RobotomyRequestForm copy constructor called." << std::endl;
}

RobotomyRequestForm&	RobotomyRequestForm::operator=(const RobotomyRequestForm& rhs){
	std::cout << "RobotomyRequestForm assignment operator called." << std::endl;
	if (this != &rhs){
		_target = rhs._target;
		AForm::operator=(rhs);
	}
	return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(){
	std::cout << "RobotomyRequestForm destructor called." << std::endl;
}

void	RobotomyRequestForm::executeAction() const{
	std::cout << "Brrrr brrrr brrrr" << std::endl;
	if (std::rand() % 2)
		std::cout << _target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomy failed." << std::endl;
}
