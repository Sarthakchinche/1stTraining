#include<iostream>

using namespace std;
int main()
{
int a[100],freq[100];
int size,i,j,count,visited=-1;
	
	cout<<"Enter size of array \n";
	cin>>size;
	cout<<"Enter the numbers to get frequency\n";
	for(i=0;i<size;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<size;i++)
	{ 
		count=1;
		for(j=i+1;j<size;j++)
		{
			if(a[i]==a[j])
			{
				count++;
				freq[j]=visited;
			}
			if(freq[i]!=visited)
			freq[i]=count;
		}
	}
cout<<"Frequency of all elements \n";
		for(i=0;i<size;i++)
		{
			if(freq[i]!=visited){
			cout<<a[i]<<"-"<<freq[i];}
		}
return 0;
}
