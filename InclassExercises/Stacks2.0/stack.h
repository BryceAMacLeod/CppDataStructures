//
// Created by Bryce on 2022-02-04.
//

#ifndef STACKS2_0_STACK_H
#define STACKS2_0_STACK_H
#include <iostream>
#include "grade.h"

class Node {
public:
    Grade m_data{-1,-1};
    Node *m_next{nullptr};
};

class Stack {
private:
    Node *m_top{nullptr};

public:
    Stack()= default;
    virtual ~Stack();
    void push(Grade num);
    Grade peek();
    void pop();
    friend std::ostream& operator<<(std::ostream& output, Stack& stack);
};


#endif //STACKS2_0_STACK_H
