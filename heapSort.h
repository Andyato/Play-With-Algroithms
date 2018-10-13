//
// Created by Andy on 2018/10/8.
//

#ifndef SORT_HEAPSORT_H
#define SORT_HEAPSORT_H

template <typename T>
void __shiftDown(T arr[], int n, int k);

template <typename T>
void heapSort(T arr[], int n)
{
    for (int i = (n-1)/2; i >= 0; --i)
        __shiftDown(arr, n, i);

    for (int i = n-1; i >= 1; --i)
    {
        swap(arr[0], arr[i]);
        __shiftDown(arr, i, 0);
    }
}

template <typename T>
void __shiftDown(T arr[], int n, int k)
{
    while(2*k+1 < n)
    {
        int j = 2*k+1;
        if (j+1 < n && arr[j] < arr[j+1])
            j += 1;

        if(arr[k] >= arr[j]) break;

        swap(arr[k], arr[j]);
        k = j;
    }
}

#endif //SORT_HEAPSORT_H
