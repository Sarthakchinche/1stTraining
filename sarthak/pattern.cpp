#include<iostream>

using namespace std;
int main()
{
int i,j;
	for(i=0;i<5;i++)
{	if(i%2!=0)
	cout<<endl;
	else
	{
	for(j=0;j<9;j++){
	if(j>=(9/2)-i && j<=(9/2)+i){
	if(j%2==0)
	cout<<"*";
	else
	cout<<" ";
}	
	else
		cout<<" ";
}cout<<endl;
	}
}	
	
return 0;
}
