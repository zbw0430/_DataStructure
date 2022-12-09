//
//  Sort.c
//  Sort
//
//  Created by 暖暖 on 2022/12/9.
//

#include "Sort.h"

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
