/********************************
*Filename:list.cpp		*
*Login:by932			*								
*AssignmentNo:ass4		*
*DateLastModified:19/10/2014	*							
********************************/
#include <iostream>
#include <cstring>
#include "list.h"
using namespace std;

LIST::LIST()
{
	nonodes = 0;
	head = NULL;

}

LIST::~LIST()
{
	node* temp = head;
	while(temp && temp->next) {
		temp=temp->next;
		delete temp;
	}

	nonodes = 0;
}

bool LIST::load(char input[])
{
	if (head == NULL)	// linked list is empty - so this will be the head node
	{			

		NPtr newnode = new node;

		if (newnode == NULL)		// could not allocate memory
		{
			cout << "Allocation error occured" << endl;
			return false;
		}	
		strcpy(newnode->content, input);
		newnode->count = 1;
		nonodes = 1;
		newnode->next = NULL;
		head = newnode;
		
	}
	else		// if not here then the linked list exists
	{
		NPtr check = head;
		while (check != NULL)
		{			
			if (strcmp(check->content, input) == 0)
			{
				check->count++;
				break;
			}
			if (check->next == NULL)
			{					
				NPtr newnode = new node;
				if (newnode == NULL)
				{
					cout << "Allocation error occured" << endl;
					return false;
				}
				strcpy(newnode->content, input);
				newnode->count++;
				nonodes += 1;
				newnode->next = NULL;
				check->next = newnode;
				break;
			}
			check = check->next;
			
		}
	}
	return true;
	
}

bool LIST::print(ostream&)
{
	if (head == NULL)
	{
		return false;
	}
	NPtr temp = head;				// do not change the head pointer
	while (temp != NULL)
	{
		cout << temp->content << '\t';
		cout << temp->count;
		cout << endl;
		temp = temp->next;
	}
	return true;

}

NPtr LIST::returnhead()
{
	return head;
}
