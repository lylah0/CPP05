/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:28:51 by lylrandr          #+#    #+#             */
/*   Updated: 2026/01/27 16:27:14 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

AForm::AForm(const std::string& name, const int gToSign, const int gToExec) : _name(name), _gToSign(gToSign), _gToExec(gToExec){
	_signed = false;
	if (_gToSign < 1 || _gToExec < 1)
		throw ExceptionTooHigh();
	if (_gToSign > 150 || _gToExec > 150)
		throw ExceptionTooLow();
	std::cout << "Default AForm constructor called." << std::endl;
}

AForm::AForm(const AForm& src) : _name(src._name), _gToSign(src._gToSign), _gToExec(src._gToExec) {
	_signed = src._signed;
	std::cout << "Copy AForm constructor called." << std::endl;
}

AForm&	AForm::operator=(const AForm& rhs){
	if (this != &rhs){
		this->_signed = rhs._signed;
	}
	return (*this);
}

AForm::~AForm(){
	std::cout << "AForm destructor called." << std::endl;
}

void	AForm::beSigned(const Bureaucrat& bureaucrat){
	if (bureaucrat.getGrade() <= _gToSign){
		_signed = true;
	}
	else
		throw ExceptionTooLow();
}

void	AForm::execute(Bureaucrat const & executor) const{
	if (!getSignStatus())
		throw ExceptionFormNotSigned();
	if (executor.getGrade() > getGradeToExec())
		throw ExceptionTooLow();
	executeAction();
}

const std::string&	AForm::getName() const{
	return(_name);
}

bool	AForm::getSignStatus() const{
	return (_signed);
}

int	AForm::getGradeToSign() const{
	return (_gToSign);
}

int	AForm::getGradeToExec() const{
	return (_gToExec);
}

std::ostream&	operator<<(std::ostream& os, const AForm& rhs){
	os << "AForm's name : " << rhs.getName() << std::endl << "Sign status : " << rhs.getSignStatus()
						  << std::endl << "Grade required to sign : " << rhs.getGradeToSign()
						  << std::endl << "Grade required to execute : " << rhs.getGradeToExec()
						  << std::endl;
	return (os);
}
