#pragma once
#include <string>

using namespace std;

struct qNode {
    string data;
    qNode* next;
};

class Queue {
    private:
        qNode* head;
        qNode* tail;
    public:
        Queue() {head = tail = nullptr;};
        bool isEmpty() {return head == nullptr;};
        void push(string);
        qNode* pop();
};

