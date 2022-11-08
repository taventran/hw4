#include "Queue.h"

void Queue::push(string data) {
    qNode* temp = new qNode();
    temp->data = data;
    temp->next = nullptr;
    if (isEmpty()) {
        head = temp;
        tail = temp;
        return;
    }

    tail->next = temp;
    temp = tail;
    return;
}

qNode* Queue::pop() {
    qNode* temp = head;
    head = head->next;
    return temp;
}