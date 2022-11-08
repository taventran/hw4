#pragma once
#include "PriorityQueue.h"
#include "Queue.cpp"
#include "BST.cpp"
#include <string>
#include <iostream>

using namespace std;

void decode(Queue& message, string data) {
    message.push(data);
}


void commands(PriorityQueue& q) {
    Queue message;
    BST tree;
     
    while(!q.isEmpty()) {
        node* temp = q.pop();
        if (temp->command == "DECODE") {
            decode(message, temp->data);
        }
        else if (temp->command == "REPLACE") {
            cout << "REPLACE" << endl;
        }
        else if (temp->command == "ADD") {
            cout << "ADD" << endl;
        }
        else if (temp->command == "SWAP") {
            cout << "SWAP" << endl;
        }
        else if (temp->command == "BST") {
            tree.insert(message.pop()->data, tree.getRoot());
        }
        else if (temp->command == "REMOVE") {
            cout << "REMOVE" << endl;
        }
        else {
            cout << "ERROR" << endl;
        }
    }
    while (!message.isEmpty()) {
        cout << message.pop()->data << endl;
    }
    tree.inOrderTraversal(tree.getRoot());
}

