/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 18:13:09 by lylrandr          #+#    #+#             */
/*   Updated: 2026/01/27 16:26:10 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AForm_HPP
#define AForm_HPP

# include <string>
# include <iostream>
# include <exception>

class	Bureaucrat;

class AForm{
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

		class ExceptionFormNotSigned : public std::exception{
			public :
				const char* what() const throw(){
					return("Exception form not signed.");
				}
		};

		AForm(const std::string& name, const int gToSign, const int gToExec);
		AForm(const AForm& src);
		AForm&	operator=(const AForm& rhs);
		virtual	~AForm();

		void				beSigned(const Bureaucrat& bureaucrat);
		void				execute(Bureaucrat const& executor) const;

		const std::string&	getName() const;
		bool				getSignStatus() const;
		int					getGradeToSign() const;
		int					getGradeToExec() const;

	protected :
		virtual void		executeAction() const = 0;
};

std::ostream&	operator<<(std::ostream& os, const AForm& rhs);

#endif
