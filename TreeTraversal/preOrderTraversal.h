//
// Created by Andy on 2018/11/25.
//

#ifndef TREETRAVERSAL_PREORDERTRAVERSAL_H
#define TREETRAVERSAL_PREORDERTRAVERSAL_H

#include <iostream>
#include <stack>
#include "TestHelper.h"
using namespace std;

void __preRecursiveTraversal(TreeNode* root)
{
    if (root == nullptr)
        return;

    std::cout << root->val << " " ;
    __preRecursiveTraversal(root->left);
    __preRecursiveTraversal(root->right);
}

void preRecursiveTraversal(TreeNode* root)
{
    __preRecursiveTraversal(root);
    std::cout << std::endl;
}

void preTraversal(TreeNode* root)
{
    if(!root)
        return;

    stack<TreeNode*> stk;
    stk.push(root);

    while (!stk.empty())
    {
        TreeNode* currNode = stk.top();
        stk.pop();

        cout << currNode->val << " " ;

        if(currNode->right)
            stk.push(currNode->right);
        if(currNode->left)
            stk.push(currNode->left);
    }
    cout << endl;
}

#endif //TREETRAVERSAL_PREORDERTRAVERSAL_H
