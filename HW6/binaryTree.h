#pragma once
#include "singletone.h"

struct node {
    int data{};
    node* left;
    node* right;
};

class BinaryTree {
public:
    BinaryTree() = default;
    BinaryTree(const BinaryTree& rhs);
    ~BinaryTree();
    void input(int data);
    void remove(int element);
    void print();

private:
    void inputElement(node*& tree, int data);
    void printTree(const node* tree);
    void removeElement(node*& tree, int element);
    void clear(node* tree);
    node* findMin(node* tree);
    node* tree_{};
};