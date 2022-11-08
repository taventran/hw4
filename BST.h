#pragma once
#include <iostream>
#include <string>

using namespace std;

struct info {
    string data;
    info* left;
    info* right;
    info(string d) {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};

class BST {
    private:
        info* root;
    public:
        BST() {root=nullptr;};
        info* getRoot() {return root;};
        void insert(string data, info* root);
        void inOrderTraversal(info*);
        void preOrderTraversal(info*);
        void postOrderTraversal(info*);
};