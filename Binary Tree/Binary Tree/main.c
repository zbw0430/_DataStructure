//
//  main.c
//  Binary Tree
//
//  Created by 暖暖 on 2022/11/21.
//

#include "Binary Tree.h"

void test1()
{
    // 通过前序遍历的数组"ABD##E#H##CF##G##"构建二叉树
    BTNode* A = BuyNode('A');
    BTNode* B = BuyNode('B');
    BTNode* C = BuyNode('C');
    BTNode* D = BuyNode('D');
    BTNode* E = BuyNode('E');
    BTNode* F = BuyNode('F');
    BTNode* G = BuyNode('G');
    BTNode* H = BuyNode('H');
    
    A->_left = B;
    A->_right = C;
    B->_left = D;
    B->_right = E;
    E->_right = H;
    C->_left = F;
    C->_right = G;
    
    BinaryTreePrevOrder(A);
    printf("\n");
    BinaryTreeInOrder(A);
    printf("\n");
    BinaryTreePostOrder(A);
    printf("\n");
    
    printf("%d\n", BinaryTreeSize(A));
    printf("%d\n", BinaryTreeLeafSize(A));
    printf("%d\n", BinaryTreeLevelKSize(A, 2));
    printf("%d\n", TreeHeight(A));
    
    free(A);
    free(B);
    free(C);
    free(D);
    free(E);
    free(F);
    free(G);
    free(H);
}

int main()
{
    test1();
    return 0;
}
