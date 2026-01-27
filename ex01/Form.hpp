/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:13:09 by lylrandr          #+#    #+#             */
/*   Updated: 2026/01/27 15:34:10 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

# include <string>
# include <iostream>
# include <exception>
# include "Bureaucrat.hpp"

class	Bureaucrat;

class Form{
	private :
		bool				_signed;
		const std::string	_name;
		const int			_gToSign;
		const int			_gToExec;

	public :
		class ExceptionTooHigh : public std::exception{
			public :
				const char* what() const throw(){
					return("Exception grade too high.");
				}
		};

		class ExceptionTooLow : public std::exception{
			public :
				const char* what() const throw(){
					return("Exception grade too low.");
				}
		};

		Form(const std::string name, const int gToSign, const int gToExec);
		Form(const Form& src);
		Form&	operator=(const Form& rhs);
		~Form();

		void	beSigned(const Bureaucrat& bureaucrat);

		std::string			getName() const;
		bool				getSignStatus() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;
};

std::ostream&	operator<<(std::ostream& os, const Form& rhs);

#endif
