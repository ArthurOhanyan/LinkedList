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

		/// class Iterator /////

		class Iterator 
		{
			public:
				explicit Iterator (Node* ptr1) : ptr(ptr1){};

				T& operator* (){
				
					return ptr -> m_val;
				}

				Iterator operator = (const Iterator& obj){
					
					this -> ptr = obj.ptr;
					return *this;
				} 

				Iterator operator ++ () {
					
					if (ptr){
					
						ptr = ptr -> next;
					}
						
					return *this;
				}

				Iterator operator ++ (int){
				
					Iterator tmp = *this;
					++*this;
					return tmp;
				}

				bool operator == (const Iterator& otr){
					
					return this -> ptr == otr.ptr;
				}

				bool operator != (const Iterator& otr){
					
					return !(this -> ptr == otr.ptr);
				}

				Iterator operator + (int x){
				
						
					int y = 0;
					Iterator tmp = *this;
					while (y < x){
					
						++tmp;
						++y;
					}
					if (!tmp.ptr){
					
						std::cout << " error :: operator + " << std::endl;
						exit(0);
					}
					return tmp;
				}

				Iterator (const Iterator& otr) : ptr (otr.ptr){};
				
			//private :
				Node* ptr;
		};
		
		using itr = Iterator;
		itr begin() {
		
			return itr (head);
		}

		itr end () {
		
			return itr (nullptr);
		}
		/// class Iterator end /////
		
		int m_size;
		Linked_List();
		~Linked_List();
		void push_back(const T&);
		void pop_back();
		void push_front(const T&);
		void pop_front();
		//void insert(size_t,const T&);
		void insert(Iterator,const T&);
		//void erase (size_t);
		void erase (Iterator);
		void clear ();
		void assign(size_t,const T&);
		void resize (size_t);
		void swap (Linked_List<T>&);
		void reverse ();
		void sort();
		void marge(const Linked_List<T>&);
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
