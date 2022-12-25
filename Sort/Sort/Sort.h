//
//  Sort.h
//  Sort
//
//  Created by 暖暖 on 2022/12/9.
//

#ifndef Sort_h
#define Sort_h

#include <stdio.h>

//插入排序
void InsertSort(int* a, int n);
//希尔排序
void ShellSort(int* a, int n);
void Shell_Sort(int* a, int n);

//选择排序
void SelectSort(int* a, int n);

//冒泡排序
void BubbleSort(int* a, int n);
//快速排序
void QuickSort(int* a, int begin, int end);
//快排两步优化
void QuickSort_2(int* a, int begin, int end);

#endif /* Sort_h */
