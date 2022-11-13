//
//  main.c
//  Stack
//
//  Created by 暖暖 on 2022/11/11.
//

#include "Stack.h"
#include "Queue.h"

void test1()
{
    Stack st;
    StackInit(&st);
    // 入栈
    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);
    StackPush(&st, 4);
    StackPush(&st, 5);
    
    printf("%d\n", StackTop(&st));
    printf("size:%d\n", st._top);
        
    // 出栈
    StackPop(&st);
    StackPop(&st);
    printf("%d\n", StackTop(&st));
    
    // 销毁栈
    StackDestroy(&st);

}


void test2()
{
    Queue q;
    // 初始化队列
    QueueInit(&q);
    // 队尾入队列
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    QueuePush(&q, 4);
    
    printf("%d\n", QueueSize(&q));
    printf("%d\n", QueueEmpty(&q));
    printf("%d\n", QueueFront(&q));
    printf("%d\n", QueueBack(&q));

    while (!QueueEmpty(&q))
    {
        printf("%d ", QueueFront(&q));
        QueuePop(&q);
    }
    printf("\n");

    printf("%d\n", QueueSize(&q));
    printf("%d\n", QueueEmpty(&q));
}

int main()
{
    //test1();
    
    test2();

    return 0;
}

