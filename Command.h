#pragma once
#include "PriorityQueue.cpp"
#include "Queue.cpp"
#include "BST.cpp"
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

void decode(Queue& message, string data) {
    //std::cout << data << std::endl;
    message.push(data);
}

void replaceFun(Queue& message, string data) {
    string curMessage = message.pop()->data;
    char toReplace = data.at(0);
    char replaceWith = data.at(2);
    std::cout << curMessage << std::endl;
    for (int i = 0; i < curMessage.size(); i++) {
        if (curMessage.at(i) == toReplace) {
            curMessage[i] = replaceWith;
        }
    }
    std::cout << curMessage << std::endl;
    message.push(curMessage);
} 

void add(Queue& message, string data) {
    string curMessage = message.pop()->data;
    char beforeChar = data.at(0);
    char newChar = data.at(2);
    string newString = "";
    std::cout << curMessage << std::endl;
    for (int i = 0; i < curMessage.size(); i++) {
        if (curMessage.at(i) == beforeChar) {
            newString.push_back(newChar);
        }
        newString.push_back(curMessage.at(i));
    }
    std::cout << newString << std::endl;
    message.push(newString);
}

void remove(Queue& message, string data) {
    string curMessage = message.pop()->data;
    string newString = "";
    char removeData = data.at(0);
    for (int i = 0; i < curMessage.size(); i++) {
        if (curMessage.at(i) == removeData) {
            continue;
        }
        newString.push_back(curMessage.at(i));
    }
    message.push(newString);
}

void swapFun(Queue& message, string data) {
    string curMessage = message.pop()->data;
    char swapChar1 = data.at(0);
    char swapChar2 = data.at(2);
    std::cout << swapChar1 << " " << swapChar2 << std::endl;
    std::cout << curMessage << std::endl;
    for (int i = 0; i < curMessage.size(); i++) {
        if (curMessage.at(i) == swapChar2) {
            curMessage.at(i) = swapChar1;
            continue;
        }   
        if (curMessage.at(i) == swapChar1) {
            curMessage.at(i) = swapChar2;
            continue;
        }
    }
    std::cout << curMessage << std::endl;
    message.push(curMessage);
}

BST commands(PriorityQueue& q) {
    Queue message;
    BST tree;
     
    while(!q.isEmpty()) {
        node* temp = q.pop();
        cout << temp->command  << " " << temp->data << endl;
        if (temp->command == "DECODE") {
            decode(message, temp->data);
        }
        else if (temp->command == "REPLACE") {
            if (message.isEmpty()) {
                continue;
            }
            replaceFun(message, temp->data);
        }
        else if (temp->command == "ADD") {
            if (message.isEmpty()) {
                continue;
            }
            add(message, temp->data);
        }
        else if (temp->command == "SWAP") {
            if (message.isEmpty()) {
                continue;
            }
            swapFun(message, temp->data);
        }
        else if (temp->command == "BST") {
            if (message.isEmpty()) {
                continue;
            }
            string data = message.pop()->data;
            //std::cout << data << std::endl;
            tree.insertNode(data);
            //std::cout << "STILL WORKING?" << std::endl;
        }
        else if (temp->command == "REMOVE") {
            if (message.isEmpty()) {
                continue;
            }
            remove(message, temp->data);
        }
        else {
            cout << "ERROR" << endl;
        }
    }
    
    return tree;
}

