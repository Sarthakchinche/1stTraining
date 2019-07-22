#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	string str;
	cout<<"Please enter a sting for puzzle";
	getline(cin,str);
	cout<<"Hello "<<str<<" lets start the puzzle";
	int len=str.length();
	cout<<"\n You can try "<<len<<" times to solve the puzzle";
	cout<<"\nEnter a character to find a letter similar to your string";
	for(int i=0;i<str.length();i++)
	{
		
	}
	
	return 0;
}
