#ifndef STACK_H
#define STACK_H

class Stack {
    public:
        Stack();
        Stack(int newSize);
        void push(int value);
        int peek();
        int pop();
        ~Stack();

    private:
        Dequeue *dequeue;
};

#endif // STACK_H
