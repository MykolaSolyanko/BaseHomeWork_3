#include "binaryTree.h"
#include <iostream>
BinaryTree::BinaryTree(const BinaryTree& rhs) {
    LoggerSingleton::Log()->Info("Copy constructor");
    if (!rhs.tree_) {
        return;
    }
    node* copy = rhs.tree_;
    while (copy->left) {
        input(copy->data);
        copy = copy->left;
    }
    while (copy->right) {
        input(copy->data);
        copy = copy->right;
    }
}

void BinaryTree::clear(node* tree) {
    if (tree == nullptr) {
        return;
    }
    if (tree->left == nullptr && tree->right == nullptr) {
        delete tree;
        return;
    }
    if (tree->left != nullptr) {
        clear(tree->left);
    }
    if (tree->right != nullptr) {
        clear(tree->right);
    }
}

BinaryTree::~BinaryTree() {
    clear(tree_);
    delete tree_;
    LoggerSingleton::Log()->Info("Tree is cleaned");
}

void BinaryTree::input(int data) { inputElement(tree_, data); }

void BinaryTree::inputElement(node*& tree, int data) {
    if (!tree) {
        tree = new node{};
        tree->data = data;
        return;
    }
    if (tree->data > data) {
        LoggerSingleton::Log()->Debug(
            "Going  left, tree data is: " + std::to_string(tree->data) +
            " data is: " + std::to_string(data));
        inputElement(tree->left, data);
    }
    else {
        LoggerSingleton::Log()->Debug(
            "Going  right, tree data is: " + std::to_string(tree->data) +
            " data is: " + std::to_string(data));
        inputElement(tree->right, data);
    }
}

void BinaryTree::print() {
    LoggerSingleton::Log()->Info("Printing tree");
    printTree(tree_);
}

static int tabs{};
void BinaryTree::printTree(const node* tree) {
    if (!tree)
        return;
    tabs++;

    if (tree->right != nullptr) {
        printTree(tree->right);
    }

    for (int i = 0; i < tabs; i++) {
        std::cout << "  ";
    }

    std::cout << tree->data << std::endl;

    if (tree->left) {
        printTree(tree->left);
    }

    tabs--;
    return;
}

void BinaryTree::remove(int element) {
    LoggerSingleton::Log()->Info("Removing element" + std::to_string(element));
    removeElement(tree_, element);
}

node* BinaryTree::findMin(node* tree) {
    node* tmp = tree;
    while (tmp && tmp->left != nullptr) {
        tmp = tmp->left;
    }

    return tmp;
}
void BinaryTree::removeElement(node*& tree, int element) {
    if (tree == nullptr) {
        return;
    }

    if (tree->data < element) {
        removeElement(tree->right, element);
    }
    else if (tree->data > element) {
        removeElement(tree->left, element);
    }
    else {

        if (tree->left == nullptr) {
            node* tmp = tree;
            tree = tree->right;
            delete tmp;
        }
        else if (tree->right == nullptr) {
            node* tmp = tree;
            tree = tree->left;
            delete tmp;
        }
        else {
            node* tmp = findMin(tree->right);
            tree->data = tmp->data;
            removeElement(tree->right, tmp->data);
        }
    }
}
