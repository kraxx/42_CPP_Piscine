#include <ctime>
#include <iostream>
#include <string>

class Base {
public:
	virtual ~Base(){};
};

class A : public Base {};
class B : public Base {};
class C : public Base {};

Base* generate(void) {

	int rng = rand() % 3;
	Base* b;

	if (rng == 0) {
		b = new A();
	} else if (rng == 1) {
		b = new B();
	} else {
		b = new C();
	}
	return b;
}

void identify_from_pointer(Base* p) {

	if (dynamic_cast<A*>(p)) {

		std::cout << "id from pointer: A" << std::endl;

	} else if (dynamic_cast<B*>(p)) {

		std::cout << "id from pointer: B" << std::endl;
		
	} else if (dynamic_cast<C*>(p)) {

		std::cout << "id from pointer: C" << std::endl;
	}
}

void identify_from_reference(Base& p) {

	try {

		A& a = dynamic_cast<A&>(p);
		std::cout << "id from reference: A" << std::endl;
		static_cast<void>(a);

	} catch(std::bad_cast &e) {
		std::cerr << "Casting A by reference failed" << std::endl;
	}

	try {

		B& b = dynamic_cast<B&>(p);
		std::cout << "id from reference: B" << std::endl;
		static_cast<void>(b);

	} catch(std::bad_cast &e) {
		std::cerr << "Casting B by reference failed" << std::endl;
	}

	try {

		C& c = dynamic_cast<C&>(p);
		std::cout << "id from reference: C" << std::endl;
		static_cast<void>(c);
		
	} catch(std::bad_cast &e) {
		std::cerr << "Casting C by reference failed" << std::endl;
	}
}


int main() {

	srand(time(nullptr));

	Base* b = generate();
	identify_from_pointer(b);
	identify_from_reference(*b);

	return 0;
}
