//
// Created by Andy on 2018/11/26.
//

#ifndef TREETRAVERSAL_LEVELORDERTRAVERSAL_H
#define TREETRAVERSAL_LEVELORDERTRAVERSAL_H

#include <iostream>
#include <queue>
#include "TestHelper.h"
using namespace std;

void levelTraversal(TreeNode* root)
{
    if(!root)
        return;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty())
    {
        TreeNode* node = q.front();
        q.pop();

        cout << node->val << " " ;

        if(node->left)
            q.push(node->left);
        if(node->right)
            q.push(node->right);
    }
    cout << endl;
}

#endif //TREETRAVERSAL_LEVELORDERTRAVERSAL_H
