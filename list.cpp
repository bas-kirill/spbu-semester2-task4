//
// Created by n2k on 13.03.2021.
//

#include "list.h"

void build(list* l, int size) {
    while (l->head != nullptr) {
        pop_front(l);
    }
    std::mt19937 gen(std::chrono::high_resolution_clock::now().time_since_epoch().count());
    for (int i = 0; i < size; ++i) {
        push_front(l, (int)gen() % 10);
    }
}

void push_front(list* l, int id) {
    node* tmp = new node;
    tmp->id = id;
    tmp->next = l->head;
    l->head = tmp;
}

void push_back(list* l, int id) {
    if (l->head == nullptr) {
        push_front(l, id);
    } else {
        node *tmp = l->head;
        while (tmp->next != nullptr) {
            tmp = tmp->next;
        }
        node* newNode = new node;
        newNode->id = id;
        newNode->next = nullptr;

        tmp->next = newNode;
    }
}

void push_before(list* l, int beforeId, int newId) {
    if (l->head == nullptr) {
        return;
    }

    if (l->head->id == beforeId) {
        push_front(l, newId);
        return;
    } else {
        node* tmp = l->head;
        node* newNode = new node;
        newNode->id = newId;

        while (tmp->next != nullptr && tmp->next->id != beforeId) {
            tmp = tmp->next;
        }

        // not found
        if (tmp->next == nullptr) {
            return;
        }

        newNode->next = tmp->next;
        tmp->next = newNode;
    }
}

void push_after(list* l, int afterId, int newId) {
    if (l->head == nullptr) {
        return;
    }

    node* tmp = l->head;
    while (tmp != nullptr && tmp->id != afterId) {
        tmp = tmp->next;
    }

    if (tmp == nullptr) {
        return;
    }

    node* newNode = new node;
    newNode->id = newId;
    newNode->next = tmp->next;
    tmp->next = newNode;
}

int pop_front(list* l) {
    if (l->head == nullptr) {
        return -1;
    }

    int result = l->head->id;
    node* tmp = l->head->next;
    delete l->head;
    l->head = tmp;
    return result;
}

int pop_back(list* l) {
    // Если список пустой, то выкидываем -1
    if (l->head == nullptr) {
        return -1;
    }

    node* prev = nullptr;
    node* tmp = l->head;
    while (tmp->next != nullptr) {
        prev = tmp;
        tmp = tmp->next;
    }

    int result = tmp->id;

    if (prev == nullptr) {
        // Nothing
    } else {
        prev->next = tmp->next;
    }
    delete tmp;
    return result;
}

void erase(list* l, int deleteId) {
    if (l->head == nullptr) {
        return;
    }

    if (l->head->id == deleteId) {
        pop_front(l);
        return;
    }

    node* prev = nullptr;
    node* tmp = l->head;
    while (tmp != nullptr && tmp->id != deleteId) {
        prev = tmp;
        tmp = tmp->next;
    }

    if (tmp == nullptr) {
        // Nothing
    } else {
        prev->next = tmp->next;
        delete tmp;
    }
}

void filter(list* l) {
    if (l->head == nullptr) {
        return;
    }

    list l1, l2;
    node* tmp = l->head;
    while (tmp != nullptr) {
        if (tmp->id > 0) {
            push_back(&l1, tmp->id);
        } else if (tmp->id < 0) {
            push_back(&l2, tmp->id);
        }
        tmp = tmp->next;
    }

    std::cout << "First list: ";
    print(&l1);
    std::cout << ";" << std::endl << "Second list: ";
    print(&l2);
    std::cout << ";" << std::endl;
}

void print(list* l) {
    node *tmp = l->head;
    bool first = true;
    std::cout << "[";
    while (tmp != nullptr) {
        if (!first) {
            std::cout << ",";
        }
        std::cout << tmp->id;
        first = false;
        tmp = tmp->next;
    }
    std::cout << "]";
}