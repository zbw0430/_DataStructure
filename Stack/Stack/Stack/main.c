//
//  main.c
//  Stack
//
//  Created by 暖暖 on 2022/11/11.
//

#include "Stack.h"

int main()
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

    return 0;
}
