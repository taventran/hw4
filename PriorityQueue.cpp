#include "PriorityQueue.h"

void PriorityQueue::push(int num, string line) {
    node* temp = new node();
    temp->priority = num;
    temp->data = line;

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


string PriorityQueue::pop() {
    if (!isEmpty()) {
        node* temp = head;
        string data;
        head = head->next;
        delete temp;
        return data;
    }
}