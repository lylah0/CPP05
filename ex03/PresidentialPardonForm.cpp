/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/28 16:26:40 by lylrandr          #+#    #+#             */
/*   Updated: 2026/02/09 17:39:42 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(const std::string& target) : AForm("PresidentialPardonForm", 25, 5){
	_target = target;
	std::cout << "Default PresidentialPardonForm constructor called." << std::endl;
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) : AForm(src){
	_target = src._target;
	std::cout << "PresidentialPardonForm copy constructor called." << std::endl;
}

PresidentialPardonForm&	PresidentialPardonForm::operator=(const PresidentialPardonForm& rhs){
	std::cout << "PresidentialPardonForm operator assignment called." << std::endl;
	if (this != &rhs){
		_target = rhs._target;
		AForm::operator=(rhs);
	}
	return(*this);
}

PresidentialPardonForm::~PresidentialPardonForm(){
	std::cout << "PresidentialPardonForm destructor called." << std::endl;
}

void	PresidentialPardonForm::executeAction() const{
	std::cout << _target << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
