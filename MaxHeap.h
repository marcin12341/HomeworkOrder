//
// Created by marcin on 04.06.18.
//

#ifndef HOMEWORK_MAXHEAP_H
#define HOMEWORK_MAXHEAP_H


class MaxHeap {
private:
    int *tab;

    int capacity;

    int parent(int index) {
        return (index - 1) / 2;
    }

    int left(int index) {
        return (2 * index + 1);
    }

    int right(int index) {
        return (2 * index + 2);
    }

    void buildHeap();

    void push(int);

    void swap(int, int);

    void heapifyDown(int, int);

    void heapifyUp(int);

    void increaseSize();

public:

    int size;

    MaxHeap(int cap = 128);

    ~MaxHeap();

    void insert(int);

    void extractMax();

    void increaseKey(int, int);

    void printSorted(int size);

    void merge(MaxHeap &);
};


#endif //HOMEWORK_MAXHEAP_H
