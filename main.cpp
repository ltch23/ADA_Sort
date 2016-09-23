#include "Sort.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

int main()
{
	int * list1;
	int tam, opc;
	cout<<"ingrese cantidad de numeros: ";
	cin>>tam;
	list1= new int[tam];
	Sort<int> sort1(tam);
	sort1.generator(list1);
	cout<<"Lista\n";
	sort1.print(list1);
	clock_t start = clock();
	sort1.mergeSort(list1,0,tam-1);
	clock_t end = clock();
    cout	<<"Lista Ordenada\n";sort1.print(list1);
    cout << "Time : " << double(end - start)/CLOCKS_PER_SEC <<endl;
	return 0;
}

