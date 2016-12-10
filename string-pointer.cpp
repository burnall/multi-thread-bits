#include <iostream>

class StringPointer {

private:
	std::string* p;
	bool alloc = false;

public:
	StringPointer(std::string* pointer): p(pointer) {
		if (pointer == NULL) {
			std::cerr << "NULL is met\n";
			p = new std::string();
			alloc = true;
		}
	};

	operator std::string*() {return p;}; 

	std::string* operator ->() {return p;}; 

	~StringPointer() {
		if (alloc) {
			std::cerr << "dealloc\n";
			delete p;
		}
	}
};

int main(int argc, char** argv) {
	std::string s1 = "Hello, world!";

	StringPointer sp1(&s1);
	StringPointer sp2(NULL);

	std::cout << sp1->length() << std::endl;
	std::cout << *sp1 << std::endl;
	std::cout << sp2->length() << std::endl;
	std::cout << *sp2 << std::endl;
}