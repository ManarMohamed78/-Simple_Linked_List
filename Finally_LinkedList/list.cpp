#include<iostream>
#include<string>

#include "list.h"
using namespace std;

list::list()
{
	head = prv = cursor = NULL;
}

bool list::listIsEmpty()
{
	return (head == NULL);
}

bool list::curIsEmpty() const
{
	return (cursor == NULL);
}
void list::toFrist() {
	cursor = head;
	prv = NULL;
 }

void list::Advance()
{
	prv = cursor;
	cursor = cursor->next;
}

bool list::atFirst()
{
	return (cursor == head);
}

void list::toEnd()
{
	toFrist();
	if (!listIsEmpty()) {
		while (cursor->next != NULL)
		{
			Advance();
		}
	}
}

bool list::atEnd()
{
	if (listIsEmpty()) return true;
	else if (curIsEmpty()) return false;
	else
	return (cursor->next == NULL) ;
}

int list::listSize()
{
	int size = 0;
	if (!listIsEmpty()) {
		toFrist();
		while (cursor != NULL)
		{
			size++;
			Advance();

		}
	}		
	return size;
}

void list::insertFrirst(int k, char d)
{
	node* newNode = new node;
	newNode->id = k;
	newNode->data = d;
	
	newNode->next = head;
	head = newNode;

	toFrist();
	//cursor = head;
	//prv = NULL;
}

void list::insertAfter(int k, char d)
{
	node* newNode = new node;
	newNode->id = k;
	newNode->data = d;

	newNode->next = cursor->next;
	cursor->next = newNode;

	prv = cursor;
	cursor = cursor->next;// cursor = newNode
	//Advance();
}

void list::insertBefor(int k, char d)
{
	node* newNode = new node;
	newNode->id = k;
	newNode->data = d;

	newNode->next = prv->next;//newNode->next = cursor
	prv->next = newNode;
	cursor = newNode;
}

void list::insertEnd(int k, char d)
{
	if (listIsEmpty())
		insertFrirst(k,d);
	else
 	{
		toEnd();
		insertAfter(k, d);
	}
}

void list::update_data(const char& c ,char &d)
{
	toFrist();
	while (cursor->data != d)
	{
		Advance();
	}
	cursor->data = c;
}

void list::retriveData(int &k, char &d) const
{
	k = cursor->id;
	d = cursor->data;
}

void list::retriveKay(int &k)
{
	k = cursor->id;
}

void list::deleteNode()
{
	node* p ;
	
	if (!curIsEmpty())
	{
		if (atFirst()) // delete head node
		{
			p = head;
			head = head->next;

			cursor = head;
			prv = NULL;
			//toFrist();

			delete(p);
		}
		else          //  delete non_head node
		{
			p = cursor;
			cursor = cursor->next;
			prv->next = cursor;
			delete p;

		}
	}
}

void list::deleteFirst()
{ 
	if (!listIsEmpty())
	{
		toFrist();
		deleteNode();
	}
}

void list::deleteEnd()
{
	toEnd();
	deleteNode();
}

void list::delete_All_List() // makeListEmpty
{
	if (!listIsEmpty())
	{
		toFrist();
		while(!curIsEmpty()) //(cursor != NULL)
		{
			deleteNode();
			Advance();
		}
		
	}
}

bool list::search(const int&k)
{
	bool found = false;
	toFrist();
	while ((cursor != NULL) && !found)
	{
		if (cursor->id == k) found = true;
		else
		Advance();
	}
	return found;


}

void list::insertOrder(const int &k, const char &d)
{
	if (listIsEmpty())
	{
		insertFrirst(k, d);
	}
		
	else
	{
		toFrist();
		while (cursor != NULL && k > cursor->id)
		{
			Advance();
		}
		if (prv == NULL) insertFrirst(k , d);// id of firstNode > k
		else if(cursor == NULL) insertEnd(k , d); // if cursor exist of list =>  
		                                     //           (k > all cursor->id)  
		else                          // k < cursor->id 
			insertBefor(k, d);
	}
	
	
}

void list::display()
{
	if (!listIsEmpty()) {

		toFrist();
		while (!curIsEmpty()) // (cursor != NULL) 
		{
			cout << cursor->id << " - " << cursor->data << endl;
			Advance();
		}
	}
	cout <<endl;
}

list::~list()
{
	delete_All_List();
}




