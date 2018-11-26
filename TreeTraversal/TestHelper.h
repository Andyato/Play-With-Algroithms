//
// Created by Andy on 2018/11/26.
//

#ifndef TREETRAVERSAL_TESTHELPER_H
#define TREETRAVERSAL_TESTHELPER_H

#include <iostream>
#include <string>
#include <sstream>
#include <queue>
#include <algorithm>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) { }
};

namespace TestHelper
{
    void trimLeftTrailingSpaces(string& input)
    {
        input.erase( input.begin(), find_if(input.begin(), input.end(), [](int ch) {
            return !isspace(ch);
        }) );
    }

    void trimRightTrailingSpaces(string &input)
    {
        input.erase( find_if(input.rbegin(), input.rend(), [](int ch) {
            return !isspace(ch);
        }).base(), input.end() );  //base() 将reverse_iterater转换为iterater
    }

    TreeNode* stringToTreeNode(string input)
    {
        trimLeftTrailingSpaces(input);
        trimRightTrailingSpaces(input);
//        input = input.substr(1, input.length() - 2);
        if (!input.size())
            return nullptr;

        string item;
        stringstream ss;
        ss.str(input);

        getline(ss, item, ',');
        TreeNode* root = new TreeNode(stoi(item));
        queue<TreeNode*> nodeQueue;
        nodeQueue.push(root);

        while (true)
        {
            TreeNode* node = nodeQueue.front();
            nodeQueue.pop();

            if (!getline(ss, item, ','))
                break;

            trimLeftTrailingSpaces(item);
            if (item != "null")
            {
                int leftNumber = stoi(item);
                node->left = new TreeNode(leftNumber);
                nodeQueue.push(node->left);
            }

            if (!getline(ss, item, ','))
                break;

            trimLeftTrailingSpaces(item);
            if (item != "null")
            {
                int rightNumber = stoi(item);
                node->right = new TreeNode(rightNumber);
                nodeQueue.push(node->right);
            }
        }
        return root;
    }

    void prettyPrintTree(TreeNode* node, string prefix = "", bool isLeft = true)
    {
        if (node == nullptr)
        {
            cout << "Empty tree";
            return;
        }

        if(node->right)
            prettyPrintTree(node->right, prefix + (isLeft ? "│   " : "    "), false);

        cout << prefix + (isLeft ? "└── " : "┌── ") + to_string(node->val) + "\n";

        if (node->left)
        {
            prettyPrintTree(node->left, prefix + (isLeft ? "    " : "│   "), true);
        }
    }

}
#endif //TREETRAVERSAL_TESTHELPER_H
