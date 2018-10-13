//
// Created by Andy on 2018/10/7.
//

#ifndef SORT_MERGESORT_H
#define SORT_MERGESORT_H

#include <algorithm>
#include "insertionSort.h"

template <typename T>
void __merge(T arr[], T tmpArr[], int l, int mid, int r) //[l, mid]  [mid+1, r]
{
    int i = l, j = mid + 1;
    for (int k = l; k <= r; ++k)
    {
        if      (i > mid)           tmpArr[k] = arr[j++];
        else if (j > r)             tmpArr[k] = arr[i++];
        else if (arr[i] <= arr[j])  tmpArr[k] = arr[i++];
        else  /*(arr[i]>arr[j])*/   tmpArr[k] = arr[j++];
    }
    for (int i = l; i <= r; ++i)
        arr[i] = tmpArr[i];
}

template <typename T>
void __mergeSort(T arr[], T tmpArr[], int l, int r)  //[l, r]
{
    if (r - l <= 15){   //改进一：可以改变0的值，在较小规模使用插入排序以改进性能
        insertionSort(arr, l, r);
        return;
    }

    int mid = l + (r-l)/2;
    __mergeSort(arr, tmpArr, l, mid);
    __mergeSort(arr, tmpArr, mid+1, r);
    if (arr[mid] > arr[mid+1]) //改进二： 两边非已经相对有序才做归并
        __merge(arr, tmpArr, l, mid, r);
}

template <typename T>
void recursiveMergeSort(T arr[], int n)  //自顶向下（递归）
{
    T* tmpArr = new T[n];
    __mergeSort(arr, tmpArr, 0, n-1);
    delete[] tmpArr;
}

template <typename T>
void iterationMergeSort(T arr[], int n) //自底向上（迭代）
{
    T* tmpArr = new T[n];
    for (int sz = 1; sz <= n; sz *= 2)
        for (int i = 0; i + sz < n; i += 2*sz)
            //对arr[i,...,i+sz-1] 和 arr[i+sz,...,i+2sz-1] 进行归并
            __merge(arr, tmpArr, i, i + sz - 1, std::min(i + 2*sz -1, n-1));  //std::min 是为了处理最后一个区间
    delete[] tmpArr;
}


#endif //SORT_MERGESORT_H
