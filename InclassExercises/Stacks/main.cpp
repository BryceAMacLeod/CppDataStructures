#include <iostream>

using namespace std;

class Node {
public:
    int m_data{-1};
    Node *m_next{nullptr};
};

class Stack {
private:
    Node *m_top{nullptr};

public:
    Stack() =default;
    virtual ~Stack() {
        Node* node = m_top;
        while(node != nullptr) {
            Node* temp = node;
            node = node->m_next;
            delete temp;
        }
    }
    void push(int num) {
        auto new_node = new Node();
        new_node->m_data = num;
        new_node->m_next = m_top;
        m_top = new_node;
    }
    int peek() {
        if(m_top != nullptr) {
            return m_top->m_data;
        } else {
            return -1;
        }
    }

    void pop() {
        if(m_top != nullptr) {
            auto node = m_top;
            m_top = m_top->m_next;
            delete node;
        }
        else {
            cout << "there are no more nodes to remove..." << endl;
        }
    }

    friend ostream& operator<<(ostream& output, Stack& stack);
};

ostream& operator<<(ostream& output, Stack& stack) {
    auto node = stack.m_top;
    while(node != nullptr) {
        output << node->m_data << " ";
        node = node->m_next;
    }
    return output;
}

int main() {

    Stack stack;


    cout << "test 1: add node to stack" << endl;
    cout << "-------------------------" << endl;

    stack.push(1);
    cout << stack << endl;

    cout << "test 2: add more nodes" << endl;
    cout << "----------------------" << endl;

    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    cout << stack << endl;

    cout << "test 3: take a look at the top of the stack" << endl;
    cout << "-------------------------------------------" << endl;

    cout << stack.peek() << endl;

    cout << "test 4: remove the top of the stack" << endl;
    cout << "-------------------------------------------" << endl;

    stack.pop();

    cout << stack << endl;

    cout << "test 5: remove all nodes off the stack" << endl;
    cout << "-------------------------------------------" << endl;

    stack.pop();
    stack.pop();
    stack.pop();
    stack.pop();

    cout << stack << endl;

    cout << "test 6: remove all node off an empty stack" << endl;
    cout << "-------------------------------------------" << endl;

    stack.pop();

    cout << stack << endl;

    return 0;
}
