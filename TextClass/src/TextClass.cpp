#include "TextClass.h"

TextClass::TextClass() {
    head = nullptr;
    tail = nullptr;
    iter = nullptr;
}

struct TextClass::node {
    char data;

    struct node *previous;
    struct node *next;
};

void TextClass::insertHead(char value) {

}

void TextClass::insertTail(char value) {

}

char TextClass::deleteHead() {

}

char TextClass::deleteTail() {

}

TextClass::~TextClass() {

}
