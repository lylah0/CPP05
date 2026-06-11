/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:31:54 by lylrandr          #+#    #+#             */
/*   Updated: 2026/06/11 15:52:44 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <functional>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main(){
	Intern	intern;
	AForm*	form1;
	AForm*	form2;
	AForm*	form3;
	AForm*	form4;

	std::cout << "\n===test 1 : robotomy" << std::endl;
	form1 = intern.makeForm("robotomy request form", "Alice");
	std::cout << "\n===test 2 : presidential" << std::endl;
	form2 = intern.makeForm("presidential pardon form", "Bob");
	std::cout << "\n===test 3 : shrubbery" << std::endl;
	form3 = intern.makeForm("shrubbery creation form", "Charlie");
	std::cout << "\n===test 4 : does not exist" << std::endl;
	form4 = intern.makeForm("does not exist", "Nobody");
	delete form1;
	delete form2;
	delete form3;
	return (0);
}

