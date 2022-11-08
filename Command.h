#pragma once
#include "PriorityQueue.cpp"
#include "Queue.cpp"
#include "BST.cpp"
#include <string>
#include <iostream>

using namespace std;

void decode(Queue& message, string data) {
    std::cout << data << std::endl;
    message.push(data);
}


void commands(PriorityQueue& q) {
    Queue message;
    BST tree;
     
    while(!q.isEmpty()) {
        node* temp = q.pop();
        cout << temp->command << endl;
        if (temp->command == "DECODE") {
            decode(message, temp->data);
        }
        else if (temp->command == "REPLACE") {
            //cout << "REPLACE" << endl;
        }
        else if (temp->command == "ADD") {
            //cout << "ADD" << endl;
        }
        else if (temp->command == "SWAP") {
            //cout << "SWAP" << endl;
        }
        else if (temp->command == "BST") {
            std::cout << "RAN" << std::endl;
            if (message.isEmpty()) {
                continue;
            }
            string data = message.pop()->data;
            std::cout << data << std::endl;
            tree.insertNode(data);
            std::cout << "STILL WORKING?" << std::endl;
        }
        else if (temp->command == "REMOVE") {
            //cout << "REMOVE" << endl;
        }
        else {
            cout << "ERROR" << endl;
        }
    }
    
    tree.inOrderTraversal(tree.getRoot());
    
}

