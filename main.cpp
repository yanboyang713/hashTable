/********************************
*Filename:main.cpp		*
*Login:by932			*								
*AssignmentNo:ass4		*
*DateLastModified:19/10/2014	*							
********************************/
#include <iostream>
#include <fstream>
#include <cstring>
#include "hash.h"
using namespace std;

int main()
{
	int file_len = 0;
	char source_file[20]= {'\0'};
	char data[21] = {'\0'};
	HT start;

	cout << "Enter file name? ";
	cin >> source_file;
	
	file_len = strlen(source_file);
	ifstream read;
	read.open(source_file);
	
	if(!read)
	{
		cout << "Cann't find file"<< endl;
		return 0;
	}
	else if (strcmp(source_file + file_len - 4, ".fna") == 0)
	{
		char del[1025] = {'\0'};
			
		cout << "This file is a fna file" << endl;
		read.getline (del,1024,'\n');
		while(!read.eof())
		{
			for (int i = 0; i < 21; i++)
				data[i] = '\0';
			
			for (int i = 0; i < 8; i++)
			{
				data[i] = read.get();				
				while (data[i] == ' ' || data[i] == '\n')
				{
					data[i] = read.get();
				}
				
			}
			if (!read.good())
			{
				read.ignore();
				read.clear();
				break;
			}
			start.calculate(data);
  		}
	}
	else if (strcmp(source_file + file_len - 4, ".txt") == 0)
	{
		cout << "This file is a txt file" << endl;
		
		while(!read.eof())
		{
			for (int i = 0; i < 21; i++)
				data[i] = '\0';
			
			for (int i = 0; i < 21; i++)
			{
				data[i] = read.get();
				
				if (data[i] == ' ' || data[i] == '\n')
				{
					data[i] = '\0';
					break;
				}
				
			}
			if (!read.good())
			{
				read.ignore();
				read.clear();
				break;
			}			
			start.calculate(data);	
  		}
	}
	else
	{
		cout << "This file is not a txt file OR fna file" << endl;
		return 0;
	}
	start.findtop();
			
	read.close();		
	return 0;
}

