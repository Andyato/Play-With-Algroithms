#include<iostream>
#include "Sort.h"

template <typename T> void print(const vector<T>& data);
int main()
{
    vector<int> data = {2,5,8,6,4,3,0,1,7,6};
    cout << "before sort: " << endl;
    print(data);
    Sort<int> sort;
    // sort.binaryInsertSort(data);
    // sort.insertSort(data);
    sort.selectSort(data);
    // sort.bubbleSort(data);
    cout << "sorted: " << endl;
    print(data);
}

template <typename T>
void print(const vector<T> &data)
{
    for(const auto e : data)
       cout << e << " ";
    cout << endl;
}