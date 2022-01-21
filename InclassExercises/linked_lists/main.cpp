#include <iostream>

using namespace std;

class LinkedListNode {
public:
    int m_data{-1};                 // the data to be stored
    LinkedListNode *m_next{nullptr};     // a pointer to the next node in the chain
};

class LinkedList {
private:
    LinkedListNode *m_start{nullptr};

public:
    LinkedList() : m_start(nullptr) {}

    virtual ~LinkedList() {
        LinkedListNode *node = m_start;

        while (node != nullptr) {
            LinkedListNode *temp = node;
            node = node->m_next;

            delete temp;
        }

    }

    void add(int data) {

        LinkedListNode *new_node = new LinkedListNode();
        new_node->m_data = data;

        // are there nodes in the list?
        if (m_start == nullptr) {
            // add the first node
            m_start = new_node;
        } else {
            //add additional nodes
            LinkedListNode *node = m_start;
            LinkedListNode *prev = nullptr;

            // go through each node until you hit null
            while (node != nullptr) {
                prev = node;
                node = node->m_next;
            }
            // attach node to end of chain
            if (prev != nullptr) {
                prev->m_next = new_node;
            }
        }
    }

    void insert(int data, int index) {

        LinkedListNode *new_node = new LinkedListNode();
        new_node->m_data = data;

        // find the node to insert between
        LinkedListNode *node = m_start;
        LinkedListNode *prev = nullptr;

        // count to keep track of the position in the list
        int curr_pos = 1;

        while (node != nullptr) {

            if (curr_pos++ == index) {
                break;
            }

            prev = node;
            node = node->m_next;
        }

        if(node != nullptr) {
            if (prev == nullptr ) {
                //inserting before the first node
                new_node->m_next = m_start;
                m_start = new_node;
            } else {
                // inserting elsewhere
                new_node->m_next = prev->m_next;
                prev->m_next = new_node;
            }
        } else {
            cout << "Position out of index" << endl;
        }
    }

    void remove(int data) {

        LinkedListNode *node = m_start;
        LinkedListNode *prev = nullptr;

        // find the node to delete
        while (node != nullptr) {

            if (node->m_data == data) {
                break;
            }
            prev = node;
            node = node->m_next;

        }

        // did I find the node?
        if (node != nullptr) {
            // first node or another node?
            if (prev != nullptr) {
                // any other node
                prev->m_next = node->m_next;
            } else {
                // first node
                m_start = node->m_next;
            }

            delete node;
        }
    }

    friend ostream &operator<<(ostream &output, LinkedList &list) {

        LinkedListNode *node = list.m_start;


        while (node != nullptr) {
            output << node->m_data << ' ';
            node = node->m_next;
        }

        return output;
    }
};

int main() {

    LinkedList list;

    // test 1 - add nodes to the list
    list.add(1);
    cout << "Test 1" << " ------ " << endl;
    cout << list << endl;

    // test 2 - add another node to the list
    list.add(2);
    list.add(3);
    list.add(4);
    list.add(5);

    cout << "Test 2" << " ------ " << endl;
    cout << list << endl;

    // test 3 - delete a node in the middle of the chain
    list.remove(3);

    cout << "Test 3" << " ------ " << endl;
    cout << list << endl;

    // test 4 - delete the last node in the chain
    list.remove(5);

    cout << "Test 4" << " ------ " << endl;
    cout << list << endl;

    // test 5 - delete the first node in the chain
    list.remove(1);

    cout << "Test 5" << " ------ " << endl;
    cout << list << endl;

    // test 6 - insert a node in the chain
    list.add(5);
    list.add(6);
    list.add(7);
    list.add(8);
    list.insert(9, 1);
    cout << "Test 6" << " ------ " << endl;
    cout << list << endl;
    return 0;
}
