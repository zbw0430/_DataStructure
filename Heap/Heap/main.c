//
//  main.c
//  Heap
//
//  Created by 暖暖 on 2022/11/18.
//

#include "Heap.h"

void test1()
{
    int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
    Heap hp;
    HeapInit(&hp);
    for(int i = 0; i < sizeof(array)/sizeof(array[0]); i++)
    {
        HeapPush(&hp, array[i]);
    }
    HeapPrint(&hp);
    
    HeapPop(&hp);
    HeapPrint(&hp);
    
    HeapDestory(&hp);
}

void test2()
{
    int array[] = { 27, 15, 19, 18, 28, 34, 65, 49, 25, 37 };
    Heap hp;
    HeapCreate(&hp, array, sizeof(array)/sizeof(array[0]));
    HeapPrint(&hp);
    
    // TopK问题：找出N个数里面最大/最小的前K个问题。
    // 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
    // 需要注意：
    // 找最大的前K个，建立K个数的小堆
    // 找最小的前K个，建立K个数的大堆
    
    int k = 5;
    while(k--)
    {
        printf("%d ", HeapTop(&hp));
        HeapPop(&hp);
    }
    printf("\n");
    
    HeapDestory(&hp);
}

int main()
{
    //test1();
    test2();
    return 0;
}
