#include<iostream>
using namespace std;

class A{
public:	
	void test(){
		cout<<"This is Normal function";	
	}
};
class B: public A{
public:
	virtual void test(){
		cout<<"this is virtual function";
	}
};
int main()
{
	A *pt;
	B obj;
	pt=&obj;
	pt->test();
return 0;
}
