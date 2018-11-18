//
// Created by Andy on 2018/10/29.
//

#ifndef BINARYSEARCHTREE_BINARYSEARCH_H
#define BINARYSEARCHTREE_BINARYSEARCH_H

template <typename T>
int binarySearch(T arr[], int n, T target)
{
    int l = 0, r = n-1;
    while(l <= r)
    {
        int mid = l + (r - l) / 2;

        if(target < arr[mid])
            r = mid - 1;
        else if(target > arr[mid])
            l = mid + 1;
        else
            return mid;
    }
    return -1;
}

template <typename T>
int recursiveBinarySearch(T arr[], int n, T target)
{
    __recursiveBS(arr, 0, n-1, target);
}

template <typename T>
int __recursiveBS(T arr[], int l, int r, T target)
{
    if(l > r) return -1;

    int mid = l + (r-l) / 2;
    if(arr[mid] < target)
        return __recursiveBS(arr, l, mid-1, target);
    else if(arr[mid] > target)
        return __recursiveBS(arr, mid+1, r, target);
    else
        return mid;
}

#endif //BINARYSEARCHTREE_BINARYSEARCH_H
