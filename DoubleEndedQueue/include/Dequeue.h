#ifndef DEQUEUE_H
#define DEQUEUE_H

class Dequeue {
    public:
        Dequeue();
        Dequeue(int newSize);
        void initialize();
        void resize();
        void addLeft(int value);
        void addRight(int value);
        int getLeft();
        int getRight();
        std::string listLeftRight();
        bool isEmpty();
        bool isFull();
        ~Dequeue();

    private:
        int *arr;
        int arrSize;
        int right;
        int left;
};

#endif
