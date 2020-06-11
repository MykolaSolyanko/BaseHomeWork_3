#pragma once
struct BinaryTree {
  int data{};
  BinaryTree *left{nullptr};
  BinaryTree *right{nullptr};
};

void InputElement(BinaryTree *&tree, int data);

void PrintTree(BinaryTree *tree);

void DeleteElement(BinaryTree *&tree, int element);