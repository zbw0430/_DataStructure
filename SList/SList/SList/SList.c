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
