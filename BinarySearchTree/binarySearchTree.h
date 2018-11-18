//
// Created by Andy on 2018/10/29.
//

#ifndef BINARYSEARCHTREE_BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_BINARYSEARCHTREE_H

#include <iostream>
#include <queue>

template <typename Key, typename Value>
class BST
{
private:
    struct Node
    {
        Key key;
        Value value;
        Node* left, right;

        Node(Key k, Value v) : key(k), value(v)
        {
            this->left = this->right = nullptr;
        }
    };

    Node* root;
    int count;

public:
    BST() : root(nullptr), count(0) {}
    ~BST() {   destroy(root);   }

    int size() { return count; }
    int empty() { return count == 0; }

    void insert(Key key, Value value)
    {
        root = recursiveInsert(root, key, value);   // 递归实现
        // non_RecursiveInsert(root, key, value);   //非递归实现
    }

    bool contain(Key key)
    {
        return contain(root, key);                //递归实现
        // return non_RecursiveInsert(root, key); //非递归实现
    }

    Value* search(Key key)
    {
        return search(root, key);                   //递归实现
        // return nonRecursiveSearch(root, key);    //非递归实现
    }

    void preOrder()
    {
        preOrder(root);
    }

    void inOrder()
    {
        inOrder();
    }

    void postOrder()
    {
        postOrder(root);
    }

    void levelOrder()
    {
        levelOrder(root);
    }

    Key minimum()
    {
        assert(count != 0);
        Node* node = root;
        while(node->left != nullptr) node = node->left;
        return node->key;
    }

    Key maximum()
    {
        assert(count != 0);
        Node* node = root;
        while(node->right != nullptr) node = node->right;
        return node->key;
    }

    void removeMin()
    {
        if(root != nullptr)
            root = removeMin(root);
    }

    void removeMax()
    {
        if(root != nullptr)
            root = removeMax(root);
    }

    void remove(Key key)
    {
        root = remove(root, key);
    }

private:
    Node* recursiveInsert(Node* node, Key key, Value value)
    {   // 向以node为根的树中插入
        // 返回插入完成后树的根
        if(node == nullptr)
        {
            ++count;
            return new Node(key, value);
        }

        if(key < node->key)
            node->left = insert(node->left, key, value);
        else if(key > node->key)
            node->right = insert(node->right, key, value);
        else
            node->value = value;

        return node;
    }
    void non_RecursiveInsert(Node* node, Key key, Value value)
    {
        while(node)
        {
            if(key > node->key)
                node = node->left;
            else if(key > node->key)
                node = node->right;
            else
                node->value = value;
        }
        node = new Node(key, value);
    }

    bool contain(Node* node, Key key)
    {
        if(node == nullptr) return false;

        if(key > node->key)
            return contain(node->right, key);
        else if(key < node->key)
            return contain(node->left);
        else
            return true;
    }
    bool nonRecursiveContain(Node* node, Key key)
    {
        while(node)
        {
            if(key > node->key)
                node = node->right;
            else if(key < node->key)
                node = node->left;
            else
                return true;
        }
        return false;
    }

    Value* search(Node* node, Key key)
    {
        if(node == nullptr)
            return nullptr;

        if(key > node->key)
            return search(node->right);
        else if(key < node->key)
            return search(node->left, key);
        else
            return &node->value;
    }
    Value* nonRecursiveSearch(Node* node, Key key)
    {
        while(node)
        {
            if(key > node->key)
                node = node->right;
            else if(key < node->key)
                node = node->left;
            else
                return &node->value;
        }
        return nullptr;
    }

    void preOrder(Node* node)
    {
        if(node != nullptr)
        {
            std::cout<< node->key <<std::endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }

    void inOrder(Node* node)
    {
        if(node != nullptr)
        {
            inOrder(node->left);
            std::cout<< node->key <<std::endl;
            inOrder(node->right);
        }
    }

    void postOrder(Node* node)
    {
        if(node != nullptr)
        {
            preOrder(node->left);
            preOrder(node->right);
            std::cout<< node->key <<std::endl;
        }
    }

    void destroy(Node* node)
    {   //析构
        //后序，先释放孩子，再释放自己，
        if(node != nullptr)
        {
            destroy(node->left);
            destroy(node->right);

            delete(node);
            --count;
        }
    }

    void levelOrder(Node* node)
    {
        if(node == nullptr)
            return;

        std::queue<Node*> q;
        q.push(node);

        while(!q.empty())
        {
            Node* n = q.front(); q.pop();

            std::cout<< n->key << std::endl;
            if(n->left != nullptr)
                q.push(n->left);
            if(n->right != nullptr)
                q.push(n->right);
        }
    }

    Node* removeMin(Node* node)
    {
        if(node->left == nullptr)
        {
            Node* rightNode = node->right;
            delete node;
            --count;
            return rightNode;
        }
        node->left = removeMin(node->left);
        return node;
    }

    Node* removeMax(Node* node)
    {
        if(node->right == nullptr)
        {
            Node* leftNode = node->left;
            delete node;
            --count;
            return leftNode;
        }
        node->right = removeMax(node->right);
        return node;
    }

    Node* remove(Node* node, Key key)
    {
        // TO-DO
    }
};

#endif //BINARYSEARCHTREE_BINARYSEARCHTREE_H
