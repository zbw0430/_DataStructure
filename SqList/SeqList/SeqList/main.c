//
//  main.c
//  SeqList
//
//  Created by 暖暖 on 2022/10/26.
//

#include "SeqList.h"

void TestSeqList()
{
    SeqList sl;
    SeqListInit(&sl);
    SeqListPushBack(&sl, 1);
    SeqListPushBack(&sl, 2);
    SeqListPushBack(&sl, 3);
    SeqListPushBack(&sl, 4);
    SeqListPushBack(&sl, 5);
    SeqListPrint(&sl);
    
    SeqListPopBack(&sl);
    SeqListPopBack(&sl);
    SeqListPopBack(&sl);
    SeqListPrint(&sl);
    SeqListDestroy(&sl);
}

int main()
{
    TestSeqList();
    return 0;
}
