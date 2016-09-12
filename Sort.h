#ifndef SORT_H
#define SORT_H

#include <iostream>

using namespace std;


template<class T>
class Sort
{
	private:
		int len;
		T* list=new int[10];
	
	public:
		
		Sort();
		void print();
		void bubleSort();
		//void insertionSort();
  		//void quickSort();
  		//T partQuick();
 		
};

template<class T>
Sort<T>::Sort()
{
int i,j;
len=j=10;
for( i=0;i<len;i++)
	*(list+i)=j, j--;
}

template<class T>
void Sort<T>::print()
{
for(int i=0;i<len;i++)
	cout<<*(list+i)<<" ";

std::cout<<std::endl;
}

template<class T>
void Sort<T>::bubleSort()
{
for(int i=0;i<len;i++)
	for(int j=0;j<len-i;j++)
	{
		if(*(list+j+1)<*(list+j))
			swap(*(list+j+1),*(list+j));
	}
}




#endif // SORT_H