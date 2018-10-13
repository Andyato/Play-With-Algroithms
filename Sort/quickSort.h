//
// Created by Andy on 2018/10/7.
//

#ifndef SORT_QUICKSORT_H
#define SORT_QUICKSORT_H

#include <ctime>
#include <cstdlib>
using namespace std;

template <typename T>
int __partition(T arr[], int l, int r)
{
   swap( arr[l], arr[ (rand() % (r-l+1)) + l ]);  //针对基本有序数据优化

   T v = arr[l]; int i = l, j = r+1;
   while( true )
   {
       while( arr[ ++i ] < v ) ;
       while( arr[ --j ] > v ) ;

       if (i > j) break;
       swap(arr[i], arr[j]);
   }
   swap(arr[l], arr[j]);
   return j;
}

template <typename T>
void __quickSort(T arr[], int l, int r)
{
    if ( r - l <= 15) {
        insertionSort(arr, l, r);
        return;
    }

    int p = __partition(arr, l, r);
    __quickSort(arr, l, p-1);
    __quickSort(arr, p+1, r);
}

template <typename T>
void quickSort(T arr[], int n)
{
    srand(time(nullptr));
    __quickSort(arr, 0, n-1);
}

template <typename T>
void __quickSort3Ways(T arr[], int l, int r)
{
    if( r - l <= 15){
        insertionSort(arr, l, r);
        return;
    }

    //partition
    swap( arr[l], arr[ rand() % (r-l+1) + l ]);
    T v = arr[l];

    int lt = l;    //(last than)
    int gt = r+1;  //(great than)
    int i = l+1;   //判断(<v, ==v or >v)的指针
    while (i < gt)
    {
        if      (arr[i] < v) swap(arr[i++], arr[++lt]);
        else if (arr[i] > v) swap(arr[i], arr[--gt]);
        else                 ++i;
    }
    swap( arr[l], arr[lt--]);

    __quickSort3Ways(arr, l, lt);
    __quickSort3Ways(arr, gt, r);
}

template <typename T>
void quickSort3Ways(T arr[], int n)
{
    srand(time(NULL));
    __quickSort3Ways(arr, 0, n-1);
}



#endif //SORT_QUICKSORT_H
