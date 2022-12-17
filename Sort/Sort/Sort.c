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
