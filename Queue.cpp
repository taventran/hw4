#include "Queue.h"

void Queue::push(string data) {
    qNode* temp = new qNode();
    temp->data = data;
    temp->next = nullptr;

    if (isEmpty()) {
        head = tail = temp;
        return;
    }

    tail->next = temp;
    tail = temp;
    return;

}

qNode* Queue::pop() {
    if (isEmpty()) {
        return nullptr;
    }

    qNode* temp = head;
    head = head->next;
    return temp;
}