/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:04:18 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/07/04 12:04:19 by eryilmaz         ###   ########.tr	      */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP


#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Bureaucrat;

class AForm
{
	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_reqGradeToSign;
		const int			_reqGradeToExecute;
	public:
		AForm();
		AForm( std::string Name, int reqGradeToSign, int reqGradeToExecute );
		AForm( const AForm & src );
		virtual ~AForm();

		class GradeTooLowException: public std::exception
		{
			virtual	const char * what() const throw();
		};

		class GradeTooHighException: public std::exception
		{
			virtual	const char * what() const throw();
		};

		class FormIsNotSigned: public std::exception
		{
			virtual	const char * what() const throw();
		};

		AForm &					operator = ( const AForm & rhs );
		std::string				getName() const;
		bool					getisSigned() const;
		int			getReqGradeToSign() const;
		int			getReqGradeToExecute() const;
		void					beSigned( Bureaucrat & brc );
		virtual void	execute( Bureaucrat const & executor ) const = 0;
		virtual void	action() const = 0;
};

std::ostream&		operator << ( std::ostream& os, AForm& form );

#endif
