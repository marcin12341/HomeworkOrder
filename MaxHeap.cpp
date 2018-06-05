//
// Created by marcin on 04.06.18.
//

#include <iostream>
#include "MaxHeap.h"

MaxHeap::MaxHeap(int cap) {
    this->tab = new int[cap];
    this->capacity = cap;
    this->size = 0;
}

void MaxHeap::buildHeap() {
    if (size == 0) {
        return;
    }
    for (int i = (size - 2) / 2; i >= 0; i--) {
        heapifyDown(size, i);
    }
}

void MaxHeap::insert(int key) {
    if (size >= capacity) {
        increaseSize();
    }
    tab[size] = key;
    heapifyUp(size);
    size++;
}

void MaxHeap::push(int key) {
    tab[size] = key;
    size++;
}

MaxHeap::~MaxHeap() {
    delete tab;
}

void MaxHeap::extractMax() {
    if (size == 0) {
        printf("na\n");
        return;
    }
    int max = tab[0];
    this->size--;
    swap(0, size);
    heapifyDown(size, 0);
    printf("%i\n", max);
}

void MaxHeap::swap(int x, int y) {
    int temp;
    temp = tab[x];
    tab[x] = tab[y];
    tab[y] = temp;
}

void MaxHeap::heapifyDown(int size, int i) {
    if (size == 0) {
        return;
    }
    int largest = i;
    if (left(i) < size && tab[left(i)] > tab[i]) {
        largest = left(i);
    }
    if (right(i) < size && tab[right(i)] >= tab[largest]) {
        largest = right(i);
    }
    if (largest != i) {
        swap(i, largest);
        heapifyDown(size, largest);
    }
}

void MaxHeap::heapifyUp(int i) {
    if (size == 0) {
        return;
    }
    while (i != 0 && tab[parent(i)] < tab[i]) {
        swap(i, parent(i));
        i = parent(i);
    }
}

void MaxHeap::increaseKey(int key1, int key2) {
    if (key1 >= key2) {
        return;
    }
    for (int i = 0; i < size; i++) {
        if (tab[i] == key1) {
            tab[i] = key2;
            return;
        }
    }
    printf("na\n");
}

void MaxHeap::increaseSize() {
    int *temp = new int[size * 2];
    for (int i = 0; i < size; i++) {
        temp[i] = tab[i];
    }
    //delete tab;
    tab = temp;
    capacity *= 2;
}

void MaxHeap::printSorted(int size) {
    int temp;
    buildHeap();
    for (int i = size - 1; i > 0; i--) {
        temp = tab[i];
        tab[i] = tab[0];
        tab[0] = temp;
        size--;
        heapifyDown(size, 0);
    }
    for (int i = this->size - 1; i >= 0; i--) {
        printf("%i ", tab[i]);
    }
    buildHeap();
}

void MaxHeap::merge(MaxHeap &heap) {
    for (int i = 0; i < heap.size; i++) {
        this->push(heap.tab[i]);
        heap.tab[i] = NULL;
    }
    this->buildHeap();
    heap.size = 0;
}


