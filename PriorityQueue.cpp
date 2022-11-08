#include "PriorityQueue.h"

void PriorityQueue::push(string command, string data, int num) {
    node* temp = new node();
    temp->priority = num;
    temp->data = data;
    temp->command = command;

    if (isEmpty()) {
        head = temp;
        return;
    }

    if (head->priority > temp->priority) { // New head
        temp->next = head;
        head = temp;
        return;
    }

    node* cur = head;
    node* prev = nullptr;

    while (cur->next != nullptr) {
        if (cur->priority > temp->priority) { // Insert somewhere in middle of list
            prev->next = temp;
            temp->next = cur;
            return;
        }
        prev = cur;
        cur = cur->next;
    }

    if (cur->priority > temp->priority) { // insert right before tail
        prev->next = temp;
        temp->next = cur;
        return;
    }

    cur->next = temp; // New tail
}

node* PriorityQueue::pop() {
    if (!isEmpty()) {
        node* temp = head;
        head = head->next;
        return temp;
    }
    return nullptr;
}

