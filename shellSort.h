//
// Created by Andy on 2018/10/7.
//

#ifndef SORT_SHELLSORT_H
#define SORT_SHELLSORT_H

template <typename T>
void shellSort(T arr[], int n)
{
    int h = 0;
    while (h < n / 3) h = 3*h + 1;
    while (h >= 1){
        for (int i = h; i < n; ++i){
            T curr = arr[i]; int j;
            for (j = i; j >=h && curr < arr[j-h] ; j -= h)
                arr[j] = arr[j-h];
            arr[j] = curr;
        }
        h /= 3;
    }
}

#endif //SORT_SHELLSORT_H
