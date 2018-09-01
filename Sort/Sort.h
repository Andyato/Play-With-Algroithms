#ifndef SORT_H
#define SORT_H

#include<vector>
using namespace std;

template <typename T>
class Sort 
{
public:
    void insertSort(vector<T>& data);
    void binaryInsertSort(vector<T>& data);
    void selectSort(vector<T>& data);
    void bubbleSort(vector<T>& data);

private:
    inline void swap(vector<T>& data, int a, int b);

};

template <typename T> 
void Sort<T>::swap(vector<T>& data, int a, int b)
{
    T temp = data[a];
    data[a] = data[b];
    data[b] = temp;
}

template <typename T>
void Sort<T>::insertSort(vector<T>& data)
{
    int length = data.size(); 
    for (int i = 1; i < length; ++i)
    {   
        T curr = data[i];
        int j = i;
        for(; j > 0 && curr < data[j-1]; --j)
                data[j] =  data[j-1];
        data[j] = curr;
    }
}

template <typename T>
void Sort<T>::binaryInsertSort(vector<T>& data)
{
    int length = data.size();
    T curr; 
    int lo, hi, mid;
    for (int i = 0; i < length; ++i)
    {
        curr = data[i];
        lo = 0; hi = i-1;
        while(lo <= hi)
        {
            mid = lo + (hi-lo)/2;
            if (curr < data[mid])
                hi = mid - 1;
            else 
                lo = mid + 1;
        }
        for (int j = i-1; j > hi; --j)
            data[j+1] = data[j];
        data[hi+1] = curr;
    }
}

template <typename T>
void Sort<T>::selectSort(vector<T>& data)
{
    int length = data.size();
    for (int i = 0; i < length-1; ++i)
    {
        int min = i;
        for (int j = i+1; j < length; ++j)
            if (data[j] < data[min]) min = j;
        if(min == i) continue;
        swap(data, i, min);
    }
}

template <typename T>
void Sort<T>::bubbleSort(vector<T>& data)
{
    int length = data.size();
    for(int i = 0; i < length; ++i)
        for (int j = length; j > i; --j)
            if(data[j] < data[j-1]) swap(data, j, j-1);
}

#endif