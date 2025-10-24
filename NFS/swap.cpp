#include <iostream>
using namespace std;

void swap(int *x,int *y)
{
	*x = *x + *y; //20 + 120 = 140
	*y = *x - *y; //140 - 120 = 20
	*x = *x + *y; //140 -20 = 120
}

int main()
{
	int a = 17, b = 120;
	cout << a<<endl<<b<<endl<<endl;	
	
	swap(a,b);
	cout << a << endl << b;
}