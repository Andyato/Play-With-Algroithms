//
// Created by Andy on 2018/11/26.
//

#ifndef TREETRAVERSAL_POSTORDERTRAVERSAL_H
#define TREETRAVERSAL_POSTORDERTRAVERSAL_H

#include <iostream>
#include "TestHelper.h"

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




#endif //TREETRAVERSAL_POSTORDERTRAVERSAL_H
