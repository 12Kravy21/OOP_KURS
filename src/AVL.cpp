// Realization of AVL trees
#include "AVL.h"

// adding

void AVL::LeftLeftRotation(Node*& head)
{
    Node* q = head->left;
    q->balance = 0;
    head->balance = 0;
    head->left = q->right;
    q->right = head;
    head = q;
    AVL::increase = false;
}

void AVL::LeftRightRotation(Node*& head)
{
    Node* q = head->left;
    Node* r = q->right;
    if (r->balance < 0) {
        head->balance = 1;
    } else {
        head->balance = 0;
    }
    if (r->balance > 0) {
        q->balance = -1;
    } else {
        q->balance = 0;
    }
    r->balance = 0;
    head->left = r->right;
    q->right = r->left;
    r->left = q;
    r->right = head;
    head = r;
    AVL::increase = false;
}

void AVL::RightRightRotation(Node*& head)
{
    Node* q = head->right;
    q->balance = 0;
    head->balance = 0;
    head->right = q->left;
    q->left = head;
    head = q;
    AVL::increase = false;
}

void AVL::RightLeftRotation(Node*& head)
{
    Node* q = head->right;
    Node* r = q->left;
    if (r->balance > 0)
        head->balance = -1;
    else
        head->balance = 0;
    if (r->balance < 0)
        q->balance = 1;
    else
        q->balance = 0;
    r->balance = 0;
    head->right = r->left;
    q->left = r->right;
    r->left = head;
    r->right = q;
    head = r;
    AVL::increase = false;
}

void AVL::AVLTree(Node*& head, std::string en, std::string ru)
{
    if (!head) {
        head = new Node(en, ru);
        // head-> = key;
        AVL::increase = true;
    } else if (head->eng > en) {
        AVLTree(head->left, en, ru);
        if (AVL::increase) {
            if (head->balance > 0) {
                head->balance = 0;
                AVL::increase = false;
            } else if (head->balance == 0) {
                head->balance = -1;
            } else if (head->left->balance < 0) {
                LeftLeftRotation(head);
            } else {
                LeftRightRotation(head);
            }
        }
    } else if (head->eng < en) {
        AVLTree(head->right, en, ru);
        if (AVL::increase) {
            if (head->balance < 0) {
                head->balance = 0;
                AVL::increase = false;
            } else if (head->balance == 0) {
                head->balance = 1;
            } else if (head->right->balance > 0) {
                RightRightRotation(head);
            } else {
                RightLeftRotation(head);
            }
        }
    }
}

void AVL::AddToAVL(std::string en, std::string ru)
{
    Node*& head = AVL::root;
    AVLTree(head, en, ru);
}

// delete

void AVL::DeleteInAVL(std::string en)
{
    Node*& head = AVL::root;
    DeleteAVL(en, head);
}

void AVL::LeftLeftRotationSpec(Node*& head)
{
    Node* q;

    q = head->left;
    if (q->balance == 0) {
        q->balance = 1;
        head->balance = -1;
        AVL::decrease = false;
    } else {
        q->balance = 0;
        head->balance = 0;
    }
    head->left = q->right;
    q->right = head;
    head = q;
}

void AVL::RightRightRotationSpec(Node*& head)
{
    Node* q;

    q = head->right;
    if (q->balance == 0) {
        q->balance = -1;
        head->balance = 1;
        AVL::decrease = false;
    } else {
        q->balance = 0;
        head->balance = 0;
    }
    head->right = q->left;
    q->left = head;
    head = q;
}

void AVL::BalanceLeft(Node*& head)
{
    if (head->balance == -1) {
        head->balance = 0;
    } else if (head->balance == 0) {
        head->balance = 1;
        AVL::decrease = false;
    } else if (head->balance == 1) {
        if (head->right->balance >= 0)
            RightRightRotationSpec(head);
        else
            RightLeftRotation(head);
    }
}

void AVL::BalanceRight(Node*& head)
{
    if (head->balance == 1) {
        head->balance = 0;
    } else if (head->balance == 0) {
        head->balance = -1;
        AVL::decrease = false;
    } else if (head->balance == -1) {
        if (head->left->balance <= 0) {
            LeftLeftRotationSpec(head);
        } else {
            LeftRightRotation(head);
        }
    }
}

void AVL::DeleteTwoSubtrees(Node*& r, Node*& q)
{
    if (r->right) {
        DeleteTwoSubtrees(r->right, q);
        if (AVL::decrease) {
            BalanceRight(r);
        }
    } else {
        q->eng = r->eng;
        q->rus = r->rus;
        q = r;
        r = r->left;
        AVL::decrease = true;
    }
    delete r;
}

void AVL::DeleteAVL(std::string x, Node*& head)
{
    Node* q = nullptr;
    if (!head) {
        // AVL::decrease = false;
    } else {
        if (x < head->eng) {
            DeleteAVL(x, head->left);
            if (AVL::decrease == true) {
                BalanceLeft(head);
            }
        } else {
            if (x > head->eng) {
                DeleteAVL(x, head->right);
                if (AVL::decrease == true) {
                    BalanceRight(head);
                }
            } else {
                q = head;
                if (q->left == NULL) {
                    head = q->right;
                    AVL::decrease = true;
                } else {
                    if (q->right == NULL) {
                        head = q->left;
                        AVL::decrease = true;
                    } else {
                        DeleteTwoSubtrees(q->left, q);
                        if (AVL::decrease == true) {
                            BalanceLeft(head);
                        }
                    }
                    delete q;
                }
            }
        }
    }
}