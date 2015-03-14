// LinkedList.cpp : Defines the entry point for the console application.
//

#include "iostream"

struct node
{
	char data;
	node *next;
};


node *create();
void showList(node *head);

int main()
{

	return 0;
}

node *create()
{
	node *head = NULL;	//There is no node in the beginning, so head is NULL.
	node *end = head;	//There is no element in the list, so end points to head.
	node *pNew;	//the pointer used when inserting new node
	char temp_data;	//store the temp data
	cout << "Please input a string end with '#': " << endl;

	do
	{
		cin >> temp_data;
		if (temp_data != '#')
		{
			pNew = new node; 
			pNew->data = temp_data;
			pNew->next = NULL;
			if (head == NULL)
			{
				head = pNew;
			}
			else
			{
				end->next = pNew;
			}
			end = pNew;
		}
	}while(temp_data != '#');

	return head;
}
