#ifndef TEXTCLASS_H
#define TEXTCLASS_H


class TextClass
{
    public:
        TextClass();
        void insertHead(char);
        void insertTail(char);
        char deleteHead();
        char deleteTail();
        ~TextClass();

    private:
        struct node;
        struct node *head;
        struct node *tail;
        struct node *iter;
};

#endif // TEXTCLASS_H
