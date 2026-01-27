/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:30:04 by lylrandr          #+#    #+#             */
/*   Updated: 2026/01/27 15:12:55 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(){
	std::cout << "===test 1 : sign form" << std::endl;
	try{
		Bureaucrat	Emy("Emy", 1);
		Form		Letter("letter", 3, 3);
		Emy.signForm(Letter);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}

	std::cout << "===test 2 : grade too low to sign" << std::endl;
	try{
		Bureaucrat	Franck("Franck", 100);
		Form		Certificat("Certificat", 1, 1);
		Franck.signForm(Certificat);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}
