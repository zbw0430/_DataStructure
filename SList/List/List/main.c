//
//  main.c
//  List
//
//  Created by 暖暖 on 2022/11/9.

#include "List.h"

int main()
{
    LTNode* phead = LTInit();
    
    LTPushBack(phead, 1);
    LTPushBack(phead, 2);
    LTPushFront(phead, 3);
    LTPushFront(phead, 4);
    LTPrint(phead);

    LTPopBack(phead);
    LTPopFront(phead);
    LTPrint(phead);

    LTNode* pos = LTFind(phead, 1);
    LTInsert(pos, 5);
    LTPrint(phead);
    pos = LTFind(phead, 5);
    LTErase(pos);
    LTPrint(phead);
    

    LTDestroy(phead);

    return 0;
}
