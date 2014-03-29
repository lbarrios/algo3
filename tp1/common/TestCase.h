#include "headers.h"
class TestCase {
public:
	TestCase(std::istream &);
	~TestCase();
protected:
    istream &_input;
};
