#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct info {
    string data;
    info* left;
    info* right;

};

class BST {
    private:
        info* root;
    public:
        BST() {root=nullptr;};
        void insertNode(string data);
        info* getRoot() {return root;};
        void insert(info*& root, info*& newNode);
        void inOrderTraversal(info*, ofstream&);
        void preOrderTraversal(info*, ofstream&);
        void postOrderTraversal(info*, ofstream&);
};