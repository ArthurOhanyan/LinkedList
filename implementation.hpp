#include <iostream>

template <typename T>
std::ostream& operator << (std::ostream& os, Linked_List<T>& list)
{
	return list.operator<<(os);
}

template <typename T>
Linked_List<T>::Linked_List()
{
	head = nullptr;
	m_size = 0;

}

template <typename T>
Linked_List<T>::~Linked_List()
{
	/*
	 * Node* tmp = head;
	while (tmp){
		
		Node* tmp_next = tmp -> next;
		delete tmp;
		tmp = tmp_next;
	}
	 head = nullptr;
	 */
	Linked_List<T>::clear();
}

template <typename T>
void Linked_List<T>::push_back(const T& val)
{
	if(!head){
		
		head = new Node (val);
		++m_size;
	
	} else {
		
		Node* tmp = head;
		while (tmp -> next) {
		
			tmp = tmp -> next;
		}
		tmp -> next = new Node(val);
		++m_size;
	}
}

template <typename T>
void Linked_List<T>::pop_back()
{
	if (!head){
		
		std::cout << " pop_back () :: nullptr :: " << std::endl;
		exit(1);

	} else if (m_size == 0) {
		
		std::cout << " The list is empty " << std::endl; 
	}

	Node* tmp = head;
	while (tmp -> next -> next) {
		
		tmp = tmp -> next;
	}

	delete tmp -> next;
	tmp -> next = nullptr;
	--m_size;
}

template <typename T>
void Linked_List<T>::push_front(const T& val)
{
	if (!head){
		
		push_back(val);

	} else {
	
		Node* tmp = new Node (val);
		tmp -> next = head;
		head = tmp;
		++m_size;

	}
}

template <typename T>
void Linked_List<T>::pop_front()
{
	if (!head){
		
		std::cout << " pop_front() :: nullptr :: " << std::endl;
		exit(1);

	} else if (empty()) {
		
		std::cout << " The list is empty. " << std::endl;
	        exit (1);	
	}

	Node* tmp = head;
	head = head -> next;
	delete tmp;
	--m_size;

}

/*template <typename T>
void Linked_List<T>::insert (size_t index, const T& val)
{
	if (!head){
		
		std::cout << " insert () :: nullptr :: " << std::endl;
		exit(1);

	} else if (index < 0 || index >= m_size) {
		
		std::cout << " insert () :: invalid index :: " << std::endl;
		exit(1);
	} 

	
	if (index == 0){
	
		push_front(val);
		++m_size;

	} else {

		int x = 1;
		Node* tmp = head;
		while (x < index){
		
			tmp = tmp -> next;
			++x;
		}

		Node* tmp2 = new Node(val);
		tmp2 -> next = tmp -> next;
		tmp -> next = tmp2;
		tmp = nullptr;
		++m_size;
	}
}*/

template <typename T>
void Linked_List<T>::insert (Linked_List<T>::Iterator it, const T& val)
{

	if (!head){
		
		std::cout << " insert () :: nullptr :: " << std::endl;
		exit(1);
	}
	

	
	if (it == Linked_List<T>::Iterator(head)){
	
		push_front(val);
		++m_size;

	} else {

		 Iterator tmp = Linked_List<T>::Iterator(head);
		 Iterator cur = Linked_List<T>::Iterator(head);
		while (tmp != it){
		
			++tmp;
			if (tmp != it){
				
				++cur;
			}	
		}


		Node* tmp2 = new Node(val);
		tmp2 -> next = tmp.ptr;
		cur.ptr -> next = tmp2;
		//tmp = nullptr;
		++m_size;
	}
}

/*template <typename T>
void Linked_List<T>::erase(size_t index)
{
	if (!head){
		
		std::cout << " erase () :: nullptr ::" << std::endl;
		exit(1);

	} else if (index < 0 || index >= m_size){
	
	
		std::cout << " erase () :: invalid index " << std::endl;
		exit(1);
	} 
	
	int x = 1;
	Node* tmp = head;
	while (x < index){
		
		tmp = tmp -> next;
		++x;
	}
	
	Node* tmp2 = tmp -> next -> next;
	delete tmp -> next;
	tmp -> next = tmp2;
	--m_size;
}*/

template <typename T>
void Linked_List<T>::erase(Linked_List<T>::Iterator it)
{
	if (!head){
		
		std::cout << " erase () :: nullptr ::" << std::endl;
		exit(1);

	} else if (!it.ptr){
	
		std::cout << " erase () :: invalid index " << std::endl;
		exit(1);
	} 
	
	
	Iterator tmp = Linked_List<T>::Iterator(head);
	Iterator cur = Linked_List<T>::Iterator(head);

	if (tmp.ptr == head){
	
		this -> pop_front();
		return;
	}
	while (tmp != it){
			
		++tmp;
		if(tmp != it){
		
			++cur;
		}
		
	}
	
	cur.ptr -> next = tmp.ptr -> next;
	delete tmp.ptr;
	--m_size;
}

template <typename T>
void Linked_List<T>::assign (size_t count, const T& val)
{
	clear();

	if (!head){
		
		head = new Node(val);
		++m_size;
		Node* tmp = head;
		int x = 1;
		while (x < count){
			
			Node* tmp2 = new Node(val);
			tmp -> next = tmp2;
			tmp = tmp2;
			++x;
			++m_size;
		}
	       
	} 
}

template <typename T>
void Linked_List<T>::resize(size_t new_size)
{
	if (!head){
	
		head = new Node(0);
		++m_size;
		Node* tmp = head;
		int x = 1;
		while (x < new_size){
			
			Node* tmp2 = new Node(0);
			tmp -> next = tmp2;
			tmp = tmp2;
			++x;
			++m_size;
		}

	} else if (new_size > m_size){
		
		/*
		 * Node* tmp = head;
		while (tmp -> next){
		
			tmp = tmp -> next;
		}

		int x = 0;
		int y = new_size - m_size;
		while (x < y){
		
			Node* tmp2 = new Node(0);
			tmp -> next = tmp2;
			tmp = tmp2;
			++x;
			++m_size;
		} */
		int x = 0;
		int y = new_size - m_size;
		while (x < y){
			
			push_back(0);
			++x;
		}

	} else if (new_size < m_size) {
	
		int x = 0;
		int y = m_size - new_size;
		while (x < y){
			
			pop_back();
			++x;
		}
		
	}
}

template <typename T>
void Linked_List<T>::swap(Linked_List<T>& other)
{
	if (head != other.head){
		
		Node* tmp = other.head;
		other.head = head;
		head = tmp;
		int tmp_size = m_size;
		m_size = other.size();
		other.m_size = tmp_size;

	}
}

template <typename T>
void Linked_List<T>::reverse() 
{
	if (!head){
		
		std::cout << " reverse () :: nullptr " << std::endl;
		exit (0);
	} 
	
	Node* tmp = nullptr;
	Node* prev = nullptr;
	Node* current = head;
	while (current) {
		
		tmp = current -> next;
		current -> next = prev;
		prev = current;
		current = tmp;
	}

	head = prev;

}

template <typename T>
void Linked_List<T>::sort()
{
	
	if (!head){
		
		std::cout << " sort() :: nullptr " << std::endl;
	        exit(1);

	} 

	
	Node* prev = head;
	Node* curent = head -> next;

	while (curent){
	
		if (curent -> m_val < prev -> m_val){
			
			prev -> next = curent -> next;
			curent -> next = head;
			head = curent;
			curent = prev;
		} else {
			
			prev = curent;
			curent = curent -> next;
		}


	}	

}

template <typename T>
void Linked_List<T>::marge (const Linked_List<T>& other)
{
	Node	*tmp1 = this->head;
	Node	*tmp2 = other.head;
	Node	*curr;

	if (!other.head)
		return ;
	if (tmp1 && tmp2)
	{
		if (tmp2->m_val <= tmp1->m_val)
		{
			this->head = tmp2;
			tmp2 = tmp2->next;
		}
	}
	curr = this->head;
	while (tmp1 && tmp2)
	{
		if (tmp1->m_val <= tmp2->m_val)
		{
			curr->next = tmp1;
			tmp1 = tmp1->next;
		}
		else
		{
			curr->next = tmp2;
			tmp2 = tmp2->next;
		}
		curr = curr->next;
	}
	if (tmp1)
		curr->next = tmp1;
	else if (tmp2)
	{
		curr->next = tmp2;
		//this->tail = other.tail;
	}
	//other.head = nullptr;
	//other.tail = nullptr;
	//other.m_size = 0;
	
}

template <typename T>
void Linked_List<T>::clear ()
{
	
	Node* tmp = head;
	while (tmp){
		
		Node* tmp_next = tmp -> next;
		delete tmp;
		tmp = tmp_next;
	}
	 head = nullptr;
	 m_size = 0;

}

template <typename T>
T& Linked_List<T>::front ()
{
	if (!head){
		
		std::cout << " front () :: head nullptr " << std::endl;
		exit(1);

	} else if (m_size == 0) {
		
		std::cout << " The list is empty " << std::endl;
		exit (1);
	} 

	return head -> m_val;
}

template <typename T>
T& Linked_List<T>::back ()
{
	if (!head){
		
		std::cout << " back () :: nullptr " << std::endl;
		exit(1);

	}  else if (m_size == 0) {
		
		std::cout << " The list is empty " << std::endl;
		exit(1);
	}

	Node* tmp = head;
	while (tmp -> next){
		
		tmp = tmp -> next;
	}

	return tmp -> m_val;
}

template <typename T>
int Linked_List<T>::size ()
{
	return m_size;
}

template <typename T>
bool Linked_List<T>::empty ()
{
	if (m_size == 0){
		
		return true;
	}

	return false;
}

template <typename T>
void Linked_List<T>::print_list ()
{
	Node* tmp = head;
	while (tmp){
		
		std::cout << tmp -> m_val << " ";
		tmp = tmp -> next;
	}
	std::cout << std::endl;
}

template <typename T>
Linked_List<T>::Node::Node()
{
	m_val = 0;
	next = nullptr;
}

template <typename T>
Linked_List<T>::Node::Node (const T& val)
{
	m_val = val;
	next = nullptr;
}


