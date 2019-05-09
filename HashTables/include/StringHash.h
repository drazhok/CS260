#ifndef STRINGHASH_H
#define STRINGHASH_H

#include <iostream>

class StringHash
{
    public:
        StringHash();
        StringHash(int newSize);
        void initialize();
        void resize();
        void addItem(std::string value);
        ~StringHash();

    private:
        std::string *table;
        int tableSize;
        int itemCount;
};

#endif
