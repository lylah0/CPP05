/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:21:52 by lylrandr          #+#    #+#             */
/*   Updated: 2026/01/22 19:55:02 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>
# include <exception>
# include "Form.hpp"

class Form;

class Bureaucrat{
	private :
		const std::string	_name;
		int					_grade;
	public :

		class GradeTooHighException : public std::exception{
			public :
				const char* what() const throw(){
					return ("Exception : Grade too high.");
				}
		};

		class GradeTooLowException : public std::exception{
			public :
				const char* what() const throw(){
					return ("Exception : Grade too low.");
				}
		};

		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat&	operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		void			incrementGrade();
		void			decrementGrade();
		void			signForm(Form form);

		std::string		getName() const;
		int				getGrade() const;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif
