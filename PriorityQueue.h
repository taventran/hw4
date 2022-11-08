#pragma once
#include <iostream>
#include <string>
using namespace std;

struct node {
    int priority;
    string data;
    string command;
    node* next;
};

class PriorityQueue {
    private:
        node* head;
    public:
        PriorityQueue() {head=nullptr;};
        void push(string, string, int);
        bool isEmpty() {return head==nullptr;};
        node* pop();
};