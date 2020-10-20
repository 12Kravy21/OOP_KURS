// Realize class AVL

#ifndef AVL_H
#define AVL_H
#include "tree.h"

class AVL : public BinaryTree {
protected:
    int increase;
    int decrease;
    void LeftLeftRotation(Node*& head);
    void LeftRightRotation(Node*& head);
    void RightRightRotation(Node*& head);
    void RightLeftRotation(Node*& head);
    void LeftLeftRotationSpec(Node*& head);
    void RightRightRotationSpec(Node*& head);
    void BalanceLeft(Node*& head);
    void BalanceRight(Node*& head);
    void DeleteTwoSubtrees(Node*& r, Node*& q);
    void DeleteAVL(std::string x, Node*& p);
    void AVLTree(Node*& head, std::string en, std::string ru);

public:
    AVL() : increase(true), decrease(true)
    {
    }
    void DeleteInAVL(std::string en);
    void AddToAVL(std::string en, std::string ru);
};

#endif
