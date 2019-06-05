#include "../WGraph.h"
#include <iostream>

#ifndef PQUEUE_H
#define PQUEUE_H


class PQueue
{
    public:
        PQueue();

        void resizeArray();

        bool addEdge(Edge *toAdd);
        Edge *removeEdge();

        bool addQueue(Edge *toAdd);

        void findLowest();

        bool isEmpty() { return (arrayCount <= 0); }

        ~PQueue();

    private:
        Edge **theArray;
        int arrayCount;
        int arraySize;
        int lowestWIndex;
        bool firstAdd;
};

#endif
