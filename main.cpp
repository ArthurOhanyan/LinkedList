#include <iostream>
#include "prototype.h"

int main ()
{
	Linked_List<int>  a;
	Linked_List<int>  b;
	
	for (int i = 10; i <= 20; ++i){
		
		a.push_back(i);
	}

	for (int i = 0; i <= 9; ++i){
		
		b.push_back(i);
	}
	b.print_list();
	b = std::move(a);
	std::cout << " b = " << b << std::endl;
	std::cout << " b[4] = " << b[99] << std::endl;

	

}
