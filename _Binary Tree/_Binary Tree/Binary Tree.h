//
//  Binary Tree.h
//  Binary Tree
//
//  Created by 暖暖 on 2022/11/21.
//

#ifndef Binary_Tree_h
#define Binary_Tree_h

#include <stdio.h>
#include "stdlib.h"
#include "assert.h"
#include "Queue.h"

typedef char BTDataType;
 
//typedef struct BinaryTreeNode
//{
//    BTDataType _data;
//    struct BinaryTreeNode* _left;
//    struct BinaryTreeNode* _right;
//}BTNode;
 
BTNode* BuyNode(BTDataType c);
// 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
BTNode* BinaryTreeCreate(BTDataType* a, int n, int* pi);
// 二叉树销毁
void BinaryTreeDestory(BTNode** root);
// 二叉树节点个数
int BinaryTreeSize(BTNode* root);
// 二叉树叶子节点个数
int BinaryTreeLeafSize(BTNode* root);
//求树的高度
int TreeHeight(BTNode* root);
// 二叉树第k层节点个数
int BinaryTreeLevelKSize(BTNode* root, int k);
// 二叉树查找值为x的节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x);
// 二叉树前序遍历
void BinaryTreePrevOrder(BTNode* root);
// 二叉树中序遍历
void BinaryTreeInOrder(BTNode* root);
// 二叉树后序遍历
void BinaryTreePostOrder(BTNode* root);
// 层序遍历
void BinaryTreeLevelOrder(BTNode* root);
// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root);

#endif /* Binary_Tree_h */

