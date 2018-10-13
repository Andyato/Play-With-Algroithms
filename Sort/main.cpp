#include <iostream>
#include "SortTestHelper.h"
#include "selectionSort.h"
#include "insertionSort.h"
#include "bubbleSort.h"
#include "shellSort.h"
#include "mergeSort.h"
#include "quickSort.h"
#include "heapSort.h"

using namespace std;

int main() {
    int n = 100000; //数据规模
    //选择以下arr生成方式的一种，来测试不同数据分布下各种排序算法的效率
    int* arr = SortTestHelper::generateRandomArray(n, 0, n); //随机生成的乱序数组
//    int* arr = SortTestHelper::generateRandomArray(n, 0, 10); //随机生成的包含大量重复元素的数组
//    int* arr = SortTestHelper::generateNearlyOrderdArray(n, swapTimes=10); //近乎有序的数组

    int* arr2 = SortTestHelper::copyIntArray(arr, n);
    int* arr3 = SortTestHelper::copyIntArray(arr, n);
    int* arr4 = SortTestHelper::copyIntArray(arr, n);
    int* arr5 = SortTestHelper::copyIntArray(arr, n);
    int* arr6 = SortTestHelper::copyIntArray(arr, n);
    int* arr7 = SortTestHelper::copyIntArray(arr, n);
    int* arr8 = SortTestHelper::copyIntArray(arr, n);
    int* arr9 = SortTestHelper::copyIntArray(arr, n);

    SortTestHelper::testSort("Bubble Sort", bubbleSort, arr, n);
    SortTestHelper::testSort("Selection Sort", selectionSort, arr2, n);
    SortTestHelper::testSort("Insertion Sort", insertionSort, arr3, n);
    SortTestHelper::testSort("Shell Sort", shellSort, arr4, n);
    SortTestHelper::testSort("Iteration Merge Sort", iterationMergeSort, arr5, n);
    SortTestHelper::testSort("Recursive Merge Sort", recursiveMergeSort, arr6, n);
    SortTestHelper::testSort("Quick Sort", quickSort, arr7, n);
    SortTestHelper::testSort("3 Ways Quick Sort", quickSort3Ways, arr8, n);
    SortTestHelper::testSort("Heap Sort", heapSort, arr9, n);

    delete[] arr;
    delete[] arr2;
    delete[] arr3;
    delete[] arr4;
    delete[] arr5;
    delete[] arr6;
    delete[] arr7;
    delete[] arr8;
    delete[] arr9;

    return 0;
}