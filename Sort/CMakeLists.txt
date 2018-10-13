cmake_minimum_required(VERSION 3.12)
project(Sort)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Sort
    bubbleSort.h
    insertionSort.h
    main.cpp
    mergeSort.h
    quickSort.h
    selectionSort.h
    shellSort.h
    SortTestHelper.h heapSort.h)
