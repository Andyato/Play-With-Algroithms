//
// Created by Andy on 2018/10/4.
//

#ifndef SORT_INSERTIONSORT_H
#define SORT_INSERTIONSORT_H

template <typename T>
void insertionSort(T arr[], int n)
{
    for ( int i = 1; i < n; ++i)
    {
        T curr = arr[i]; int j;
        for ( j = i; j >= 1 && curr < arr[j-1]; --j)
            arr[j] = arr[j-1];
        arr[j] = curr;
    }
}

template <typename T>
void insertionSort(T arr[], int l, int r) //高级排序小规模优化用
{
    for (int i = l+1; i <= r; ++i)
    {
        T curr = arr[i]; int j = 0;
        for (j = i; j > l && curr < arr[j-1]; --j)
            arr[j] = arr[j-1];
        arr[j] = curr;
    }

}

#endif //SORT_INSERTIONSORT_H
