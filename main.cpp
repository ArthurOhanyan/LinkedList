#include <iostream>
#include "prototype.h"

int main ()
{
	Linked_List<int>  a;
	a.push_back(1);
	a.push_back(2);
	a.push_back(3);
	a.push_back(4);
	a.push_back(5);
	a.push_back(6);
	a.push_back(7);
	a.print_list();
	std::cout << "size ==  " << a.size() << std::endl;
	a.front() = 88;
	a.back () = 99;
	a.print_list();
	a.pop_back();
	a.print_list();
	std::cout << " size == " << a.size() << std::endl;
	a.push_front(44);
	a.print_list();
	std::cout << " size == " << a.size() << std::endl;

}
