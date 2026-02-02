/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:27:43 by lylrandr          #+#    #+#             */
/*   Updated: 2026/02/02 17:31:19 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade){
	if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	else if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	std::cout << "Default constructor called." << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat& src) : _name(src._name), _grade(src._grade){
	std::cout << "Copy constructor called." << std::endl;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& rhs){
	std::cout << "Assignment operator= called." << std::endl;
	if (this != &rhs)
		this->_grade = rhs._grade;
	return (*this);
}

Bureaucrat::~Bureaucrat(){
	std::cout << "Default destructor called." << std::endl;
}

void	Bureaucrat::incrementGrade(){
	if (_grade > 1){
		_grade--;
		std::cout << "Incrementing grade." << std::endl;
		return;
	}
	throw Bureaucrat::GradeTooHighException();
}

void	Bureaucrat::decrementGrade(){
	if (_grade < 150){
		_grade++;
		std::cout << "Decrementing grade." << std::endl;
		return;
	}
	throw Bureaucrat::GradeTooLowException();
}

void	Bureaucrat::signForm(AForm& form){
	try{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e){
		std::cout << _name << " couldn't sign " << form.getName() << " because "
				  << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const& form) const{
	try{
		form.execute(*this);
		std::cout << _name << " executed " << form.getName() << std::endl;
	}
	catch(std::exception& e){
		std::cout << _name << " couldn't execute " << form.getName() << " because "
				  << e.what() << std::endl;
	}
}

std::string	Bureaucrat::getName() const{
	return(_name);
}

int	Bureaucrat::getGrade() const{
	return(_grade);
}

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& rhs){
	os << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
	return (os);
}
