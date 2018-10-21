/********************************
*Filename:hash.h		*
*Login:by932			*								
*AssignmentNo:ass4		*
*DateLastModified:19/10/2014	*							
********************************/
#include <iostream>
#include <cstring>
#include "list.h"
using namespace std;

struct htnode
{
   LIST data;
};

typedef htnode* HDNPtr; 

class HT 
{  
 	public: 
  		HT();     
  		~HT();
  		void calculate(char input[]);
  		void findtop();
  		bool topten(LIST&);
  		void sort(sortnode[]); 		
	private:
		HDNPtr hashtable[SIZE];
		sortnode sortarr[10];
}; 

