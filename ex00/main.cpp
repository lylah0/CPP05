/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 18:10:11 by lylrandr          #+#    #+#             */
/*   Updated: 2026/01/19 18:53:07 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int	main(){
	Bureaucrat	a("Emma", 0);
	Bureaucrat	b("Elise", 151);
	std::cout << "\n===test 1 : grade too high" << std::endl;
	try{
		if (a.getGrade() < 1)
			throw(a.getGrade());
	}
	catch(int){
		a.GradeTooHighException();
	}
	a.incrementGrade();
	a.decrementGrade();
	a.decrementGrade();
	std::cout << "Grade : " << a.getGrade() << std::endl;
	a.incrementGrade();
	std::cout << "Grade : " << a.getGrade() << std::endl;

	std::cout << "\n===test 2 : grade too low" << std::endl;
	try{
		if (b.getGrade() > 150)
			throw(b.getGrade());
	}
	catch(int){
		b.GradeTooLowException();
	}
	b.decrementGrade();
	b.incrementGrade();
	b.incrementGrade();
	std::cout << "Grade : " << b.getGrade() << std::endl;
	b.incrementGrade();
	std::cout << "Grade : " << b.getGrade() << std::endl;

	std::cout << "\n===test 3 : <<" << std::endl;
	std::cout << b;
	return(0);
}
