#include <iostream>
#include "prototype.h"

int main ()
{
	Linked_List<int>  a;
	Linked_List<int>  b;
	
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
	a.pop_front();
	a.print_list();
	std::cout << " size == " << a.size() << std::endl;
	a.insert(1,55);
	a.print_list();
	std::cout << " size == " << a.size() << std::endl;
	a.erase(6);
	a.print_list();
	std::cout << " size == " << a.size() << std::endl;
	a.clear();
	a.print_list();
	std::cout << " size == " << a.size() << std::endl;
	a.assign(5,9);
	a.print_list();
	a.assign(3,7);
	a.print_list();
	std::cout << " size == " << a.size() << std::endl;
	a.resize(15);
	a.print_list();
	std::cout << " size == " << a.size() << std::endl;
	a.resize(3);
	a.print_list();
        std::cout << " size == " << a.size() << std::endl;	
	b.assign(8,8);
	b.print_list();
	a.swap(b);
	std::cout << " ::::::::::::::::::: " << std::endl;
	std::cout << " a :::: " << std::endl;
	a.print_list();
	std::cout << " b :::::: " << std::endl;
	b.print_list();
	b.clear();
	for (int i = 0; i < 9; ++i){
		
		b.push_back(i);
	}
	b.print_list();
	b.reverse();
	b.print_list();


	

}
