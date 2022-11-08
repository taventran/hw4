#include "BST.h"

using namespace std;

void BST::insert(string data, info* root) { 
    info* temp = new info(data);

    if (root == nullptr) {
        root = temp;
        return;
    }

    else if (data.length() <= root->data.length()) {
       insert(data, root->left);
    }

    else if (data.length() > root->data.length()) {
        insert(data, root->right);
    }
}

void BST::inOrderTraversal(info* root) {
    if (root == nullptr) {
        return;
    }
    inOrderTraversal(root->left);
    std::cout << root->data;
    inOrderTraversal(root->right);
}

void BST::preOrderTraversal(info* root) {
    if (root == nullptr) {
        return;
    }
    std::cout << root->data;
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void BST::postOrderTraversal(info* root) {
    if (root == nullptr) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    std::cout << root->data;
}