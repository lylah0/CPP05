/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:10:11 by lylrandr          #+#    #+#             */
/*   Updated: 2026/01/22 17:17:12 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


int	main(){
	std::cout << "\n===test 1 : Grade too high" << std::endl;
	try{
		Bureaucrat	a("Emma", 0);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===test 2 : Grade too low" << std::endl;
	try{
		Bureaucrat	b("Elise", 200);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===test 3 : Increment" << std::endl;
	try{
		Bureaucrat	c("Lou", 2);
		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << c << std::endl;
		c.incrementGrade();
		std::cout << c << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n===test 4 : Decrement" << std::endl;
	try{
		Bureaucrat	d("Robert", 149);
		std::cout << d << std::endl;
		d.decrementGrade();
		std::cout << d << std::endl;
		d.decrementGrade();
		std::cout << d << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	return(0);
}
