#include <iostream>
#include "Sort.h"
typedef int T;

using namespace std;


int main( )
{

	Sort<int> sort1;
	sort1.print();
	// sort1.bubleSort();
	// sort1.insertionSort();
	sort1.qs();
	sort1.print();

	return 0;
}

