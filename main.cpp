#include <iostream>
#include "Sort.h"
typedef int T;

using namespace std;


int main( )
{
	Sort<int> sort1(10);
	int op;
	cin>>op;
	if(op==1)
	sort1.bubleSort();
	else if(op==2)
	sort1.insertionSort();
	else if(op==3)
	sort1.qs();
	else
		return 0;
	sort1.print();
	

	return 0;
}

