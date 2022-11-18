//
//  Heap.c
//  Heap
//
//  Created by 暖暖 on 2022/11/18.
//

#include "Heap.h"

void swap(HPDataType* p1, HPDataType* p2)
{
    HPDataType tmp = *p1;
    *p1 = *p2;
    *p2 = tmp;
}

//向上调整
void AdjustUp(HPDataType* a, int child)
{
    assert(a);
    int parent = (child-1) / 2;
    while(child > 0)
    {
        if(a[child] > a[parent])
        {
            swap(&a[child], &a[parent]);
            child = parent;
            parent = (child-1) / 2;
        }
        else
        {
            break;
        }
    }
}

//向下调整
void AdjustDown(HPDataType* a, int size, int parent)
{
    assert(a);
    int child = parent*2 + 1;
    while(child < size)
    {
        if(child+1 < size && a[child] < a[child+1])
            child++;
        if(a[child] > a[parent])
        {
            swap(&a[child], &a[parent]);
            parent = child;
            child = parent*2 + 1;
        }
        else
        {
            break;
        }
    }
}

//堆的初始化
void HeapInit(Heap* hp)
{
    assert(hp);
    hp->a = NULL;
    hp->size = hp->capacity = 0;
}

// 堆的构建
void HeapCreate(Heap* hp, HPDataType* a, int n);

// 堆的销毁
void HeapDestory(Heap* hp)
{
    assert(hp);
    free(hp->a);
    hp->a = NULL;
    hp->size = hp->capacity = 0;
}

//打印
void HeapPrint(Heap* hp)
{
    assert(hp);
    for (int i = 0; i < hp->size; ++i)
    {
        printf("%d ", hp->a[i]);
    }
    printf("\n");
}

// 堆的插入
void HeapPush(Heap* hp, HPDataType x)
{
    assert(hp);
    //扩容
    if(hp->size == hp->capacity)
    {
        int newCapacity = hp->capacity == 0 ? 4 : hp->capacity*2;
        HPDataType* tmp = (HPDataType*)realloc(hp->a, sizeof(HPDataType) * newCapacity);
        if(tmp == NULL)
        {
            perror("realloc failed");
            exit(-1);
        }
        hp->a = tmp;
        hp->capacity = newCapacity;
    }
    
    hp->a[hp->size] = x;
    hp->size++;
    
    AdjustUp(hp->a, hp->size-1);
}

// 堆的删除
void HeapPop(Heap* hp);
// 取堆顶的数据
HPDataType HeapTop(Heap* hp);
// 堆的数据个数
int HeapSize(Heap* hp);
// 堆的判空
int HeapEmpty(Heap* hp);
 
// TopK问题：找出N个数里面最大/最小的前K个问题。
// 比如：未央区排名前10的泡馍，西安交通大学王者荣耀排名前10的韩信，全国排名前10的李白。等等问题都是Topk问题，
// 需要注意：
// 找最大的前K个，建立K个数的小堆
// 找最小的前K个，建立K个数的大堆
void PrintTopK(int* a, int n, int k);
void TestTopk();
