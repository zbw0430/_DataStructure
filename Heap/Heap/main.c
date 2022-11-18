//
//  main.c
//  Heap
//
//  Created by 暖暖 on 2022/11/18.
//

#include "Heap.h"

void test()
{
    int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
    Heap hp;
    HeapInit(&hp);
    for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
    {
        HeapPush(&hp, array[i]);
    }
    HeapPrint(&hp);
    HeapDestory(&hp);
}

int main()
{
    test();
    return 0;
}
