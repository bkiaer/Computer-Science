#include <iostream>
#include <stdlib.h>
using namespace std;

/***********************************************************
Linked List Definition
***********************************************************/
template <class Type> 
class LinkedList
{
	struct node
	{
		Type data;
		node * link;
	};
//**********************************************************
//Iterator class definition
public:
	class iterator
	{
	public:
		friend class LinkedList;
		iterator();
		iterator(node* ptr);
		iterator& operator++(int);
		Type& operator*();
		bool operator==(const iterator& rhs);
		bool operator!=(const iterator& rhs);
	private:
		node * current;
	};
	//**********************************************************
	//LinkedList class member functions
	void insert_front(const Type& item);
	void insert_back(const Type& item);
	void remove_front();
	void remove_back();
	LinkedList();
	LinkedList(const LinkedList& copy);
	~LinkedList();
	const LinkedList& operator=(const LinkedList& rhs);
	Type& front();
	Type& back();
	bool search(const Type& s);
	bool isEmpty();
	void delete_node(const Type& d);
	void reassign(const iterator& it, const Type& item);
	void insert_after(const iterator& it, const Type& item);
	void delete_node(iterator& it);
	void destroyList();
	iterator begin();
	iterator end();
private:
	node * head;
	node * tail;
};


/***********************************************************
LinkedList Implementation
***********************************************************/


/***********************************************************
Iterator Default Constructor
Precondition: None
Postcondition: Creates an iterator that points to NULL
***********************************************************/
template <class Type>	
LinkedList<Type>::iterator::iterator()
{
	current = NULL;
}

/***********************************************************
Iterator Constructor
Precondition: Takes a pointer of type node as a parameter
Postcondition: Creates an iterator that points the pointer
passed to it
***********************************************************/
template <class Type>
LinkedList<Type>::iterator::iterator(LinkedList<Type>::node* ptr)
{
	current = ptr;
}

/***********************************************************
Iterator operator++
Precondition: None
Postcondition: Returns an iterator that points to the next
node in the linked list, NULL otherwise
***********************************************************/
template <class Type>
typename LinkedList<Type>::iterator& LinkedList<Type>::iterator::operator++(int)
{
	current = current->link;
	return *this;
}

/***********************************************************
Iterator operator*
Precondition: None
Postcondition: Returns the data of the node that the iterator
is pointing to, if it points to NULL, a seg fault will result
***********************************************************/
template <class Type>
Type& LinkedList<Type>::iterator::operator*()
{
	return current->data;
}

/***********************************************************
Iterator operator==
Precondition: Takes an iterator which is on the right hand
side of the == operator
Postcondition: Returns true if the iterators point to the same
node and false otherwise
***********************************************************/
template <class Type>
bool LinkedList<Type>::iterator::operator==(const LinkedList<Type>::iterator& rhs)
{
	return current == rhs.current;
}

/***********************************************************
Iterator operator!=
Precondition: Takes an iterator which is on the right hand
side of the != operator
Poscondition: Returns true if the iterators point to a
different node and true otherwise
***********************************************************/
template <class Type>
bool LinkedList<Type>::iterator::operator!=(const LinkedList<Type>::iterator& rhs)
{
	return current != rhs.current;
}

/***********************************************************
LinkedList insert_front
Precondition: Takes an item to be inserted to the front of
the linked list
Postcondition: Adds the new item to the front of the linked list
***********************************************************/
template <class Type>
void LinkedList<Type>::insert_front(const Type& item)
{
	LinkedList<Type>::node * tmp;
	tmp = new LinkedList::node;
	tmp->data = item;
	tmp->link = head;
	head = tmp;
	if (tail == NULL)
		tail = head;
}

/***********************************************************
LinkedList insert_back
Precondition: Takes an item to be inserted to the back of the
linked list
Postcondition: Inserts the new item to the back of the linked list
***********************************************************/
template <class Type>
void LinkedList<Type>::insert_back(const Type& item)
{
	if (tail == NULL)
		insert_front(item);
	else
	{
		LinkedList<Type>::node * tmp;
		tmp = new LinkedList<Type>::node;
		tmp->data = item;
		tmp->link = NULL;
		tail->link = tmp;
		tail = tmp;
	}
}

/***********************************************************
LinkedList remove_front
Precondition: None
Postcondition: Removes the front item of the linked list, if
the list is empty then nothing happens
***********************************************************/
template <class Type>
void LinkedList<Type>::remove_front()
{
	if (head != NULL)
	{
		LinkedList<Type>::node * tmp;
		tmp = head->link;
		delete head;
		head = tmp;

		if (head == NULL)
			tail = NULL;
	}
}

/***********************************************************
LinkedList remove_back
Precondition: None
Postcondition: Removes the back element of the linked list, if
the list is empty then nothing happens
***********************************************************/
template <class Type>
void LinkedList<Type>::remove_back()
{
	if (tail != NULL)
	{
		if (head != tail)
		{
			LinkedList<Type>::node * tmp;
			tmp = head;
			while (tmp->link != tail)
				tmp = tmp->link;
			delete tail;
			tail = tmp;
			tail->link = NULL;
		}
		else
			remove_front();
	}
}

/***********************************************************
LinkedList default constructor
Precondition: None
Postcondition: Creates an emoty linked list
***********************************************************/
template <class Type>
LinkedList<Type>::LinkedList()
{
	head = tail = NULL;
}

/***********************************************************
LinkedList copy constructor
Precondition: Takes a linked list object
Postcondition: Creates a deep copy of the linked list object
passed to it
***********************************************************/
template <class Type>
LinkedList<Type>::LinkedList(const LinkedList<Type>& copy)
{
	head = tail = NULL;

	if (copy.head != NULL)
	{
		LinkedList<Type>::node * tmp = copy.head;

		while (tmp != NULL)
		{
			insert_back(tmp->data);
			tmp = tmp->link;
		}
	}	
}

/***********************************************************
LinkedList destructor
Precondition: None
Postcondition: Destroys the linked list
***********************************************************/
template <class Type>
LinkedList<Type>::~LinkedList()
{
	destroyList();
}

/***********************************************************
LinkedList assignment operator
Precondition: Takes a LinkedList object
Postcondition: Creates a deep copy of the linked list passed
to it unless it's a self assignment in which nothing will happen
***********************************************************/
template <class Type>
const LinkedList<Type>& LinkedList<Type>::operator=(const LinkedList<Type>& rhs)
{
	if (this != &rhs)
	{
		destroyList();

		if (rhs.head != NULL)
		{
			LinkedList<Type>::node * tmp = rhs.head;
			while (tmp != NULL)
			{
				insert_back(tmp->data);
				tmp = tmp->link;
			}
		}			
	}
	return *this;
}

/***********************************************************
LinkedList front
Precondition: None
Postcondition: Returns the front element of the linked list,
seg faults if the list is empty
***********************************************************/
template <class Type>
Type& LinkedList<Type>::front()
{
	return head->data;
}

/***********************************************************
LinkedList back
Precondition: None
Postcondition: Returns the last element of the linked list,
seg faults if the list is empty
***********************************************************/
template <class Type>
Type& LinkedList<Type>::back()
{
	return tail->data;
}

/***********************************************************
LinkedList search
Precondition: an element to be searched is passed
Postcondition: returns true if that element exists in the
linked list and false otherwise
***********************************************************/
template <class Type>
bool LinkedList<Type>::search(const Type& s)
{
	if (head == NULL)
		return false;
	else
	{
		for (LinkedList<Type>::node * i = head; i != NULL; i = i->link)
			if (i->data == s)
				return true;
		return false;
	}
}

/***********************************************************
LinkedList isEmpty
Precondition: None
Postcondition: Returns true if the linked list is empty and
false otherwise
***********************************************************/
template <class Type>
bool LinkedList<Type>::isEmpty()
{
	return head == NULL;
}

/***********************************************************
LinkedList delete_node
Precondition: Takes in an element to be deleted
Postcondition: Deletes the element passed in as a parameter
from the linked list, nothing happens if that element does
not exist
***********************************************************/
template <class Type>
void LinkedList<Type>::delete_node(const Type& d)
{
	if (head != NULL)
	{
		if (head->data == d)
			remove_front();
		else
		{
			LinkedList<Type>::node * curr1 = head;
			LinkedList<Type>::node * curr2 = head->link;
			while (curr2 != NULL)
			{
				if (curr2->data == d)
					break;
				curr1 = curr2;
				curr2 = curr2->link;
			}
			if (curr2 != NULL)
			{
				curr1->link = curr2->link;
				delete curr2;
			}
		}
	}
}

/***********************************************************
LinkedList reassign
Precondition: takes an iterator and an element
Postcondition: Replaces the contents of the node pointed to 
by the iterator with the item passed into it
***********************************************************/
template <class Type>
void LinkedList<Type>::reassign(const LinkedList<Type>::iterator& it, const Type& item)
{
	it.current->data = item;
}

/***********************************************************
LinkedList insert_after
Precondition: Takes in an iterator pointing to a node in
the linked list and an item to be inserted
Postcondition: Inserts a new node to the node next to the node
pointed to by the iterator
***********************************************************/
template <class Type>
void LinkedList<Type>::insert_after(const LinkedList<Type>::iterator& it, const Type& item)
{
	if (it.current == tail)
		insert_back(item);
	else
	{
		LinkedList<Type>::node * tmp;
		tmp = new LinkedList<Type>::node;
		tmp->data = item;
		tmp->link = it.current->link;
		it.current->link = tmp;
	}
}

/***********************************************************
LinkedList delete_node
Precondition: An iterator which points to a node in the linked
list
Postcondition: Deletes the node pointed to by the iterator and
moves the iterator to the preceding node
***********************************************************/
template <class Type>
void LinkedList<Type>::delete_node(LinkedList<Type>::iterator& it)
{
	if (it.current == head)
	{
		remove_front();
		it.current = head;
	}
	else if (it.current == tail)
	{
		remove_back();
		it.current = tail;
	}
	else
	{
		node * tmp = head;
		while (tmp->link != it.current)
			tmp = tmp->link;
		tmp->link = it.current->link;
		delete it.current;
		it.current = tmp;
	}
}
/***********************************************************
LinkedList destroyList
Precondition: None
Postcondition: Deallocates the linked list
***********************************************************/
template <class Type>
void LinkedList<Type>::destroyList()
{
	while (head != NULL)
		remove_front();
}

/***********************************************************
LinkedList begin
Precondition: None
Postcondition: Returns an iterator which points to the first
element of the linked list
***********************************************************/
template <class Type>
typename LinkedList<Type>::iterator LinkedList<Type>::begin()
{
	return LinkedList<Type>::iterator(head);
}

/***********************************************************
LinkedList end
Precondition: None
Postcondition: Returns an iterator that points to the last
element of the linked list
***********************************************************/
template <class Type>
typename LinkedList<Type>::iterator LinkedList<Type>::end()
{
	return LinkedList<Type>::iterator(NULL);
}
