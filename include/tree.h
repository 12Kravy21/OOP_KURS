// Piece for tree working

#ifndef TREE_H
#define TREE_H
#include <iostream>

class Node {
private:
    std::string eng;
    std::string rus;
    Node* left;
    Node* right;
    int balance;

public:
    Node(std::string en, std::string ru)
        : eng(en), rus(ru), left(nullptr), right(nullptr), balance(0)
    {
    }
    friend class BinaryTree;
    friend class AVL;
};

class BinaryTree {
protected:
    Node* root;
    virtual void AVLTree(Node*& head, std::string en, std::string ru) = 0;
    virtual void DeleteAVL(std::string x, Node*& p) = 0;
    int TreeSize(Node* head);
    void DestroyRecursive(Node*& leaf);

public:
    BinaryTree() : root(nullptr)
    {
    }
    ~BinaryTree();
    void LeftToRight(Node* head);
    void UpToDown(Node* head);
    int FindKey(Node* head, std::string key);
    int HeightTree(Node* head);
    Node* ReturnRoot();
};

#endif