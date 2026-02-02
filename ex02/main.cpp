/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 15:31:54 by lylrandr          #+#    #+#             */
/*   Updated: 2026/02/02 18:05:33 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

#include <cstdlib>
#include <ctime>
#include <iostream>

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	std::srand(std::time(NULL));

	std::cout << "=== TEST 1 : execute without signing ===" << std::endl;
	try{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("home");
		boss.executeForm(shrub);
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 2 : sign then execute ===" << std::endl;
	try{
		Bureaucrat boss("Boss", 1);
		ShrubberyCreationForm shrub("home");
		boss.signForm(shrub);
		boss.executeForm(shrub);
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 3 : robotomy ===" << std::endl;
	try{
		Bureaucrat boss("Boss", 1);
		RobotomyRequestForm robo("Bender");
		boss.signForm(robo);
		boss.executeForm(robo);
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n=== TEST 4 : pardon ===" << std::endl;
	try{
		Bureaucrat boss("Boss", 1);
		PresidentialPardonForm pardon("Arthur Dent");
		boss.signForm(pardon);
		boss.executeForm(pardon);
	}
	catch (const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}

