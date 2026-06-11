/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/10 18:37:38 by lylrandr          #+#    #+#             */
/*   Updated: 2026/06/11 15:48:46 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern(){
	std::cout << "Intern constructor called" << std::endl;
}

Intern::Intern(const Intern &other){
	*this = other;
	std::cout << "Intern copy constructor called" << std::endl;
}

Intern&	Intern::operator=(const Intern &other){
	(void)other;
	return (*this);
}

Intern::~Intern(){
	std::cout << "Intern destructor called" << std::endl;
}

struct FormEntry
{
	std::string	name;
	AForm*		(*creator)(const std::string);
};

static AForm* createPresidential(const std::string target){
	return new PresidentialPardonForm(target);
}

static AForm* createRobotomy(const std::string target){
	return new RobotomyRequestForm(target);
}

static AForm* createShrubbery(const std::string target){
return new ShrubberyCreationForm(target);
}

AForm* Intern::makeForm(std::string formName, std::string target){
	FormEntry forms[3] = {
		{"presidential pardon form", createPresidential},
		{"robotomy request form",    createRobotomy},
		{"shrubbery creation form",  createShrubbery}
	};
	for (int i = 0; i < 3; i++){
		if (forms[i].name == formName)
		{
			std::cout << "Intern creates " << formName << std::endl;
			return forms[i].creator(target);
		}
	}
	std::cout << "Error: form '" << formName << "' does not exist" << std::endl;
	return NULL;
}
