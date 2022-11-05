//
//  SList.c
//  SList
//
//  Created by 暖暖 on 2022/11/1.
//

#include "SList.h"

// 动态申请一个节点
SListNode* BuySListNode(SLTDateType x)
{
    SListNode* newNode = (SListNode*)malloc(sizeof(SListNode));
    if(newNode == NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// 单链表打印
void SListPrint(SListNode* plist)
{
    SListNode* slt = plist;
    while(slt)
    {
        printf("%d->", slt->data);
        slt = slt->next;
    }
    printf("NULL\n");
}

// 单链表尾插
void SListPushBack(SListNode** pplist, SLTDateType x)
{
    SListNode* newnode = BuySListNode(x);
    if(*pplist == NULL)
    {
        *pplist = newnode;
    }
    else
    {
        SListNode* cur = *pplist;
        while(cur->next)
        {
            cur = cur->next;
        }
        cur->next = newnode;
    }
}

// 单链表的头插
void SListPushFront(SListNode** pplist, SLTDateType x)
{
    SListNode* newnode = BuySListNode(x);
    newnode->next = *pplist;
    *pplist = newnode;
}

// 单链表的尾删
void SListPopBack(SListNode** pplist)
{
    assert(*pplist);
    if((*pplist)->next == NULL)
    {
        free(*pplist);
        *pplist = NULL;
    }
    else
    {
        SListNode* cur = *pplist;
        while(cur->next->next)
        {
            cur = cur->next;
        }
        free(cur->next);
        cur->next = NULL;
    }
    
}

// 单链表头删
void SListPopFront(SListNode** pplist)
{
    assert(*pplist);
    SListNode* cur = *pplist;
    *pplist = (*pplist)->next;
    free(cur);
}

// 单链表查找
SListNode* SListFind(SListNode* plist, SLTDateType x)
{
    SListNode* cur = plist;
    while(cur)
    {
        if(cur->data == x)
            return cur;
        cur = cur->next;
    }
    return NULL;
}

// 单链表在pos位置之后插入x
// 分析思考为什么不在pos位置之前插入？
void SListInsertAfter(SListNode* pos, SLTDateType x)
{
    assert(pos);
    SListNode* newNode = BuySListNode(x);
    newNode->next = pos->next;
    pos->next = newNode;
}

// 单链表删除pos位置之后的值
// 分析思考为什么不删除pos位置？
void SListEraseAfter(SListNode* pos)
{
    assert(pos);
    if(pos->next == NULL)
        return;
    else
    {
        SListNode* del = pos->next;
        pos->next = pos->next->next;
        free(del);
        del = NULL;
    }
    
}

// 单链表的销毁
void SListDestroy(SListNode** plist)
{
    SListNode* cur = *plist;
    SListNode* next = cur->next;
    while(next)
    {
        free(cur);
        cur = next;
        next = cur->next;
    }
    *plist = NULL;
}

