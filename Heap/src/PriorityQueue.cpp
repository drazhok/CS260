#include "PriorityQueue.h"

// Initializes the heap to the default size or
// a custom size depending on the validity of
// the given size.
PriorityQueue::PriorityQueue(int size) {
    heap = (size <= 0) ? new Heap(0) : new Heap(size);
}

// Inserts a new value into the
// 'priority queue'
void PriorityQueue::insert(int value) {
    heap->insert(value);
}

// Peeks at the largest value
int PriorityQueue::peek() {
    return heap->largest();
}

// Removes the largest value and returns it
int PriorityQueue::remove() {
    return heap->remove();
}

// Deletes the heap when done
PriorityQueue::~PriorityQueue() {
    delete heap;
}
