#include "BST.h"



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

void BST::inOrderTraversal(info* root, ofstream& ofs) {
    if (root != nullptr) {
        inOrderTraversal(root->left, ofs);
        ofs << root->data << endl;
        inOrderTraversal(root->right, ofs);
    }
}

void BST::preOrderTraversal(info* root, ofstream& ofs) {
    if (root != nullptr) {
        ofs << root->data << endl;
        preOrderTraversal(root->left, ofs);
        preOrderTraversal(root->right, ofs);
    }

}

void BST::postOrderTraversal(info* root, ofstream& ofs) {
    if (root != nullptr) {
        postOrderTraversal(root->left, ofs);
        postOrderTraversal(root->right, ofs);
        ofs << root->data << endl;
    }
}
