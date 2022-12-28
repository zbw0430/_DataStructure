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


//快排两步优化
// 三数取中
// begin  mid  end
int GetMidIndex(int* a, int begin, int end)
{
    int mid = (begin + end) / 2;
    if (a[begin] < a[mid])
    {
        if (a[mid] < a[end])
        {
            return mid;
        }
        else if (a[begin] > a[end])
        {
            return begin;
        }
        else
        {
            return end;
        }
    }
    else // a[begin] > a[mid]
    {
        if (a[mid] > a[end])
        {
            return mid;
        }
        else if (a[begin] < a[end])
        {
            return begin;
        }
        else
        {
            return end;
        }
    }
}

void QuickSort_2(int* a, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    
    if ((end - begin + 1) < 15)
    {
        // 小区间用直接插入替代，减少递归调用次数
        InsertSort(a+begin, end - begin + 1);
    }
    else
    {
        int mid = GetMidIndex(a, begin, end);
        swap(&a[begin], &a[mid]);
    
        int left = begin, right = end;
        int keyi = left;
        while (left < right)
        {
            // 右边先走，找小
            while (left < right && a[right] >= a[keyi])
            {
                --right;
            }
    
            // 左边再走，找大
            while (left < right && a[left] <= a[keyi])
            {
                ++left;
            }
    
            swap(&a[left], &a[right]);
        }
    
        swap(&a[left], &a[keyi]);
        keyi = left;
    
        // [begin, keyi-1]  keyi [keyi+1, end]
        QuickSort(a, begin, keyi - 1);
        QuickSort(a, keyi + 1, end);
    }
}


//快排三种方法

//Hoare
int PartSort1(int* a, int begin, int end)
{
    int mid = GetMidIndex(a, begin, end);
    swap(&a[begin], &a[mid]);

    int left = begin, right = end;
    int keyi = left;
    while (left < right)
    {
        // 右边先走，找小
        while (left < right && a[right] >= a[keyi])
        {
            --right;
        }

        // 左边再走，找大
        while (left < right && a[left] <= a[keyi])
        {
            ++left;
        }

        swap(&a[left], &a[right]);
    }

    swap(&a[left], &a[keyi]);
    keyi = left;
    
    return keyi;
}

//挖坑法
int PartSort2(int* a, int begin, int end)
{
    int mid = GetMidIndex(a, begin, end);
    swap(&a[begin], &a[mid]);

    int left = begin, right = end;
    int key = a[left];
    int hole = left;
    while (left < right)
    {
        // 右边找小，填到左边坑里面
        while (left < right && a[right] >= key)
        {
            --right;
        }

        a[hole] = a[right];
        hole = right;

        // 左边找大，填到右边坑里面
        while (left < right && a[left] <= key)
        {
            ++left;
        }

        a[hole] = a[left];
        hole = left;
    }

    a[hole] = key;
    return hole;
}

//双指针
int PartSort3(int* a, int begin, int end)
{
    int mid = GetMidIndex(a, begin, end);
    swap(&a[begin], &a[mid]);

    int keyi = begin;
    int prev = begin, cur = begin + 1;
    while (cur <= end)
    {
        // 找到比key小的值时，跟++prev位置交换，小的往前翻，大的往后翻
        if (a[cur] < a[keyi] && ++prev != cur)
            swap(&a[prev], &a[cur]);

        ++cur;
    }

    swap(&a[prev], &a[keyi]);
    keyi = prev;
    return keyi;
}

void QuickSort_3(int* a, int begin, int end)
{
    if (begin >= end)
    {
        return;
    }
    
    if ((end - begin + 1) < 15)
    {
        // 小区间用直接插入替代，减少递归调用次数
        InsertSort(a+begin, end - begin + 1);
    }
    else
    {
        //int keyi = PartSort1(a, begin, end);
        //int keyi = PartSort2(a, begin, end);
        int keyi = PartSort3(a, begin, end);
        
        // [begin, keyi-1]  keyi [keyi+1, end]
        QuickSort(a, begin, keyi - 1);
        QuickSort(a, keyi + 1, end);
    }
}
