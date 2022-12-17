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


//力扣 138. 复制带随机指针的链表
//struct Node* copyRandomList(struct Node* head)
//{
//    if(head == NULL)
//        return NULL;
//    struct Node* cur = head;
//    while(cur)
//    {
//        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
//        newNode->val = cur->val;
//        newNode->next = cur->next;
//        cur->next = newNode;
//        cur = cur->next->next;
//    }
//
//    struct Node* left = head;
//    struct Node* right = head->next;
//    while(left)
//    {
//        //struct Node* right = left->next;
//        if(left->random == NULL)
//            right->random = NULL;
//        else
//            right->random = left->random->next;
//        left = left->next->next;
//        if(left)
//            right = left->next;
//    }
//
//    cur = head;
//    struct Node* newcur = head->next;
//    struct Node* newHead = head->next;
//    while(cur)
//    {
//        //struct Node* newcur = cur->next;
//        cur->next = newcur->next;
//        cur = cur->next;
//        if(newcur->next)
//            newcur->next = newcur->next->next;
//        else
//            newcur->next = NULL;
//        newcur = newcur->next;
//    }
//
//    return newHead;
//}


//力扣 20. 有效的括号
//bool isValid(char * s)
//{
//    int len = strlen(s);
//    char Stack[len];
//    int top = 0;
//    char num;
//
//    for(int i = 0; i< len; i++)
//    {
//        if(s[i] == '(' || s[i] == '[' || s[i] == '{') Stack[top++] = s[i];
//        else
//        {
//            if(top == 0) return false;
//            num = Stack[--top];
//            if(s[i] == ')' && num != '(') return false;
//            if(s[i] == ']' && num != '[') return false;
//            if(s[i] == '}' && num != '{') return false;
//        }
//    }
//
//    if(top != 0) return false;
//    return true;
//}


//力扣 225. 用队列实现栈
//#define QDataType int
//typedef struct QListNode
//{
//    struct QListNode* _next;
//    QDataType _data;
//}QNode;
//
//// 队列的结构
//typedef struct Queue
//{
//    QNode* _front;
//    QNode* _rear;
//    int size;
//}Queue;
//
//// 初始化队列
//void QueueInit(Queue* q);
//// 队尾入队列
//void QueuePush(Queue* q, QDataType data);
//// 队头出队列
//void QueuePop(Queue* q);
//// 获取队列头部元素
//QDataType QueueFront(Queue* q);
//// 获取队列队尾元素
//QDataType QueueBack(Queue* q);
//// 获取队列中有效元素个数
//int QueueSize(Queue* q);
//// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
//int QueueEmpty(Queue* q);
//// 销毁队列
//void QueueDestroy(Queue* q);
//
//
//// 初始化队列
//void QueueInit(Queue* q)
//{
//    assert(q);
//    q->_front = NULL;
//    q->_rear = NULL;
//    q->size = 0;
//}
//
//// 队尾入队列
//void QueuePush(Queue* q, QDataType data)
//{
//    assert(q);
//
//    QNode* newNode = (QNode*)malloc(sizeof(QNode));
//    if(newNode == NULL)
//    {
//        perror("malloc failed");
//        exit(-1);
//    }
//    newNode->_data = data;
//    newNode->_next = NULL;
//
//    if(q->_front == NULL)
//    {
//        q->_front = newNode;
//        q->_rear = newNode;
//        q->size++;
//    }
//    else
//    {
//        q->_rear->_next = newNode;
//        q->_rear = newNode;
//        q->size++;
//    }
//}
//
//// 队头出队列
//void QueuePop(Queue* q)
//{
//    assert(q);
//    assert(!QueueEmpty(q));
//
//    QNode* del = q->_front;
//    q->_front = q->_front->_next;
//    free(del);
//
//    if(q->_front == NULL)
//    {
//        q->_rear = NULL;
//    }
//
//    q->size--;
//}
//
//// 获取队列头部元素
//QDataType QueueFront(Queue* q)
//{
//    assert(q);
//    assert(!QueueEmpty(q));
//
//    return q->_front->_data;
//}
//
//// 获取队列队尾元素
//QDataType QueueBack(Queue* q)
//{
//    assert(q);
//    assert(!QueueEmpty(q));
//
//    return q->_rear->_data;
//}
//
//// 获取队列中有效元素个数
//int QueueSize(Queue* q)
//{
//    assert(q);
//    return q->size;
//}
//
//// 检测队列是否为空，如果为空返回非零结果，如果非空返回0
//int QueueEmpty(Queue* q)
//{
//    assert(q);
//
//    return q->_front == NULL && q->_rear == NULL;
//}
//
//// 销毁队列
//void QueueDestroy(Queue* q)
//{
//    assert(q);
//    QNode* cur = q->_front;
//    while(cur)
//    {
//        QNode* del = cur;
//        cur = cur->_next;
//        free(del);
//    }
//    q->_front = q->_rear = NULL;
//    q->size = 0;
//}
//
//
//
//typedef struct
//{
//    Queue q1;
//    Queue q2;
//} MyStack;
//
//
//MyStack* myStackCreate()
//{
//    MyStack* obj = (MyStack*)malloc(sizeof(MyStack));
//    QueueInit(&obj->q1);
//    QueueInit(&obj->q2);
//
//    return obj;
//}
//
//void myStackPush(MyStack* obj, int x)
//{
//    if(!QueueEmpty(&obj->q1))
//    {
//        QueuePush(&obj->q1, x);
//    }
//    else
//    {
//        QueuePush(&obj->q2, x);
//    }
//}
//
//int myStackTop(MyStack* obj)
//{
//    if(!QueueEmpty(&obj->q1))
//    {
//        return QueueBack(&obj->q1);
//    }
//    else
//    {
//        return QueueBack(&obj->q2);
//
//    }
//}
//
//int myStackPop(MyStack* obj)
//{
//    int ret = myStackTop(obj);
//
//    Queue* empty = &obj->q1;
//    Queue* nonempty = &obj->q2;
//    if(!QueueEmpty(&obj->q1))
//    {
//        empty = &obj->q2;
//        nonempty = &obj->q1;
//    }
//
//    while(QueueSize(nonempty) > 1)
//    {
//        QueuePush(empty,QueueFront(nonempty));
//        QueuePop(nonempty);
//    }
//
//    QueuePop(nonempty);
//
//    return ret;
//
//}
//
//
//bool myStackEmpty(MyStack* obj)
//{
//    return QueueEmpty(&obj->q1) && QueueEmpty(&obj->q2);
//}
//
//void myStackFree(MyStack* obj)
//{
//    QueueDestroy(&obj->q1);
//    QueueDestroy(&obj->q2);
//
//    free(obj);
//    obj = NULL;
//}
//

//力扣 232. 用栈实现队列
//typedef int STDataType;
//typedef struct Stack
//{
//    STDataType* _a;
//    int _top;        // 栈顶
//    int _capacity;  // 容量
//}Stack;
//// 初始化栈
//void StackInit(Stack* ps);
//// 入栈
//void StackPush(Stack* ps, STDataType data);
//// 出栈
//void StackPop(Stack* ps);
//// 获取栈顶元素
//STDataType StackTop(Stack* ps);
//// 获取栈中有效元素个数
//int StackSize(Stack* ps);
//// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
//int StackEmpty(Stack* ps);
//// 销毁栈
//void StackDestroy(Stack* ps);
//
//// 初始化栈
//void StackInit(Stack* ps)
//{
//    assert(ps);
//    ps->_a = (STDataType*)malloc(sizeof(STDataType) * 4);
//    if(ps->_a == NULL)
//    {
//        perror("malloc failed");
//        exit(-1);
//    }
//    ps->_capacity = 4;
//    ps->_top = 0;
//}
//
//// 入栈
//void StackPush(Stack* ps, STDataType data)
//{
//    assert(ps);
//    if(ps->_capacity == ps->_top)
//    {
//        STDataType* new = (STDataType*)realloc(ps->_a, ps->_capacity*2*sizeof(STDataType));
//        if(new == NULL)
//        {
//            perror("realloc failed");
//            return;
//        }
//        ps->_a = new;
//        ps->_capacity *= 2;
//    }
//    ps->_a[ps->_top] = data;
//    ps->_top++;
//}
//
//// 出栈
//void StackPop(Stack* ps)
//{
//    assert(ps);
//    //assert(ps->_top > 0);
//    assert(!StackEmpty(ps));
//    ps->_top--;
//}
//
//// 获取栈顶元素
//STDataType StackTop(Stack* ps)
//{
//    assert(ps);
//    assert(!StackEmpty(ps));
//    return ps->_a[ps->_top-1];
//}
//
//// 获取栈中有效元素个数
//int StackSize(Stack* ps)
//{
//    assert(ps);
//    return ps->_top;
//}
//
//// 检测栈是否为空，如果为空返回非零结果，如果不为空返回0
//int StackEmpty(Stack* ps)
//{
//    assert(ps);
//
//    return ps->_top == 0;
//}
//
//// 销毁栈
//void StackDestroy(Stack* ps)
//{
//    assert(ps);
//    free(ps->_a);
//    ps->_a = NULL;
//    ps->_capacity = 0;
//    ps->_top = 0;
//}
//
//
//
//typedef struct
//{
//    Stack STpush;
//    Stack STpop;
//} MyQueue;
//
//
//MyQueue* myQueueCreate()
//{
//    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
//    StackInit(&obj->STpush);
//    StackInit(&obj->STpop);
//
//    return obj;
//}
//
//void myQueuePush(MyQueue* obj, int x)
//{
//    StackPush(&obj->STpush,x);
//}
//
//int myQueuePeek(MyQueue* obj)
//{
//    if(StackEmpty(&obj->STpop))
//    {
//        while(!StackEmpty(&obj->STpush))
//        {
//            StackPush(&obj->STpop,StackTop(&obj->STpush));
//            StackPop(&obj->STpush);
//        }
//    }
//    return StackTop(&obj->STpop);
//}
//
//int myQueuePop(MyQueue* obj)
//{
//    int ret = myQueuePeek(obj);
//    StackPop(&obj->STpop);
//    return ret;
//}
//
//bool myQueueEmpty(MyQueue* obj)
//{
//    return StackEmpty(&obj->STpush) && StackEmpty(&obj->STpop);
//}
//
//void myQueueFree(MyQueue* obj)
//{
//    StackDestroy(&obj->STpush);
//    StackDestroy(&obj->STpop);
//
//    free(obj);
//    //obj->NULL;
//}


//力扣 622. 设计循环队列
//typedef struct
//{
//    int* a;
//    int front;
//    int rear;
//    int k;
//} MyCircularQueue;
//
//
//MyCircularQueue* myCircularQueueCreate(int k)
//{
//    MyCircularQueue* obj = (MyCircularQueue*)malloc(sizeof(MyCircularQueue));
//    obj->a = (int*)malloc(sizeof(int) * (k+1));
//    obj->front = 0;
//    obj->rear = 0;
//    obj->k = k;
//    return obj;
//}
//
//bool myCircularQueueIsEmpty(MyCircularQueue* obj)
//{
//    return obj->front == obj->rear;
//}
//
//bool myCircularQueueIsFull(MyCircularQueue* obj)
//{
//    int rear = obj->rear == obj->k ? 0 : obj->rear + 1;
//    return rear == obj->front;
//}
//
//bool myCircularQueueEnQueue(MyCircularQueue* obj, int value)
//{
//    if(myCircularQueueIsFull(obj))
//        return false;
//    obj->a[obj->rear] = value;
//    obj->rear = obj->rear == obj->k ? 0 : obj->rear + 1;
//    return true;
//}
//
//bool myCircularQueueDeQueue(MyCircularQueue* obj)
//{
//    if(myCircularQueueIsEmpty(obj))
//        return false;
//    obj->front = obj->front == obj->k ? 0 : obj->front + 1;
//    return true;
//}
//
//int myCircularQueueFront(MyCircularQueue* obj)
//{
//    if(myCircularQueueIsEmpty(obj))
//        return -1;
//    return obj->a[obj->front];
//}
//
//int myCircularQueueRear(MyCircularQueue* obj)
//{
//    if(myCircularQueueIsEmpty(obj))
//        return -1;
//    int rear = obj->rear == 0 ? obj->k : obj->rear - 1;
//    return obj->a[rear];
//}
//
//void myCircularQueueFree(MyCircularQueue* obj)
//{
//    free(obj->a);
//    obj->a = NULL;
//    free(obj);
//    obj = NULL;
//}
//


//力扣 965. 单值二叉树
//bool isUnivalTree(struct TreeNode* root)
//{
//    if(root == NULL)
//        return true;
//    if(root->left)
//    {
//        if(root->val != root->left->val || !isUnivalTree(root->left))
//            return false;
//    }
//    if(root->right)
//    {
//        if(root->val != root->right->val || !isUnivalTree(root->right))
//            return false;
//    }
//    return true;
//}


//力扣 104. 二叉树的最大深度
//int maxDepth(struct TreeNode* root)
//{
//    if(root == NULL)
//        return 0;
//
//    int left = maxDepth(root->left);
//    int right = maxDepth(root->right);
//
//    return left > right ? left+1 : right+1;
//}


//力扣 100. 相同的树
//bool isSameTree(struct TreeNode* p, struct TreeNode* q)
//{
//    if(p == NULL && q == NULL)
//    {
//        return true;
//    }
//    else if(p == NULL || q == NULL)
//    {
//        return false;
//    }
//    else if(p->val != q->val)
//    {
//        return false;
//    }
//    else
//    {
//        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
//    }
//
//}


//力扣 144. 二叉树的前序遍历
//int TreeSize(struct TreeNode* root)
//{
//    return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
//}
//
//void Preorder(struct TreeNode* root, int* ret, int* i)
//{
//    if(root == NULL)
//        return;
//
//    ret[(*i)++] = root->val;
//    Preorder(root->left, ret, i);
//    Preorder(root->right, ret, i);
//}
//
//
//int* preorderTraversal(struct TreeNode* root, int* returnSize)
//{
//    *returnSize = TreeSize(root);
//    int* ret = (int*)malloc(sizeof(int) * (*returnSize));
//
//    int i = 0;
//    Preorder(root, ret, &i);
//    return ret;
//}


//力扣 226. 翻转二叉树
//struct TreeNode* invertTree(struct TreeNode* root)
//{
//    if(root == NULL)
//        return NULL;
//
//    struct TreeNode* tmp = root->left;
//    root->left = root->right;
//    root->right = tmp;
//
//    invertTree(root->left);
//    invertTree(root->right);
//
//    return root;
//}


//力扣 101. 对称二叉树
//bool isSametree(struct TreeNode* left, struct TreeNode* right)
//{
//    if(left == NULL && right == NULL)
//        return true;
//    if(left == NULL || right == NULL)
//        return false;
//    if(left->val != right->val)
//        return false;
//
//    return isSametree(left->left, right->right) &&
//                isSametree(left->right, right->left);
//
//}
//
//bool isSymmetric(struct TreeNode* root)
//{
//    if(root == NULL)
//        return true;
//
//    return isSametree(root->left, root->right);
//}


//力扣 572. 另一棵树的子树
//bool isSametree(struct TreeNode* left, struct TreeNode* right)
//{
//    if(left == NULL && right == NULL)
//        return true;
//    if(left == NULL || right == NULL)
//        return false;
//    if(left->val != right->val)
//        return false;
//
//    return isSametree(left->left, right->left) &&
//                isSametree(left->right, right->right);
//
//}
//
//bool isSubtree(struct TreeNode* root, struct TreeNode* subRoot)
//{
//    if(root == NULL)
//        return false;
//    if(isSametree(root, subRoot))
//        return true;
//
//    return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
//}


//牛客网 KY11 二叉树遍历
//#include <stdio.h>
//#include <stdlib.h>
//
//struct treeNode
//{
//    char val;
//    struct treeNode* left;
//    struct treeNode* right;
//};
//
//struct treeNode* rebuildTree(char* str, int* i)
//{
//    if(str[*i] == '#')
//    {
//        (*i)++;
//        return NULL;
//    }
//
//    struct treeNode* newNode = (struct treeNode*)malloc(sizeof(struct treeNode));
//    newNode->val = str[(*i)++];
//
//    newNode->left = rebuildTree(str, i);
//    newNode->right = rebuildTree(str, i);
//
//    return newNode;
//}
//
//void InOrder(struct treeNode* root)
//{
//    if(root == NULL)
//        return;
//
//    InOrder(root->left);
//    printf("%c ", root->val);
//    InOrder(root->right);
//}
//
//
//
//int main()
//{
//    char str[100];
//    scanf("%s", str);
//
//    int i = 0;
//    struct treeNode* Tree = rebuildTree(str, &i);
//    InOrder(Tree);
//
//    return 0;
//}


//力扣 110. 平衡二叉树
//int Height(struct TreeNode* root)
//{
//    if(root == NULL)
//        return 0;
//
//    int lh = Height(root->left);
//    int rh = Height(root->right);
//
//    return lh > rh ? (lh+1) : (rh+1);
//}
//
//bool isBalanced(struct TreeNode* root)
//{
//    if(root == NULL)
//        return true;
//
//    if(abs( Height(root->left) - Height(root->right)) > 1)
//        return false;
//
//    return isBalanced(root->left) && isBalanced(root->right);
//}

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
