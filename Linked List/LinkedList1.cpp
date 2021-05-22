//Simple Linked List with hardcoded data and prinitng out data
#include<iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
};

int main()
{
	//pointers to three nodes
	Node* head = NULL;
	Node* first;
	Node* second;
	Node* third;
	//Creating 3 Nodes
	first = new Node();
	second = new Node();
	third = new Node();
	//Putting Values in Node 
	first->data = 100;
	first->next = second;

	second->data = 200;
	second->next = third;

	third->data = 300;
	third->next = NULL;

	//printing values of nodes
	head = first;//head pointing to first
	while (head!=NULL)
	{
		cout << head->data << "\n";
		head = head->next;
	}

	return 0;
}