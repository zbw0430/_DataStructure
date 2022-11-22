//
//  Binary Tree.c
//  Binary Tree
//
//  Created by 暖暖 on 2022/11/21.
//

#include "Binary Tree.h"

BTNode* BuyNode(BTDataType c)
{
    BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
    if(newNode == NULL)
    {
        perror("malloc failed");
        exit(-1);
    }
    newNode->_data = c;
    newNode->_left = newNode->_right = NULL;
    return newNode;
}


// 二叉树节点个数
int BinaryTreeSize(BTNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    
    return 1 + BinaryTreeSize(root->_left) + BinaryTreeSize(root->_right);
}

// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root)
{
    if(root == NULL)
    {
        return 0;
    }
    if(root->_left == NULL && root->_right == NULL)
    {
        return 1;
    }
    return BinaryTreeLeafSize(root->_left) + BinaryTreeLeafSize(root->_right);
}

//求树的高度
int TreeHeight(BTNode* root)
{
    if (root == NULL)
    {
        return 0;
    }

    int leftHeight = TreeHeight(root->_left);
    int rightHeight = TreeHeight(root->_right);

    return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}

// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
    if(root == NULL)
    {
        return 0;
    }
    
    if(k == 1)
    {
        return 1;
    }
    
    return BinaryTreeLevelKSize(root->_left, k-1) + BinaryTreeLevelKSize(root->_right, k-1);
    
}

// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);

// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root)
{
    //assert(root);
    if(root == NULL)
    {
        printf("NULL ");
        return;
    }
    printf("%c ", root->_data);
    BinaryTreePrevOrder(root->_left);
    BinaryTreePrevOrder(root->_right);
}

// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root)
{
    if(root == NULL)
    {
        printf("NULL ");
        return;
    }
    
    BinaryTreePrevOrder(root->_left);
    printf("%c ", root->_data);
    BinaryTreePrevOrder(root->_right);
}

// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root)
{
    if(root == NULL)
    {
        printf("NULL ");
        return;
    }
    
    BinaryTreePrevOrder(root->_left);
    BinaryTreePrevOrder(root->_right);
    printf("%c ", root->_data);
}

// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);
