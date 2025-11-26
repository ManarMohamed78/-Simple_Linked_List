#pragma once

#include<iostream>
#include<string>
class list
{
	class node {
	public:
		int id;
		char data;
		node* next;

	};
	node* head, * prv, * cursor;

public:
	list();
	bool listIsEmpty();
	bool curIsEmpty() const;
	void toFrist();
	void Advance();
	bool atFirst();
	void toEnd();
	bool atEnd();
	int listSize();
	void insertFrirst(int k, char d);
	void insertAfter(int k, char d);
	void insertBefor(int k, char d);
	void insertEnd(int k, char d);
	void update_data(const char&, char&);
	void retriveData(int&, char&) const;
	void retriveKay(int&);
	void deleteNode();
	void deleteFirst();
	void deleteEnd();
	void delete_All_List();
	bool search(const int&);
	void insertOrder(const int&, const char&);
	void display();
	~list();


};

