//
// Created by n2k on 13.03.2021.
//

#pragma once

#include <iostream>
#include <random>
#include <chrono>

struct node {
    int id;
    node* next;
};

struct list {
    node* head;

    list() : head(nullptr)
        {}
};

void build(list* l, int size);
void push_front(list* l, int id);
void push_back(list* l, int id);
void push_before(list* l, int beforeId, int newId);
void push_after(list* l, int afterId, int newId);
int pop_front(list* l);
int pop_back(list* l);
void erase(list* l, int deleteId);
void filter(list* l);
void print(list* l);

