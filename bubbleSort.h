//
// Created by Andy on 2018/10/7.
//

#ifndef SORT_BUBBLESORT_H
#define SORT_BUBBLESORT_H

template <typename T>
void bubbleSort(T arr[], int n)
{
    for (int i = n-1; i > 1; --i)
        for (int j = 0; j < i; ++j)
            if (arr[j+1] < arr[j]) swap(arr[j], arr[j+1]);
}

#endif //SORT_BUBBLESORT_H
