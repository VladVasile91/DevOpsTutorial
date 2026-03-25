#include "Rectangle.hpp"

#include <iostream>

int main()
{
	Rectangle r(20,10);
	std::cout<<"Rectangle permiterer result: " << r.calculatePermieter() << std::endl;
	std::cout<<"Rectangle area result: " << r.calculateArea() << std::endl;
	
	return 1;
}
