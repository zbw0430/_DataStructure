//
//  Sort.c
//  Sort
//
//  Created by 暖暖 on 2022/12/9.
//

#include "Sort.h"

//插入排序
void InsertSort(int* a, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int end = i;
        int tmp = a[end+1];
           
        while(end >= 0)
        {
            if(tmp < a[end])
            {
                a[end+1] = a[end];
                end--;
            }
            else
            {
                break;
            }
        }
           
        a[end+1] = tmp;
    }
    
}


//希尔排序
void ShellSort(int* a, int n)
{
    int gap = n;
    while (gap > 1)
    {
        // gap = gap / 2;
        gap = gap / 3 + 1;
        
        for (int i = 0; i < n - gap; ++i)
        {
            int end = i;
            int tmp = a[end + gap];
            while (end >= 0)
            {
                if (tmp < a[end])
                {
                    a[end + gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }

            a[end + gap] = tmp;
        }

    }
}

void Shell_Sort(int* a, int n)
{
    int gap = n;
    while(gap > 1)
    {
        gap = gap/3 + 1;
        for(int i = 0; i < n-gap; i++)
        {
            int end = i;
            int tmp = a[end + gap];
            while(end >= 0)
            {
                if(tmp < a[end])
                {
                    a[end+gap] = a[end];
                    end -= gap;
                }
                else
                {
                    break;
                }
            }
            
            a[end+gap] = tmp;
        }
    }
}


//选择排序
void swap(int* a, int* b)
{
    int tmp = 0;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

void SelectSort(int* a, int n)
{
    int begin = 0;
    int end = n-1;
    
    while(begin < end)
    {
        int mini = begin;
        int maxi = begin;
        
        for(int i = begin; i <= end; i++)
        {
            if(a[i] < a[mini])
            {
                mini = i;
            }
            if(a[i] > a[maxi])
            {
                maxi = i;
            }
        }
        
        swap(&a[begin], &a[mini]);
        if(maxi == begin)
        {
            maxi = mini;
        }
        swap(&a[end], &a[maxi]);
        
        begin++;
        end--;
    }
}


//冒泡排序
void BubbleSort(int* a, int n)
{
    for(int i = 0; i < n-1; i++)
    {
        int flag = 0;
        for(int j = 0; j < n-i-1; j++)
        {
            if(a[j] > a[j+1])
            {
                swap(&a[j], &a[j+1]);
                flag = 1;
            }
        }
        
        if(flag == 0)
        {
            break;
        }
    }
}


//快速排序
void QuickSort(int* a, int begin, int end)
{
    if(begin >= end)
    {
        return;
    }
    
    int left = begin;
    int right = end;
    int key = left;
    
    while(left < right)
    {
        while(left < right && a[right] > a[key])
        {
            right--;
        }
        while(left < right && a[left] < a[key])
        {
            left++;
        }
        
        swap(&a[left], &a[right]);
    }
    
    swap(&a[left], &a[key]);
    
    QuickSort(a, begin, key-1);
    QuickSort(a, key+1, end);
}
