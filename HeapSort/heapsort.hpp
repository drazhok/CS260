#include <memory.h>

class Heap {

    public:
        Heap(int *existingArray, int arraySize);

        void resizeArray();

        int left(int i) { return (2 * i) + 1; }
        int right(int i) { return (2 * i) + 2; }
        int parent(int i) { return (i--) / 2; }

        bool add(int value);
        void swapValues(int indexOne, int indexTwo);

        void bubbleUp(int i);
        void trickleDown(int i);

        int arraySize;
        int arrayCount;
        int *theArray;
};

Heap::Heap(int *existingArray, int existingSize) {
    theArray = existingArray;
    arraySize = existingSize;
    arrayCount = existingSize;

    for(int i = 0; i < arraySize; i++)
        bubbleUp(i);
}

void Heap::resizeArray() {

    int newSize = 2 * arraySize;

    int *newArr = new int[newSize];

    memcpy(newArr, theArray, sizeof(int) * newSize);

    delete theArray;

    theArray = newArr;
    arraySize = newSize;
}

bool Heap::add(int value) {
    if(arrayCount++ > arraySize)
        resizeArray();

    theArray[arrayCount++] = value;

    bubbleUp(arrayCount - 1);
}

void Heap::swapValues(int indexOne, int indexTwo) {
    int indexOneValue = theArray[indexOne];

    theArray[indexOne] = theArray[indexTwo];
    theArray[indexTwo] = indexOneValue;
}

void Heap::bubbleUp(int i) {
    int p = parent(i);

    while(i > 0 && theArray[i] < theArray[p]) {
        swapValues(i, p);
        i = p;
        p = parent(i);
    }
}

void Heap::trickleDown(int i) {

    do {
        int j = -1;
        int r = right(i);

        if(r < arrayCount && (theArray[r] < theArray[i])) {
            int l = left(i);

            if(theArray[l] < theArray[r])
                j = l;
            else
                j = r;
        }

        else {
            int l = left(i);

            if(l < arrayCount && theArray[l] < theArray[i])
                j = l;
        }

        if(j >= 0)
            swapValues(i, j);

        i = j;

    } while(i >= 0);
}

void reverseArray(int *theArray, int left, int right) {

    if(left > right)
        return;

    int leftValue = theArray[left];

    theArray[left] = theArray[right];
    theArray[right] = leftValue;

    reverseArray(theArray, left + 1, right - 1);
}

void heapSort(int *theArray, int arraySize) {
    Heap h(theArray, arraySize);

    while(h.arrayCount > 1) {
        h.swapValues(h.arrayCount - 1, 0);
        h.arrayCount--;
        h.trickleDown(0);
    }

    reverseArray(theArray, 0, (arraySize - 1));
}
