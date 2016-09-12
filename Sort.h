#ifndef SORT_H
#define SORT_H

#include <iostream>

using namespace std;


template<class T>
class Sort
{
	private:
		int len;
		T* list=new int[len];
		T* time1 =new int [10];
		T* time2 =new int [10];
		T* time3 =new int [10];

	public:
		
		Sort(T);
		void print();
		void printq();
		void bubleSort();
	
		void insertionSort();
  		void qs();
  		void quickSort(T,T);
  		T partQuick(T,T);
 		
};

template<class T>
Sort<T>::Sort(T _len)
{
	int i,j;
	len=j=_len;
	for( i=0;i<len;i++)
	*(list+i)=j, j--;
	
	time1[0]=time1[1]=time1[2]=time1[3]=time1[4]=0;
	time2[0]=time2[1]=time2[2]=time2[3]=time2[4]=0;
	time3[0]=time3[1]=time3[2]=time3[3]=time3[4]=time3[5]=time3[6]=time3[7]=time3[8]=0;

}

template<class T>
void Sort<T>::print()
{
	for(int i=0;i<len;i++)
	cout<<*(list+i)<<" ";
	std::cout<<std::endl;
	
}

template<class T>
void Sort<T>::printq()
{	
	for (int i=0;i<8;i++)
	{
		time3[8]=time3[8]+time3[i];
		cout<<i<<" : "<< *(time3+i)<<"\n";
	}
	cout<<"complejidad: "<<time3[3]+time3[4]+time3[5]+time3[6]+time3[7]<<endl;
	cout<<"instrucciones: "<<time3[8]<<endl;
}

template<class T>
void Sort<T>::bubleSort()
{
	cout << "\tBubleSort" <<endl;
	for(int i=0;i<len;i++)
	{
	time1[0]=time1[0]+1;	
	for(int j=0;j<len-i;j++)
	{time1[1]=time1[1]+1;
		if(*(list+j+1)<*(list+j))
			swap(*(list+j+1),*(list+j)),time1[2]=time1[2]+1, time1[3]=time2[3]+1;
	}
	}

	for (int j=0;j<4;j++)
	{
	time1[4]=time1[4]+time1[j];
	cout<<j<<" : "<<time1[j]<<endl;
	}
	cout<<"complejidad: "<<time1[0]+time1[1]+time1[3]<<endl;
	cout<<"sumatoria: "<<time1[4]<<endl;
}

template<class T>
void Sort<T>::insertionSort()
{
    cout << "\tInsertionSort" <<endl;
    for (int i=0;i<len;i++)
    {
    	time2[0]=time2[0]+1;
        T tmp=*(list+i);time2[2]=time2[2]+1;
        int j=i-1;
        for(j>=0;*(list+j)>tmp;j--)
            *(list+j+1)=*(list+j),time2[1]=time2[1]+2;
        *(list+j+1)=tmp;
        time2[3]=time2[3]+1;
    }	

 	for (int j=0;j<4;j++)
	{
	time2[4]=time2[4]+time2[j];
	cout<<j<<": "<<time2[j]<<endl;
	}
	cout<<"complejidad: "<<time2[0]+time2[1]<<endl;
	cout<<"instrucciones: "<<time2[4]<<endl;
}

template<class T>
void Sort<T>::qs()
{
	cout<<"\tquickSort\n";
	quickSort(0,len-1);
	printq();
}

template<class T>
void Sort<T>::quickSort(T left, T right)
{
    if(left < right)
    {
    time3[0]=time3[0]+1;
    T pivot = partQuick(left, right);
        if(pivot > 1)
            quickSort(left, pivot - 1),time3[1]=time3[1]+1;
        if(pivot + 1 < right)
            quickSort(pivot + 1, right); time3[2]=time3[2]+1;
    }
}

template<class T>
T Sort<T>::partQuick(T left,T right)
{
T pivot = *(list + left);
while (true)
	{time3[3]=time3[3]+1;
	while (*(list + left) < pivot)
    left++,time3[4]=time3[4]+1;
    while (*(list + right) > pivot)
    right--,time3[5]=time3[5]+1;
    if (left < right)
       swap( *(list + left),  *(list + right)),time3[6]=time3[6]+1;
    else
    time3[7]=time3[7]+1;
    return right;
	}   
}


#endif // SORT_H