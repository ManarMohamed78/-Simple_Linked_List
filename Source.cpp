#include <iostream>
#include "list.cpp"
using namespace std;

int main()
{
	list l1;
	/*
		l1.insertFrirst(5, 'E');
		l1.insertFrirst(4, 'D');
		l1.insertFrirst(3, 'C');
		l1.insertFrirst(2, 'B');
		l1.insertFrirst(1, 'A');
		l1.display();

		l1.deleteFirst();
		l1.display();

		l1.deleteEnd();
		l1.display();

		l1.insertFrirst(5 , 'E');
		l1.insertEnd(1 , 'A');
		l1.insertBefor(444 , 'R');
		l1.insertAfter(445 , 'S');
		l1.display();

		l1.toEnd();
		l1.insertAfter(446 , 'Z');
		l1.display();
	*/
	cout << "\n===============================\n";

	list *l2 = new list();
	if (l2->listIsEmpty())
		l2->insertFrirst(20, 'b');

	else
		l2->insertOrder(20, 'b');

	l2->display();
	l2->insertOrder(50, 'e');
	l2->insertOrder(10, 'a');
	l2->insertOrder(40, 'd');
	l2->insertOrder(30, 'c');

	l2->display();
	
	return 0;
}