/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:30:04 by lylrandr          #+#    #+#             */
/*   Updated: 2026/06/10 18:12:04 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(){
	std::cout << "\n===test 1 : sign form" << std::endl;
	try{
		Bureaucrat	Emy("Emy", 1);
		Form		Letter("letter", 1, 3);
		std::cout << "sign status : " << Letter.getSignStatus() << std::endl;
		Emy.signForm(Letter);
		std::cout << "sign status : " << Letter.getSignStatus() << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n===test 2 : grade too low to sign" << std::endl;
	try{
		Bureaucrat	Franck("Franck", 100);
		Form		Certificat("Certificat", 1, 1);
		std::cout << "sign status : " << Certificat.getSignStatus() << std::endl;
		Franck.signForm(Certificat);
		std::cout << "sign status : " << Certificat.getSignStatus() << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n===test 3 : sign grade too high" << std::endl;
	try{
		Form	a("fail 1", 0, 3);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n===test 4 : sign grade too low" << std::endl;
	try{
		Form	b("fail 2", 151, 3);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n===test 5 : exec grade too high" << std::endl;
	try{
		Form	c("fail 3", 1, 0);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n===test 6 : form grade too low" << std::endl;
	try{
		Form	d("fail 4", 1, 160);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n===test 7 : operator<<" << std::endl;
	try{
		Form	e("Paper", 1, 24);
		std::cout << e << std::endl;
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	std::cout << "\n===test 8 : to sign" << std::endl;
	try{
		Bureaucrat	a("Amy", 80);
		Form		b("may be signed", 90, 90);
		Form		c("may not be signed", 1, 5);
		a.signForm(b);
		a.signForm(c);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return (0);

}
