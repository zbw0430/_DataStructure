//
//  main.c
//  Sort
//
//  Created by 暖暖 on 2022/12/9.
//

#include "Sort.h"

void test_InsertSort()
{
    int a[] = {9,2,8,1,5,7,3,4,6};
    InsertSort(a, 9);
    for(int i = 0; i < 9; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void test_ShellSort()
{
    int a[] = {9,2,8,1,5,7,3,4,6};
    //ShellSort(a, 9);
    Shell_Sort(a, 9);
    for(int i = 0; i < 9; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void test_SelectSort()
{
    int a[] = {9,2,8,1,5,7,3,4,6};
    //ShellSort(a, 9);
    SelectSort(a, 9);
    for(int i = 0; i < 9; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void test_BubbleSort()
{
    int a[] = {9,2,8,1,5,7,3,4,6};
    BubbleSort(a, 9);
    for(int i = 0; i < 9; i++)
        printf("%d ", a[i]);
    printf("\n");
}


int main()
{
    test_InsertSort();
    test_ShellSort();
    test_SelectSort();
    test_BubbleSort();
    return 0;
}
