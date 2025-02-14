/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ngtina1999 <ngtina1999@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 01:32:34 by ngtina1999        #+#    #+#             */
/*   Updated: 2025/02/14 16:35:52 by ngtina1999       ###   ########.fr       */
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

//if dynamic_cast fails, the result will be nullptr, and you can test for that explicitly
void	identify(Base* p) {
	if (dynamic_cast<A*>(p) != NULL)
		std::cout <<MYGREEN "A is identified" MYEOF<< std::endl;
	else if (dynamic_cast<B*>(p) != NULL)
		std::cout <<MYGREEN "B is identified" MYEOF<< std::endl;
	else if (dynamic_cast<C*>(p) != NULL)
		std::cout <<MYGREEN "C is identified" MYEOF<< std::endl;
	else
		std::cout << MYRED << "No type is identified" << MYEOF << std::endl;	
}

//When casting with references, there's no way to directly test for a failed cast, as references can't be nullptr
//If the cast fails, C++ will throw a std::bad_cast exception
void	identify(Base& p) {
	try {
		A referenceA = dynamic_cast<A &>(p);
		std::cout <<MYGREEN "A is identified" MYEOF<< std::endl;
		return ;
	}
	catch (std::exception &e) {
	}
	try {
		B referenceB = dynamic_cast<B &>(p);
		std::cout <<MYGREEN "B is identified" MYEOF<< std::endl;
		return ;
	}
	catch (std::exception &e) {
	}
	try {
		C referenceC = dynamic_cast<C &>(p);
		std::cout <<MYGREEN "C is identified" MYEOF<< std::endl;
		return ;
	}
	catch (std::exception &e) {
	}
	std::cout << MYRED << "No type is reference" << MYEOF << std::endl;
}


// If base actually points to an object of type Derived, the cast will succeed, and you can safely call methods specific to Derived.
// If base does not point to a Derived object, the cast will return nullptr.
// benefit of this is polymorphism. The pointer obj can point to any derived class object (like A, B, or C) while still being treated as a Base pointer, 
// allowing you to call Base methods.
//  However, you won't be able to access methods specific to A (unless they are overridden in the derived class).
int	main() {

	// seed is set using srand(), and if you do not set it explicitly, it is initialized to a default value (often 1).
	srand(clock() - rand());

	Base* obj = generate();
	std::cout << "Identification by pointer: ";
	identify(obj);

	std::cout << "Identification by reference: ";
	identify(*obj);

	delete obj;
}