#include <iostream>

int main()
{
	//Block of code, checks for debug version.
#ifdef _DEBUG
	std::cout << "Debug!\n";
#endif
	std::cout << "Hello world!\n";
}
