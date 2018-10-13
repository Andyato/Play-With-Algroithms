//
// Created by Andy on 2018/10/4.
//

#ifndef SORT_SELECTIONSORT_H
#define SORT_SELECTIONSORT_H

template <typename T>
void selectionSort(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
    {
        int minIndex = i;
        for (int j = i+1; j < n; ++j)
            if (arr[minIndex] > arr[j])
                minIndex = j;

        swap(arr[i], arr[minIndex]);
    }
}

#endif //SORT_SELECTIONSORT_H
