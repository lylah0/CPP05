/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/27 18:04:57 by lylrandr          #+#    #+#             */
/*   Updated: 2026/01/29 14:36:02 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target) : AForm("ShrubberyCreationForm", 145, 137){
	_target = target;
	std::cout << "Default ShrubberyCreationForm constructor called." << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : AForm(src){
	_target = src._target;
	std::cout << "Shrubbery copy constructor called." << std::endl;
}

ShrubberyCreationForm&	ShrubberyCreationForm::operator=(const ShrubberyCreationForm& rhs){
	std::cout << "Shrubbery assignement operator called." << std::endl;
	if (this != &rhs){
		this->_target = rhs._target;
		AForm::operator=(rhs);
	}
	return(*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
	std::cout << "ShrubberyCreationForm destructor called." << std::endl;
}

void	ShrubberyCreationForm::executeAction() const{
	const std::string	filename = _target + "_shrubbery";
	std::ofstream out(filename.c_str());
	if (!out)
		throw std::runtime_error("Shrubbery	CreationnForm : could not create file.");
	out <<
	"       _-_\n"
	"    /~~   ~~\\\n"
	" /~~         ~~\\\n"
	"{               }\n"
	" \\  _-     -_  /\n"
	"   ~  \\\\ //  ~\n"
	"_- -   | | _- _\n"
	"  _ -  | |   -_\n"
	"      // \\\\\n";
}
