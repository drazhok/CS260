#ifndef TEXTCLASS_H
#define TEXTCLASS_H

class TextClass {
    public:
        TextClass();
        void insertHead(char);
        void insertTail(char);
        char deleteHead();
        char deleteTail();
        bool isEmpty();
        bool findKey(char value);
        bool insertKey(char value);
        bool deleteIter();
        bool deleteKey(char value);
        std::string displayList();
        void appendList(TextClass &list);
        ~TextClass();

    private:
        struct node;
        struct node *head;
        struct node *tail;
        struct node *iter;
};

#endif
