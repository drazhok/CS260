#include "ParseTree.h"
#include <stack>
#include <ctype.h>
#include <iostream>
#include <stdexcept>

// constructor, build tree from expression
ParseTree::ParseTree(std::string expression) {

    parsePostOrder(expression);
}

// Parses the tree in a post-order fashion
void ParseTree::parsePostOrder(std::string expression) {

    std::stack<node*> expStack;

    // Iterates through each character
    for(unsigned int i = 0; i < expression.length(); i++) {

        char value = expression[i];

        // If the value is a space, do nothing
        if(value == SPACE)
            continue;

        // If the value is an operand, push a new node containing that
        // operand and push on the stack.
        else if(isOperand(value)) {

            node *newNode = new node(value);

            expStack.push(newNode);
        }

        // If it's an operator, create a new node with the operator and pop
        // the last two nodes on the stack to add as leaves, then push on the
        // stack.
        else if(isOperator(value)) {

            node *newNode = new node(value);

            newNode->right = expStack.top();
            expStack.pop();

            newNode->left = expStack.top();
            expStack.pop();

            expStack.push(newNode);
        }

        // If the final node on the stack, set root equal to the
        // final node
        if(i == expression.length() - 1) {

            root = expStack.top();

            expStack.pop();
        }
    }
}

// Returns whether the char value is an operand or not
bool ParseTree::isOperand(char value) {

    if(isalpha(value) || isdigit(value)) return true;

    else return false;
}

// Returns whether the char value is an operator or not
bool ParseTree::isOperator(char value) {

    char operators[4] = { '+', '-', '*', '/' };

    for(int curOperator = 0; curOperator < 4; curOperator++)
        if(value == operators[curOperator]) return true;

    return false;
}

// Returns the result of traversing in-order
std::string ParseTree::inOrder() {
    return recInOrder(root);
}

// Returns the result of traversing post-order
std::string ParseTree::postOrder() {
    return recPostOrder(root);
}

// Returns the result of traversing pre-order
std::string ParseTree::preOrder() {
    return recPreOrder(root);
}

// Traverses the tree in-order
std::string ParseTree::recInOrder(node *currentNode) {

    // The base case
    if(currentNode == nullptr)
        return "";

    std::string buffer = "";

    // Only adds parenthesis if the current node is an operator
    if(isOperator(currentNode->data))
        buffer += LPAREN;

    // Recurs in an in-order fashion
    buffer += recInOrder(currentNode->left);
    buffer += currentNode->data;
    buffer += recInOrder(currentNode->right);

    if(isOperator(currentNode->data))
        buffer += RPAREN;

    // Returns the output string
    return buffer;
}

// Traverses the tree pre-order
std::string ParseTree::recPreOrder(node *currentNode) {

    if(currentNode == nullptr)
        return "";

    std::string buffer = "";

    // Recurs in a pre-order fashion
    buffer += currentNode->data;
    buffer += recPreOrder(currentNode->left);
    buffer += recPreOrder(currentNode->right);

    return buffer;
}

// Traverses the tree post-order
std::string ParseTree::recPostOrder(node *currentNode) {

    if(currentNode == nullptr)
        return "";

    std::string buffer = "";

    // Recurs in a post-order fashion
    buffer += recPostOrder(currentNode->left);
    buffer += recPostOrder(currentNode->right);
    buffer += currentNode->data;

    return buffer;
}

// Annihilates the tree (because destroying is for wimps)
void ParseTree::ANNIHILATE(node *currentNode) {

    // Thanks Alex! This is a much better solution than
    // what I had.
    if(currentNode != nullptr) {
        ANNIHILATE(currentNode->left);
        ANNIHILATE(currentNode->right);
        delete currentNode;
    }
}

ParseTree::~ParseTree() {

    ANNIHILATE(root);
}
