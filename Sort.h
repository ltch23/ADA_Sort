#ifndef SORT_H
#define SORT_H

#include <vector>
#include <iostream>
using namespace std;

template<class T>
class Sort
{
	private:
		int tam;

	public:
		
		Sort(int _tam);
		void print(T* list);
		void generator(T* list);

		void bubleSort(T* list);
		
        void insertionSort(T* list);
  		
  		void quickSort(T* list, T left, T right);
  		T partQuick(T* list, T left, T right);

  		void mergeSort(T* list, T left, T right);
  		void partMerge(T* list, T left, T mid, T right);
  		
};

template<class T>
Sort<T>::Sort(int _tam)
{
    tam = _tam ;
}
template<class T>
void Sort<T>::generator(T * list)
{
srand(time (NULL));
for(int i=0;i<tam;i++)
    *(list+i)=rand()% tam +1;
}
template<class T>
void Sort<T>::print(T* list)
{
    for (int i=0 ; i<tam ;i++)
        cout << *(list+i)<< " " ;
    cout << endl;
}
template<class T>
void Sort<T>::bubleSort(T* list)
{
    cout << "BubleSort"<< endl;
    int i ,j;
    for(i=0; i<tam-i ; i++)
        for (j=0 ; j<tam ; j++)
            if ( *(list+j+1) < *(list+j))
                swap(*(list+j),*(list+j+1));
}
template<class T>
void Sort<T>::insertionSort(T * list)
{
    cout << "InesertionSort" <<endl;
    int i,j,tmp;
    for (i=0;i<tam;i++)
    {
        tmp=*(list+i);
        j=i-1;
        for(j>=0;*(list+j)>tmp;j--)
            *(list+j+1)=*(list+j);
        *(list+j+1)=tmp;
    }
}

template<class T>
T Sort<T>::partQuick(T* list, T left, T right)
    {
    T pivot = *(list + left);
    while (true)
    {
        while (*(list + left) < pivot)
        left++;
        while (*(list + right) > pivot)
        right--;
        if (left < right)
           swap( *(list + left),  *(list + right));
        else
        return right;
    }   
}
template<class T>
void Sort<T>::quickSort(T* list1, T left, T right)
{
    if(left < right)
    {
    T pivot = partQuick(list1, left, right);
        if(pivot > 1)
            quickSort(list1, left, pivot - 1);
        if(pivot + 1 < right)
            quickSort(list1, pivot + 1, right);
    }
}
template<class T>
void Sort<T>::partMerge(T *list, T left, T right, T mid)
{   
    T i = left;T j = mid + 1;
    T k = left; T tmp[tam];

    while (i <= mid and j <= right)
    {
        if (*(list+i) < *(list+j))
        {   *(tmp+k) = *(list+i);
            i++;}
        else
        {   *(tmp+k) = *(list+j);
            j++;}
    k++;
    }
    while (i <= mid)
        *(tmp+ k++)= *(list+ i++);
    while (j <= right) 
        *(tmp+ k++) = *(list+ j++);
    for (i = left; i < k; ++i)
        *(list+ i) = *(tmp+i);
}

template<class T>
void Sort<T>::mergeSort(T *list, T left, T right)
{
    T mid;
    if (left < right)
    {
        mid = (left + right) / 2;
        mergeSort(list, left, mid);
        mergeSort(list, mid + 1, right);
        partMerge(list, left, right, mid);
    }
}



#endif // SORT_H