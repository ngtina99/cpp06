/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 01:32:34 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/14 15:50:04 by ngtina1999       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/A.hpp"
#include "../includes/B.hpp"
#include "../includes/C.hpp"
#include "../includes/Base.hpp"

Base *generate(void) {
	switch(rand() % 3) {
		case 0:
			std::cout << MYBLUE << "A generated" << MYEOF << std::endl;
			return(new A());
		case 1:
			std::cout << MYBLUE << "B generated" << MYEOF << std::endl;
			return(new B());
		case 2:
			std::cout << MYBLUE << "C generated" << MYEOF << std::endl;
			return(new C());
		default:
			std::cout << MYRED << "Error in generation" << MYEOF << std::endl;
			return(NULL);
	}
}
// It randomly instanciates A, B or C and returns the instance as a Base pointer. Feel free
// to use anything you like for the random choice implementation.

void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout << "A is identified with a pointer" << std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout << "B is identified with a pointer" << std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout << "C is identified with a pointer" << std::endl;
	else
		std::cout << MYRED << "No type is identified" << MYEOF << std::endl;	
}

void	identify(Base& p) {
	try {
		A referenceA = dynamic_cast<A &>(p);
		std::cout << "A is identified with a reference" << std::endl;
		return ;
	}
	catch (std::exception &e) {
	}
	try {
		B referenceB = dynamic_cast<B &>(p);
		std::cout << "B is identified with a reference" << std::endl;
		return ;
	}
	catch (std::exception &e) {
	}
	try {
		C referenceC = dynamic_cast<C &>(p);
		std::cout << "C is identified with a reference" << std::endl;
		return ;
	}
	catch (std::exception &e) {
	}
	std::cout << MYRED << "No type is reference" << MYEOF << std::endl;
}

int	main() {

	srand(clock() - rand());

    Base* obj = generate();
    std::cout << "Identification by pointer: ";
    identify(obj);
    
    std::cout << "Identification by reference: ";
    identify(*obj);

	// Proof of downcasting
	if (A* a = dynamic_cast<A*>(obj)) {
		std::cout << MYGREEN "Downcasting succeeded: Object is of type A" MYEOF<< std::endl;
	} else if (B* b = dynamic_cast<B*>(obj)) {
		std::cout << MYGREEN "Downcasting succeeded" MYEOF<< ":" << MYBLUE " Object is of type B" MYEOF<< std::endl;
	} else if (C* c = dynamic_cast<C*>(obj)) {
		std::cout << MYGREEN "Downcasting succeeded: Object is of type C" MYEOF << std::endl;
	} else {
		std::cout << MYRED "Errord: downcasting failed" MYEOF<< std::endl;
	}
    delete obj;
}