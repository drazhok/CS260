#ifndef ARRAYINT_H
#define ARRAYINT_H


class ArrayInt
{
    public:
        ArrayInt();
        ArrayInt(int newSize);
        void setSize(int newSize);
        int getSize();
        int getAt(int index);
        void setAt(int index, int value);
        void insertAt(int index, int value);
        int removeAt(int index);
        void append(int value);
        ~ArrayInt();

    private:
        int *arr;
        int arrSize;
        int valueCount;
        int lastValueIndex;
};

#endif
