#include <iostream>

using namespace std;

class Node {
public:
    int m_data{-1};
    Node *m_next{nullptr};
};

class Queue {
private:
    Node *m_first{nullptr};
    Node *m_last{nullptr};
public:
    Queue() = default;
    virtual ~Queue() {
        Node* node = m_first;
        while(node != nullptr){
            Node* temp = node;
            node = node->m_next;
            delete temp;
        }
    }

    void push(int num) {
        Node *new_node = new Node();
        new_node->m_data = num;

        // are there nodes in the queue
        if (m_first == nullptr) {
            // adding the first node
            m_first = new_node;

        } else {
            // adding to existing queue
            m_last->m_next = new_node;
        }

        // set last pointer to the new end of the queue
        m_last = new_node;
    }

    int peek() {
        // is the queue empty
        if (m_first == nullptr) {
            return -1;
        } else {
            return m_first->m_data;
        }
    }

    void pop() {
        Node* node = m_first;

        // is the queue empty or only 1 node

        if(m_first == m_last) {
            m_first = m_last = nullptr;
        } else {
            m_first = m_first->m_next;
        }
        delete node;
    }
    friend ostream &operator<<(ostream &output, Queue &queue);
};

ostream &operator<<(ostream &output, Queue &queue) {
    Node *node = queue.m_first;
    while (node != nullptr) {
        output << node->m_data << " ";
        node = node->m_next;
    }
    return output;
}

int main() {

    Queue queue;

    cout << "test 1 : Add data to the queue" << endl;
    cout << "------------------------------" << endl;
    queue.push(1);
    queue.push(2);
    queue.push(3);
    queue.push(4);
    queue.push(5);

    cout << queue << endl;

    cout << "test 2 : access data at the front of the queue" << endl;
    cout << "----------------------------------------------" << endl;

    cout << queue.peek() << endl;

    cout << "test 3 : remove a node from the front of the queue" << endl;
    cout << "----------------------------------------------" << endl;

    queue.pop();

    cout << queue << endl;

    cout << "test 4 : remove all nodes from the queue" << endl;
    cout << "----------------------------------------------" << endl;
    queue.pop();
    queue.pop();
    queue.pop();
    queue.pop();

    cout << queue << endl;

    cout << "test 5 : attempt to remove node from empty queue" << endl;
    cout << "----------------------------------------------" << endl;

    queue.pop();

    cout << "queue: " << queue.peek() << endl;

    return 0;
}
