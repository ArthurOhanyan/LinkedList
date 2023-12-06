#include <iostream>

template <typename T>
class Linked_List 
{
	public: 
		
		class Node 
		{
			public:

			T m_val;
			Node* next;

			Node();
			Node (const T&);
			
		};
		
		int m_size;
		Linked_List();
		~Linked_List();
		void push_back(const T&);
		void pop_back();
		void push_front(const T&);
		void pop_front();
		void insert(size_t,const T&);
		void erase (size_t);
		void clear ();
		void assign(size_t,const T&);
		void resize (size_t);
		void swap (Linked_List<T>&);
		void reverse ();
		void print_list();
		int size();
		bool empty();
		T& front();
		T& back();

	private:
		Node* head;
		
};

#include "implementation.hpp"
