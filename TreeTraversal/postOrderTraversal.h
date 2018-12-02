//
// Created by Andy on 2018/11/26.
//

#ifndef TREETRAVERSAL_POSTORDERTRAVERSAL_H
#define TREETRAVERSAL_POSTORDERTRAVERSAL_H

#include <iostream>
#include <stack>
#include "TestHelper.h"
using namespace std;

void __postRecursiveTraversal(TreeNode* root)
{
    if(!root)
        return;

    __postRecursiveTraversal(root->left);
    __postRecursiveTraversal(root->right);
    std::cout << root->val << " " ;
}

void postRecursiveTraversal(TreeNode* root)
{
    __postRecursiveTraversal(root);
    std::cout << std::endl;
}


//Non-Recursive
void postTraversal(TreeNode* root)
{
    vector<int> res;
    if(!root)
        return ;

    stack<TreeNode*> stack;
    TreeNode* pre = nullptr;
    TreeNode* cur = root;

    while(cur != nullptr || !stack.empty())
    {
        if(cur != nullptr)
        {
            stack.push(cur);
            cur = cur->left;
        }
        else
        {
            cur = stack.top();
            stack.pop();

            if(cur->right == nullptr || pre == cur->right)
            {
                cout << cur->val << " ";
                pre = cur;
                cur = nullptr;
            }
            else
            {
                stack.push(cur);
                cur = cur->right;
            }
        }
    }
    cout << endl;
}

#endif //TREETRAVERSAL_POSTORDERTRAVERSAL_H
