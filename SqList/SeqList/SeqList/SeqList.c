//
//  SeqList.c
//  SeqList
//
//  Created by 暖暖 on 2022/10/26.
//

#include "SeqList.h"

//初始化
void SeqListInit(SeqList* ps)
{
    assert(ps);
    ps->a = NULL;
    ps->size = 0;
    ps->capacity = 0;
}

//销毁
void SeqListDestroy(SeqList* ps)
{
    assert(ps);
    if(ps->a)
    {
        free(ps->a);
        ps->a = NULL;
        ps->size = 0;
        ps->capacity = 0;
    }
    
}

//打印
void SeqListPrint(SeqList* ps)
{
    assert(ps);
    for(int i = 0; i < ps->size; i++)
    {
        printf("%d ", ps->a[i]);
    }
    printf("\n");
}

//尾插
void SeqListPushBack(SeqList* ps, SLDateType x)
{
    assert(ps);
    if(ps->size == ps->capacity)
    {
        size_t newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
        SLDateType* tmp = (SLDateType*)realloc(ps->a, newCapacity * sizeof(SLDateType));
        if(tmp == NULL)
        {
            perror("realloc failed");
            exit(-1);
        }
        ps->a = tmp;
        ps->capacity = newCapacity;
    }
    ps->a[ps->size] = x;
    ps->size++;
}

//尾删
void SeqListPopBack(SeqList* ps)
{
    assert(ps);
    assert(ps->size>0);
    ps->size--;
}
