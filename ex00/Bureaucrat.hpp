/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lylrandr <lylrandr@student.42lausanne.ch>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/19 16:21:52 by lylrandr          #+#    #+#             */
/*   Updated: 2026/01/19 18:34:15 by lylrandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat{
	private :
		const std::string	_name;
		int					_grade;
	public :
		Bureaucrat(std::string name, int grade);
		Bureaucrat(const Bureaucrat& src);
		Bureaucrat&	operator=(const Bureaucrat& rhs);
		~Bureaucrat();

		void			GradeTooHighException();
		void			GradeTooLowException();

		void			incrementGrade();
		void			decrementGrade();

		std::string		getName() const;
		int				getGrade() const;
};

std::ostream&	operator<<(std::ostream& os, const Bureaucrat& rhs);

#endif
