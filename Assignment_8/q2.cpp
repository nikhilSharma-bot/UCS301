#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int a)
    {
        data = a;
        left = NULL;
        right = NULL;
    }
};

class BST
{
public:
    Node *root;
    BST() : root(NULL) {}

    Node *insert(Node *node, int x)
    {
        if (!node)
            return new Node(x);
        if (x < node->data)
            node->left = insert(node->left, x);
        else
            node->right = insert(node->right, x);
        return node;
    }

    Node *searchRec(Node *node, int x)
    {
        if (!node || node->data == x)
            return node;
        if (x < node->data)
            return searchRec(node->left, x);
        return searchRec(node->right, x);
    }

    Node *searchIter(int x)
    {
        Node *cur = root;
        while (cur && cur->data != x)
        {
            if (x < cur->data)
                cur = cur->left;
            else
                cur = cur->right;
        }
        return cur;
    }

    Node *maxElement(Node *node)
    {
        if (!node)
            return NULL;
        while (node->right)
            node = node->right;
        return node;
    }

    Node *minElement(Node *node)
    {
        if (!node)
            return NULL;
        while (node->left)
            node = node->left;
        return node;
    }

    Node *inorderSuccessor(Node *node, int x)
    {
        Node *cur = root;
        Node *succ = NULL;
        while (cur)
        {
            if (x < cur->data)
            {
                succ = cur;
                cur = cur->left;
            }
            else
                cur = cur->right;
        }
        return succ;
    }

    Node *inorderPredecessor(Node *node, int x)
    {
        Node *cur = root;
        Node *pred = NULL;
        while (cur)
        {
            if (x > cur->data)
            {
                pred = cur;
                cur = cur->right;
            }
            else
                cur = cur->left;
        }
        return pred;
    }
};

int main()
{
    BST t;
    t.root = t.insert(t.root, 8);
    t.root = t.insert(t.root, 5);
    t.root = t.insert(t.root, 10);
    t.root = t.insert(t.root, 4);
    t.root = t.insert(t.root, 7);
    t.root = t.insert(t.root, 9);
    t.root = t.insert(t.root, 11);

    Node *s1 = t.searchRec(t.root, 7);
    Node *s2 = t.searchIter(10);
    Node *mx = t.maxElement(t.root);
    Node *mn = t.minElement(t.root);
    Node *suc = t.inorderSuccessor(t.root, 7);
    Node *pre = t.inorderPredecessor(t.root, 7);

    return 0;
}
