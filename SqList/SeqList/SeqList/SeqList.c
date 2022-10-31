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

void SLCheckCapacity(SeqList* ps)
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
}


//尾插
void SeqListPushBack(SeqList* ps, SLDateType x)
{
//    assert(ps);
//    if(ps->size == ps->capacity)
//    {
//        size_t newCapacity = ps->capacity == 0 ? 4 : 2 * ps->capacity;
//        SLDateType* tmp = (SLDateType*)realloc(ps->a, newCapacity * sizeof(SLDateType));
//        if(tmp == NULL)
//        {
//            perror("realloc failed");
//            exit(-1);
//        }
//        ps->a = tmp;
//        ps->capacity = newCapacity;
//    }
    SLCheckCapacity(ps);
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

// 顺序表查找
int SeqListFind(SeqList* ps, SLDateType x)
{
    assert(ps);
    for(int i = 0; i < ps->size; i++)
    {
        if(ps->a[i] == x)
            return i;
    }
    return -1;
}

// 顺序表在pos位置插入x
void SeqListInsert(SeqList* ps, size_t pos, SLDateType x)
{
    SLCheckCapacity(ps);
    assert(pos >= 0);
    assert(pos <= ps->size);
    for(int i = ps->size-1; i >= pos; i--)
    {
        ps->a[i+1] = ps->a[i];
    }
    ps->a[pos] = x;
    ps->size++;
}

// 顺序表删除pos位置的值
void SeqListErase(SeqList* ps, size_t pos)
{
    assert(ps);
    assert(pos >= 0);
    assert(pos <= ps->size);
    for(int i = pos+1; i < ps->size; i++)
    {
        ps->a[i-1] = ps->a[i];
    }
    ps->size--;
}
