#include <iostream>

template < class TDerived > class StaticBaseA {
public:
	static void announce () {
		std::cout << "do something" << std::endl;
	}
};

template < class TDerived > class StaticBaseB {
public:
	static void announce () {
		std::cout << "do something else" << std::endl;
	}
};

class Derived : public StaticBaseA< Derived >, public StaticBaseB< Derived > {
	using StaticBaseA< Derived >::announce;
};

class NonDerived {};

int main (int argc, char* argv[]) {
	Derived::announce ();
	// What I want:
	// Derived::StaticBaseB<Derived>::announce(); Error: "Undefined symbol 'StaticBaseB'

	// What works, but what I don't want ...
	StaticBaseB< Derived >::announce ();

	// ... because I would like to prevent this (however this is done):
	StaticBaseB< NonDerived >::announce ();


	return 0;
}