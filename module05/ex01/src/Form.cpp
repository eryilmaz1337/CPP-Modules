/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:04:48 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/07/04 12:04:49 by eryilmaz         ###   ########.tr	      */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Form.hpp"
#include "../lib/Bureaucrat.hpp"

Form::Form(): _name(), _reqGradeToSign(), _reqGradeToExecute()
{
	throw Form::GradeTooHighException();
}

Form::Form( std::string name, int reqGradeToSign, int reqGradeToExecute ):
    _name(name), _reqGradeToSign(reqGradeToSign), _reqGradeToExecute(reqGradeToExecute)
{
	if (reqGradeToSign == 0 || reqGradeToExecute == 0)
		throw Form::GradeTooHighException();
	if ( reqGradeToSign > 150 || reqGradeToExecute > 150)
		throw Form::GradeTooLowException();
	this->_isSigned = false;
}

Form::Form( const Form & src):
	_name(src._name), _reqGradeToSign(src._reqGradeToSign), _reqGradeToExecute(src._reqGradeToExecute)
{
    *this = src;
}

Form::~Form() {}

Form & Form::operator=( const Form & rhs )
{
	if (this == &rhs)
		return (*this);
	this->_isSigned = rhs._isSigned;
	return (*this);
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("FormException: Form Grade is too High");
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("FormException: Form Grade is too Low");
}

std::string	Form::getName() const
{
    return (this->_name);
}

bool		Form::getisSigned() const
{
    return (this->_isSigned);
}

int			Form::getReqGradeToSign() const
{
    return (this->_reqGradeToSign);
}

int			Form::getReqGradeToExecute() const
{
    return (this->_reqGradeToExecute);
}

void		Form::beSigned( Bureaucrat & brc )
{
	if (brc.getGrage() > this->_reqGradeToSign)
		throw  Form::GradeTooLowException();
	this->_isSigned = true;
}

std::ostream& operator<<( std::ostream& os, Form& form )
{
	os << "The Form " << form.getName() << ", need a Bureaucrat has Grade " << form.getReqGradeToSign() << " or higher to be able to sign, and need a Bureaucrat has Grade "
		<< form.getReqGradeToExecute() << " or higher to be execute ";
	if (form.getisSigned() == true)
		os << "and it's signed" << std::endl;
	else
		os << "and it's not signed" << std::endl;
	return (os);
}
