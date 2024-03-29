/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eryilmaz <eryilmaz@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:47:43 by eryilmaz          #+#    #+#             */
/*   Updated: 2023/05/30 13:47:44 by eryilmaz         ###   ########.tr	      */
/*                                                                            */
/* ************************************************************************** */

#include "../lib/Cure.hpp"

Cure::Cure() : AMateria( "cure" )
{
	std::cout << "Cure Default Constructor Called" << std::endl;
}

Cure::Cure( const Cure &ref ) : AMateria( "cure" )
{
	std::cout << "Cure Copy Constructor Called" << std::endl;
	*this = ref;
}

Cure &Cure::operator=( const Cure &ref )
{
	std::cout << "Cure Assignment Operator Called" << std::endl;
	if (this != &ref)
	{
		this->type = ref.type;
	}
	return (*this);
}

Cure::~Cure()
{
	std::cout << "Cure Destructor Called" << std::endl;
}

AMateria	*Cure::clone( void ) const
{
	return (new Cure(*this));
}

void		Cure::use( ICharacter &ref )
{
	std::cout << "* heals " << ref.getName() << "'s wounds *" << std::endl;
}
