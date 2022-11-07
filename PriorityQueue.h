#pragma once
#include <iostream>
#include <string>

using namespace std;


struct node {
    int priority;
    string data;
    node* next;
};

class PriorityQueue {
    private:
        node* head;
    public:
        PriorityQueue() {head=nullptr;};
        void push(int, string);
        node* pop();
};