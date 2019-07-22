#include<iostream>
using namespace std;
int main()
{
	int a=0,b=1,c,num,i;
	cout<<"Enter a number for fibo";
	cin>>num;
	for(i=2;i<=num;i++)
	{
		c=a+b;
		cout<<c<<"\n";
		b=c;
		a=b;
	}
}
