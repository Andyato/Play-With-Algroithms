//
// Created by Andy on 2018/10/4.
//

#ifndef SORT_SORTTESTHELPER_H
#define SORT_SORTTESTHELPER_H

#include <iostream>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

namespace SortTestHelper
{
    int* generateRandomArray(int n, int rangeL, int rangeR)
    {
        assert( rangeL <= rangeR);
        int* arr = new int[n];
        srand(time(NULL));
        for (int i = 0; i < n; ++i)
            arr[i] = rand() % (rangeR - rangeL + 1) + rangeL;
        return arr;
    }

    int* generateNearlyOrderdArray(int n, int swapTimes)
    {
        int* arr = new int[n];
        for (int i = 0; i < n; ++i)
            arr[i] = i;

        srand(time(NULL));
        for (int i = 0; i < swapTimes; ++i)
        {
            int x = rand() % n;
            int y = rand() % n;

            swap(arr[y], arr[x]);
        }
        return arr;
    }

    template <typename T>
    void printArray(T arr[], int n)
    {
        for (int i = 0; i < n; ++i)
            cout << arr[i] << " ";
        cout << endl;
    }

    template <typename T>
    bool isSorted(T arr[], int n)
    {
        for (int i = 0; i < n-1; ++i)
            if (arr[i] > arr[i+1])
                return false;
        return true;
    }

    template <typename T>
    void testSort( string sortName, void(*sort)(T[], int), T arr[], int n )
    {
        clock_t startTime = clock();
        sort(arr ,n);
        clock_t endTime = clock();

        assert( isSorted(arr,n) );
        cout << sortName << " : " << double(endTime - startTime) / CLOCKS_PER_SEC << "s" << endl;
        return;
    }

    int* copyIntArray(int a[], int n)
    {
        int* arr = new int[n];
        copy(a, a+n, arr);
        return arr;
    }
}

struct Student
{
    string name;
    int score;

    bool operator<(const Student& otherStudent)
    {
        return score < otherStudent.score;
    }

    friend ostream& operator<<(ostream& os, const Student& student)
    {
        os<<"Student: "<<student.name<<" "<<student.score<<endl;
        return os;
    }
};

#endif //SORT_SORTTESTHELPER_H
