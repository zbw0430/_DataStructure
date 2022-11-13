//
//  Queue.c
//  Stack && Queue
//
//  Created by 暖暖 on 2022/11/13.
//

#include "Queue.h"

// 初始化队列
void QueueInit(Queue* q)
{
    assert(q);
    q->_front = NULL;
    q->_rear = NULL;
    q->size = 0;
}

// 队尾入队列
void QueuePush(Queue* q, QDataType data)
{
    assert(q);
    
    QNode* newNode = (QNode*)malloc(sizeof(QNode));
    if(newNode == NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    newNode->_data = data;
    newNode->_next = NULL;
    
    if(q->_front == NULL)
    {
        q->_front = newNode;
        q->_rear = newNode;
        q->size++;
    }
    else
    {
        q->_rear->_next = newNode;
        q->_rear = newNode;
        q->size++;
    }
}

// 队头出队列
void QueuePop(Queue* q)
{
    assert(q);
    assert(!QueueEmpty(q));
    
    QNode* del = q->_front;
    q->_front = q->_front->_next;
    free(del);
    
    if(q->_front == NULL)
    {
        q->_rear = NULL;
    }
    
    q->size--;
}

// 获取队列头部元素
QDataType QueueFront(Queue* q)
{
    assert(q);
    assert(!QueueEmpty(q));
    
    return q->_front->_data;
}

// 获取队列队尾元素
QDataType QueueBack(Queue* q)
{
    assert(q);
    assert(!QueueEmpty(q));
    
    return q->_rear->_data;
}

// 获取队列中有效元素个数
int QueueSize(Queue* q)
{
    assert(q);
    return q->size;
}

// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
int QueueEmpty(Queue* q)
{
    assert(q);
    
    return q->_front == NULL && q->_rear == NULL;
}

// 销毁队列
void QueueDestroy(Queue* q)
{
    assert(q);
    QNode* cur = q->_front;
    while(cur)
    {
        QNode* del = cur;
        cur = cur->_next;
        free(del);
    }
    q->_front = q->_rear = NULL;
    q->size = 0;
}
