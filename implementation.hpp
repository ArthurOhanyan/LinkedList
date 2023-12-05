#include <iostream>

template <typename T>
Linked_List<T>::Linked_List()
{
	head = nullptr;
	m_size = 0;

}

template <typename T>
Linked_List<T>::~Linked_List()
{
	Node* tmp = head;
	while (tmp){
		
		Node* tmp_next = tmp -> next;
		delete tmp;
		tmp = tmp_next;
	}
	 head = nullptr;
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

	}
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

