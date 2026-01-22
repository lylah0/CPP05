/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:28:51 by lylrandr          #+#    #+#             */
/*   Updated: 2026/01/22 19:45:40 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

class	Bureaucrat;

Form::Form(const std::string name, const int gToSign, const int gToExec) : _name(name), _gToSign(gToSign), _gToExec(gToExec){
	_signed = 0;
	if (_gToSign < 1)
		throw ExceptionTooHigh();
	if (_gToExec > 150)
		throw ExceptionTooLow();
	std::cout << "Default Form constructor called." << std::endl;
}

Form::Form(const Form& src) : _name(src._name), _gToSign(src._gToSign), _gToExec(src._gToExec) {
	_signed = src._signed;
	std::cout << "Copy Form constructor called." << std::endl;
}

Form&	Form::operator=(const Form& rhs){
	if (this != &rhs){
		this->_signed = rhs._signed;
	}
	return (*this);
}

Form::~Form(){
	std::cout << "Form destrcutor called." << std::endl;
}

void	Form::beSigned(Bureaucrat bureaucrat){
	if (bureaucrat.getGrade() <= _gToSign){
		_signed = 1;
		std::cout << bureaucrat.getName() << " signed " << _name << std::endl;
	}
}

std::string	Form::getName() const{
	return(_name);
}

bool	Form::getSignStatus() const{
	return (_signed);
}

int	Form::getGradeToSign() const{
	return (_gToSign);
}

int	Form::getGradeToExec() const{
	return (_gToExec);
}

std::ostream&	operator<<(std::ostream& os, const Form& rhs){
	os << "Form's name : " <<rhs.getName() << " , sign status : " << rhs.getSignStatus()
						   << ", grade required to sign : " << rhs.getGradeToSign()
						   << " , grade required to execute : " << rhs.getGradeToExec()
						   << std::endl;
	return (os);
}
