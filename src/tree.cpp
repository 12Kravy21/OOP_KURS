// Realization of piece for tree working

#include "tree.h"
#include <iostream>

BinaryTree::~BinaryTree()
{
    DestroyRecursive(BinaryTree::root);
}

void BinaryTree::LeftToRight(Node* head)
{
    if (head) {
        LeftToRight(head->left);
        std::cout << head->eng << "\t---\t" << head->rus << "\n";
        LeftToRight(head->right);
    }
}

void BinaryTree::UpToDown(Node* head)
{
    if (head) {
        std::cout << head->eng << "\t---\t" << head->rus << "\n";
        UpToDown(head->left);
        UpToDown(head->right);
    }
}

int BinaryTree::HeightTree(Node* head)
{
    if (head) {
        return 1
                + (HeightTree(head->left) > HeightTree(head->right)
                           ? HeightTree(head->left)
                           : HeightTree(head->right));
    } else
        return 0;
}

Node* BinaryTree::ReturnRoot()
{
    return BinaryTree::root;
}

int BinaryTree::TreeSize(Node* head)
{
    if (head) {
        return 1 + TreeSize(head->left) + TreeSize(head->right);
    } else
        return 0;
}

int BinaryTree::FindKey(Node* head, std::string key)
{
    while (TreeSize(head)) {
        if (head->eng < key) {
            head = head->right;
        } else if (head->eng > key) {
            head = head->left;
        } else if (head->eng == key) {
            break;
        }
    }
    if (head) {
        return 1;
    } else {
        return 0;
    }
}

void BinaryTree::DestroyRecursive(Node*& leaf)
{
    if (leaf) {
        DestroyRecursive(leaf->left);
        DestroyRecursive(leaf->right);
        delete *&leaf;
    }
}