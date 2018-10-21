/********************************
*Filename:list.h		*
*Login:by932			*								
*AssignmentNo:ass4		*
*DateLastModified:19/10/2014	*							
********************************/
#include <iostream>
#include "constants.h"
#include <cstring>
using namespace std;
struct node
{
	char content[21];
	int count;
	node *next;
};
typedef node* NPtr;
class LIST 
{  
 	public: 
  		LIST();   
  		LIST(const LIST&);    
  		~LIST();     
  		bool load(char input[]); 
  		bool print(ostream&);
  		NPtr returnhead();
	private: 
	  	int nonodes;    // no of nodes in LIST 
	  	NPtr head;    // pointer to list of chars
	  	NPtr next;
};



