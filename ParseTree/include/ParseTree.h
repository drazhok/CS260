#ifndef Parser_h
#define Parser_h

#include <string>
#include "node.h"

class ParseTree {

    public:
        ParseTree(std::string expression);

        void parsePostOrder(std::string expression);

        std::string preOrder();
        std::string inOrder();
        std::string postOrder();

        std::string recInOrder(node *currentNode);
        std::string recPreOrder(node *currentNode);
        std::string recPostOrder(node *currentNode);

        bool isOperand(char value);
        bool isOperator(char value);

        void ANNIHILATE(node *currentNode);

        ~ParseTree();

    private:
        node *root;

        const char SPACE = ' ';
        const char LPAREN = '(';
        const char RPAREN = ')';
};

#endif
