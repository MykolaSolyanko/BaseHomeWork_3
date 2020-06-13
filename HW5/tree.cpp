#include "tree.h"
#include <iostream>
void InputElement(BinaryTree*& tree, int data) {
    if (!tree) {
        tree = new BinaryTree{};
        tree->data = data;
        return;
    }
    if (tree->data > data) {
        InputElement(tree->left, data);
    }
    else
    {
        InputElement(tree->right, data);
    }
}

static int tabs{};
void PrintTree(BinaryTree* tree)
{
    if (!tree) return;
    tabs++;

    if (tree->right!=nullptr) {
        PrintTree(tree->right);
    }
   


    for (int i = 0; i < tabs; i++) {
        std::cout << "  ";
    }

    std::cout << tree->data << std::endl;

    if (tree->left) {
        PrintTree(tree->left);
    }

    tabs--;
    return;

}

static BinaryTree* findMin(BinaryTree* tree) {

    BinaryTree* tmp = tree;
    while (tmp && tmp->left != nullptr) {
        tmp = tmp->left;
    }

    return tmp;
}


void DeleteElement(BinaryTree*& tree, int element) {
    if (tree == nullptr) {
        return;
    }

    if (tree->data<element) {
        DeleteElement(tree->right, element);
    }
    else if (tree->data > element)
    {
        DeleteElement(tree->left, element);
    }
    else{

        if (tree->left == nullptr) {
            BinaryTree *tmp = tree;
            tree = tree->right;
            delete tmp;
        }else if (tree->right == nullptr) {
            BinaryTree* tmp = tree;
            tree = tree->left;
            delete tmp;
        }
        else {
            BinaryTree* tmp = findMin(tree->right);
            tree->data = tmp->data;
            DeleteElement(tree->right, tmp->data);
        }

        
        
    }



}