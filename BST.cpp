#include "BST.h"
#include <iostream>

using namespace std;

void BST::insertNode(string data) {
    info* newNode = new info();
    newNode->data = data;
    newNode->left = newNode->right = nullptr;
    insert(root, newNode);
}

void BST::insert(info*& root, info*& newNode) { 
  if (root == nullptr) {
    root = newNode;
  } 
  else if (newNode->data <= root->data) {
    insert(root->left, newNode);
  } 
  else {
    insert(root->right, newNode);
  }

   
}

void BST::inOrderTraversal(info* root) {
    std::cout << "DOES THIS RUN" << std::endl;
    if (root != nullptr) {
        inOrderTraversal(root->left);
        cout << root->data << endl;
        inOrderTraversal(root->right);
    }
}

void BST::preOrderTraversal(info* root) {
    if (root != nullptr) {
        cout << root->data;
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }

}

void BST::postOrderTraversal(info* root) {
    if (root != nullptr) {
        postOrderTraversal(root->left);
        postOrderTraversal(root->right);
        cout << root->data;
    }
}
