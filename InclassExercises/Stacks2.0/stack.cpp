//
// Created by Bryce on 2022-02-04.
//

#include "stack.h"
#include <iostream>

Stack::~Stack() {
        Node* node = m_top;
        while(node != nullptr) {
            Node* temp = node;
            node = node->m_next;
            delete temp;
        }
    }
void Stack::push(Grade num) {
        auto new_node = new Node();
        new_node->m_data = num;
        new_node->m_next = m_top;
        m_top = new_node;
    }
Grade Stack::peek() {
        if(m_top != nullptr) {
            return m_top->m_data;
        } else {
            return{-1,-1};
        }
    }

void Stack::pop() {
        if(m_top != nullptr) {
            auto node = m_top;
            m_top = m_top->m_next;
            delete node;
        }
        else {
            std::cout << "there are no more nodes to remove..." << std::endl;
        }
    }

std::ostream& operator<<(std::ostream& output, Stack& stack) {
    auto node = stack.m_top;
    while(node != nullptr) {
        output << node->m_data << " ";
        node = node->m_next;
    }
    return output;
}