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

		std::ostream& operator << (std::ostream& os)
		{
			Node* tmp = head;
			if (!head){
			
				std::cout << " The conteiner is empty " << std::endl;
				return os;
			}
			while (tmp){
				
				os << tmp -> m_val << " ";
				tmp = tmp -> next;
			}

			return os;
		}

		Linked_List& operator=(const Linked_List& other)
		{
			if (this != &other){
				
				if (head){
					
					clear();
				}

				head = new Node(other.head -> m_val);
				Node* tmp_this = head;
				Node* tmp_o_h = other.head;

				while (tmp_o_h -> next){
					
					tmp_o_h = tmp_o_h -> next;
					tmp_this -> next = new Node(tmp_o_h -> m_val);
					tmp_this = tmp_this -> next;
					
				}
				m_size = other.m_size;
			}
			return *this;
		}

		Linked_List& operator=(Linked_List&& other)
		{
			if(this != &other){
				
				if (head){
					
					clear();
				}

				head = other.head;
				m_size = other.m_size;
				other.head = nullptr;
			}
			return *this;
		}

		T& operator [] (size_t index)
		{
			if (!head){
				
				std::cout << " operator [] :: nullptr " << std::endl;
				exit (1);

			} else if (index < 0 || index >= m_size) {
				
				std::cout << "operator [] ::  invalid index " << std::endl;
				exit (1);
			}

			Node* tmp = head;
			int x = 0;
			
			while (x <= index){
				
				if (x == index){
					
					break;
				} 
				tmp = tmp -> next;
				++x;
			}
			return tmp -> m_val;
		}

	private:
		Node* head;
		
};

#include "implementation.hpp"
