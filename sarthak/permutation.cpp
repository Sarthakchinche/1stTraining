#include<iostream>
using namespace std;

void swap(char& a, char& b)
{
    char temp;
    temp = a;
    a = b;
    b = temp;
}

void permutation(string a,int i,int b)
{
	int j;
	if(i==b)
cout<<a<<"\t";
	else{
	for(j=i;j<a.length();j++)
	{
	swap(a[i],a[j]);
	permutation(a,i+1,b);
	swap(a[i],a[j]);
}
}
}
int main()
{
	string a;
	cout<<"Enter a string";
	cin>>a;
	cout<<endl<<"permutation is:"<<endl;
	permutation(a,0,a.length()-1);
	cout<<endl;
}
