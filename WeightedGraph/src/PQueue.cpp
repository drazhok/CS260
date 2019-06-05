#include "PQueue.h"
#include <memory.h>
#include <iostream>

PQueue::PQueue() {
    theArray = new Edge*[10];
    arrayCount = 0;
    arraySize = 10;
    lowestWIndex = 0;
    firstAdd = true;
}

void PQueue::findLowest() {
    for(int i = 0; i < arrayCount; i++)
        if(theArray[i]->weight <= theArray[lowestWIndex]->weight)
            lowestWIndex = i;
}

void PQueue::resizeArray() {

    Edge **temp = new Edge*[2 * arraySize];

    memcpy(temp, theArray, (2 * arraySize) * sizeof(theArray));

    delete[] theArray;

    theArray = temp;
}

bool PQueue::addEdge(Edge *toAdd) {

    if(arrayCount >= arraySize)
        resizeArray();

    theArray[arrayCount] = toAdd;

    arrayCount++;

    if(firstAdd)
        firstAdd = false;

    else {
        if(toAdd->weight < theArray[lowestWIndex]->weight)
            lowestWIndex = arrayCount - 1;
    }

    return true;
}

Edge *PQueue::removeEdge() {

    Edge *toRemove = theArray[lowestWIndex];

    for(int i = lowestWIndex; i < arrayCount; i++)
        theArray[i] = theArray[i + 1];

    arrayCount--;

    int lowest = 0;

    for(int i = 0; i < arrayCount; i++) {
        if(theArray[i]->weight < theArray[lowest]->weight)
            lowest = i;
    }

    lowestWIndex = lowest;

    return toRemove;
}

bool PQueue::addQueue(Edge *toAdd) {

    for(int i = 0; i < arrayCount; i++) {
        if((theArray[i]->endIndex == toAdd->endIndex) && (theArray[i]->weight > toAdd->weight)) {
            theArray[i] = toAdd;

            if(theArray[lowestWIndex]->weight > toAdd->weight)
                lowestWIndex = i;

            return true;
        }
    }

    return addEdge(toAdd);
}

PQueue::~PQueue() {
    delete[] theArray;
}
