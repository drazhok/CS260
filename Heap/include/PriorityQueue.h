#include "Heap.h"

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H


class PriorityQueue
{
    public:
        PriorityQueue(int size);
        void insert(int value);
        int peek();
        int remove();
        ~PriorityQueue();

    private:
        Heap *heap;
};

#endif
