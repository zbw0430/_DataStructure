//
//  main.c
//  Practice
//
//  Created by 暖暖 on 2022/11/7.
//

#include <stdio.h>

//牛客网 CM11 链表分割
//class Partition {
//public:
//    ListNode* partition(ListNode* pHead, int x)
//    {
//        // write code here
//        ListNode* minphead = (ListNode*)malloc(sizeof(ListNode));
//        ListNode* mincur = minphead;
//        minphead->next = NULL;
//        ListNode* maxphead = (ListNode*)malloc(sizeof(ListNode));
//        ListNode* maxcur = maxphead;
//        maxphead->next = NULL;
//
//        ListNode* cur = pHead;
//        while(cur)
//        {
//            if(cur->val < x)
//            {
//                mincur->next = cur;
//                mincur = cur;
//                cur = cur->next;
//            }
//            else
//            {
//                maxcur->next = cur;
//                maxcur = cur;
//                cur = cur->next;
//            }
//        }
//
//        mincur->next = maxphead->next;
//        maxcur->next = NULL;
//        ListNode* newhead = minphead->next;
//        free(minphead);
//        free(maxphead);
//        return newhead;
//    }
//};


//牛客网 OR36 链表的回文结构
//class PalindromeList {
//public:
//    //找中间节点(快慢指针)
//    ListNode* FindMidNode(ListNode* pHead)
//    {
//        ListNode* fast = pHead;
//        ListNode* slow = pHead;
//        while(fast && fast->next)
//        {
//            slow = slow->next;
//            fast = fast->next->next;
//        }
//        return slow;
//    }
//
//    //链表逆置(头插)
//    ListNode* ReverseListNode(ListNode* pHead)
//    {
//        ListNode* newNode = NULL;
//        ListNode* cur = pHead;
//
//        while(cur)
//        {
//            ListNode* next = cur->next;
//            cur->next = newNode;
//            newNode = cur;
//            cur = next;
//        }
//
//        return newNode;
//    }
//
//    bool chkPalindrome(ListNode* A)
//    {
//        // write code here
//        ListNode* midNode = FindMidNode(A);
//        ListNode* rNode = ReverseListNode(midNode);
//
//        ListNode* curA = A;
//        ListNode* currNode = rNode;
//        while(currNode)
//        {
//            if(curA->val != currNode->val)
//                return false;
//            curA = curA->next;
//            currNode = currNode->next;
//        }
//        return true;
//
//    }
//};


//力扣 160. 相交链表
//struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB)
//{
//    struct ListNode* curA = headA;
//    struct ListNode* curB = headB;
//    int lenA = 0;
//    int lenB = 0;
//
//    while(curA->next)
//    {
//        lenA++;
//        curA = curA->next;
//    }
//
//    while(curB->next)
//    {
//        lenB++;
//        curB = curB->next;
//    }
//
//    if(curA != curB)
//        return NULL;
//
//    int l = abs(lenA - lenB);
//    struct ListNode* longNode = headA;
//    struct ListNode* shortNode = headB;
//    if(lenA < lenB)
//    {
//        longNode = headB;
//        shortNode = headA;
//    }
//
//    while(l--)
//    {
//        longNode = longNode->next;
//    }
//
//    while(longNode)
//    {
//        if(longNode == shortNode)
//            return longNode;
//        longNode = longNode->next;
//        shortNode = shortNode->next;
//    }
//    return NULL;
//}


//力扣 141. 环形链表
//bool hasCycle(struct ListNode *head)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//
//    while(fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if(fast == slow)
//            return true;
//    }
//
//    return false;
//}


//力扣 142. 环形链表 II
//struct ListNode *detectCycle(struct ListNode *head)
//{
//    struct ListNode* fast = head;
//    struct ListNode* slow = head;
//
//
//    while(fast && fast->next)
//    {
//        slow = slow->next;
//        fast = fast->next->next;
//        if(fast == slow)
//        {
//            struct ListNode* n1 = head;
//            while(fast != n1)
//            {
//                n1 = n1->next;
//                fast = fast->next;
//            }
//            return fast;
//        }
//    }
//
//
//    return false;
//    
//}


int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
