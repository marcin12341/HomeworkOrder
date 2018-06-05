#include <iostream>

#include "MaxHeap.h"

using namespace std;

int main() {
    int n;
    char c;
    MaxHeap *heap = new MaxHeap[1000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> c;
        switch (c) {
            case 'a': {                                 // Add element with value to the group
                int group, value;
                scanf("%i %i", &group, &value);
                heap[group].insert(value);
                break;
            }
            case 'e': {                                 // Extract element with maximum value
                int group;                              // from the group and print it's value
                scanf("%i", &group);
                heap[group].extractMax();
                break;
            }
            case 'p': {                                 // Print values of all elements in
                int group;                              // the group according to their decreasing
                scanf("%i", &group);
                heap[group].printSorted(heap[group].size);
                break;
            }
            case 'm': {                                 // Merge groups 1 and 2. Group 1 should
                int group1, group2;                     // contain all elements. Group 2 should become empty
                scanf("%i %i", &group1, &group2);
                heap[group1].merge(heap[group2]);
                break;
            }
            case 'i': {                                 // Increase value of element in group from oldValue to newValue
                int group, oldValue, newValue;
                scanf("%i %i %i", &group, &oldValue, &newValue);
                heap[group].increaseKey(oldValue, newValue);
                break;
            }
            default:
                break;
        }
    }
    return 0;
}