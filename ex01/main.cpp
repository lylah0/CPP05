/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 19:30:04 by lylrandr          #+#    #+#             */
/*   Updated: 2026/01/22 19:49:22 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int	main(){
	std::cout << "===test 1 : sign form" << std::endl;
	try{
		Bureaucrat	Ba("Emy", 1);
		Form		Fa("letter", 3, 3);
	}
	catch(const std::exception& e){
		std::cout << e.what() << std::endl;
	}
	return (0);
}
