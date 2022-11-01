//
//  main.c
//  SList
//
//  Created by 暖暖 on 2022/11/1.
//

#include "SList.h"

int main()
{
    SListNode* slt = NULL;
    SListPushBack(&slt, 1);
    SListPushBack(&slt, 2);
    SListPushBack(&slt, 3);
    SListPrint(slt);
    
    SListPushFront(&slt, 4);
    SListPushFront(&slt, 5);
    SListPushFront(&slt, 6);
    SListPrint(slt);
    return 0;
}
