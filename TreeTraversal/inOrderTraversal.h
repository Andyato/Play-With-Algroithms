//
// Created by Andy on 2018/11/26.
//

#ifndef TREETRAVERSAL_INORDERTRAVERSAL_H
#define TREETRAVERSAL_INORDERTRAVERSAL_H

#include <iostream>
#include <stack>
#include "TestHelper.h"
using namespace std;

void __inRecursiveTraversal(TreeNode* root)
{
    if(!root)
        return;

    __inRecursiveTraversal(root->left);
    std::cout << root->val << " " ;
    __inRecursiveTraversal(root->right);
}

void inRecursiveTraversal(TreeNode* root)
{
    __inRecursiveTraversal(root);
    std::cout << std::endl;
}

void inTraversal(TreeNode* root)
{
    if(!root)
        return;

    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty())
    {
        TreeNode* currNode = stk.top();

        if()
    }
}

#endif //TREETRAVERSAL_INORDERTRAVERSAL_H
