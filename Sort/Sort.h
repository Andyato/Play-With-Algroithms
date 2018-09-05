#ifndef SORT_H
#define SORT_H

#include<vector>
using namespace std;

template <typename T>
class Sort 
{
public:
    void bubbleSort(vector<T> &data);
    void insertSort(vector<T> &data);
    void binaryInsertSort(vector<T> &data);  
    void shellSort(vector<T> &data);
    void selectSort(vector<T> &data);

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
void Sort<T>::bubbleSort(vector<T> &data)
{
    int length = data.size();
    for (int i = 0; i < length; ++i)
        for (int j = length; j > i; --j)
            if (data[j] < data[j - 1])
                swap(data, j, j - 1);
}

template <typename T>
void Sort<T>::selectSort(vector<T> &data)
{
    int length = data.size();
    for (int i = 0; i < length - 1; ++i)
    {
        int min = i;
        for (int j = i + 1; j < length; ++j)
            if (data[j] < data[min])
                min = j;
        if (min == i)
            continue;
        swap(data, i, min);
    }
}

template <typename T>
void Sort<T>::insertSort(vector<T>& data)
{
    int length = data.size(); 
    for (int i = 1; i < length; ++i)
    {   
        T curr = data[i];
        int j;
        for(j = i; j > 0 && curr < data[j-1]; --j)
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
void Sort<T>::shellSort(vector<T>& data) //数据越大效果越好
{
    int length = data.size();
    int h = 1;
    while (h < length/3) h = 3*h + 1;  //构建一个递增序列，更复杂的递增序列会改善最坏情况下效率，本序列取自《算法第４版》
    while (h >= 1)
    {
        for (int i = h; i < length; ++i)
            for(int j = i; j >= h && data[j-h]>data[h]; j -= h)
                swap(data, j, j-h);
        h = h / 3;
    }
}

#endif