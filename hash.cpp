/********************************
*Filename:hash.cpp		*
*Login:by932			*								
*AssignmentNo:ass4		*
*DateLastModified:19/10/2014	*							
********************************/
#include <iostream>
#include <string.h>
#include <stdlib.h>
#include "hash.h"
using namespace std;

HT::HT()
{
	hashtable[SIZE] = NULL;

	for (int index = 0; index < SIZE; index++)
		hashtable[index] = new htnode();
}  

HT::~HT()
{
	for (int i =0; i < 100; i++)
		delete  hashtable[i];
		
}
void HT::calculate(char input[])
{	
	int sum = 0;
	int which = 0;
	for (int i = 0; i < 20; i++)
	{
		sum += static_cast<int>(input[i]);
	}
	
	which = sum % SIZE;
	hashtable[which]->data.load(input);
	
}

void HT::findtop()
{
	for (int i = 0; i < SIZE; i++)
	{
		topten(hashtable[i]->data);
	}
	sort(sortarr);
}
bool HT::topten(LIST& pass)
{
	NPtr head;
	//head = hashtable->data.returnhead();
	if (head == NULL)
	{
		return false;
	}
	NPtr temp = head;
	int move = 0;				// do not change the head pointer
	while (temp != NULL)
	{
		
		while (sortarr[move].content != '\0' && move < 10)
		{
			move++;
		}
		if (sortarr[move].content == '\0')
		{
			strcpy(sortarr[move].content, temp->content);
			sortarr[move].count = temp->count;
			move++;
		}
		else
		{
			for (int i = 0; i < 10; i++)
			{
				if (sortarr[i].count < temp->count)
				{
					strcpy(sortarr[i].content, temp->content);
					sortarr[i].count = temp->count;
				}
			}
		}
		temp = temp->next;
			
	}
	return true;

}

void HT::sort(sortnode right[])
{
	for (int i = 9; i > 0; i--)
	{	
		for (int q = 0; q < 10; q++)// print out sorted collection
		{
		    cout << right[q].count << " ";
		}
		cout << endl;
        
		for (int j = 0; j < i; j++)		// perform sorting
		{			
		 	if (right[j].count > right[j+1].count)				
			{
				int temp = right[j+1].count;
				char tempch[21] = {'\0'};				
				strcpy(tempch, right[j + 1].content);
				
				right[j+1].count = right[j].count;				
				strcpy(right[j + 1].content, right[j].content);
				
				right[j].count = temp;
				strcpy(right[j].content, tempch);
			}

		}
	}
}
