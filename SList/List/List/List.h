//
//  List.h
//  List
//
//  Created by 暖暖 on 2022/11/9.
//

#ifndef List_h
#define List_h

#include <stdio.h>
#include "stdlib.h"
#include "assert.h"
#include <stdbool.h>

#endif /* List_h */

// 带头+双向+循环链表增删查改实现
typedef int LTDataType;
typedef struct ListNode
{
    LTDataType data;
    struct ListNode* next;
    struct ListNode* prev;
}LTNode;
 

//开辟节点
LTNode* BuyListNode(LTDataType x);

//初始化
LTNode* LTInit();

//打印
void LTPrint(LTNode* phead);

//尾插
void LTPushBack(LTNode* phead, LTDataType x);

//尾删
void LTPopBack(LTNode* phead);

//头插
void LTPushFront(LTNode* phead, LTDataType x);

//头删
void LTPopFront(LTNode* phead);

//查找
LTNode* LTFind(LTNode* phead, LTDataType x);

// 在pos之前插入x
void LTInsert(LTNode* pos, LTDataType x);

// 删除pos位置
void LTErase(LTNode* pos);

//判空
bool LTEmpty(LTNode* phead);

//长度
size_t LTSize(LTNode* phead);

//销毁
void LTDestroy(LTNode* phead);
