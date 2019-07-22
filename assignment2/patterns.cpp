#include<iostream>
using namespace std;
class Pattern{
public:
void pat1()
{
	int i,j,a=5;
	for(i=0;i<5;i++)
	{
		for(j=0;j<9;j++)
		{
			if(j==i || j==8-i){
				cout<<a;
			}
			else{
				cout<<"_";
			}
		}a=a-1;
		cout<<"\n";
	}
}
public:
void pat2()
{
	int i,j,a=1;
	for(i=0;i<4;i++)
	{
		for(j=0;j<4;j++)
		{
			if(j>=3-i){
				cout<<a;
				a++;
			}
			else{
				cout<<" ";
			}
		}
		cout<<"\n";
	}
}
public:
void pat3()
{
	int i,j,a=5;
	for(i=0;i<5;i++)
	{
		for(j=0;j<9;j++)
		{
			if(j<=i || j>=8-i){
				cout<<"*";
			}
			else{
				cout<<" ";
			}
		}a=a-1;
		cout<<"\n";
	}
}
};
int main()
{
	Pattern p;
	p.pat1();
	cout<<endl;
	p.pat2();
	cout<<endl;
	p.pat3();
}