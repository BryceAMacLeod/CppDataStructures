#include <iostream>
#include "stack.h"
#include "grade.h"

using namespace std;


int main() {

    Stack stack;


    cout << "test 1: add node to stack" << endl;
    cout << "-------------------------" << endl;

    stack.push({10,25});
    cout << stack << endl;

    cout << "test 2: add more nodes" << endl;
    cout << "----------------------" << endl;

    stack.push({15,20});
    stack.push({20,25});
    stack.push({25,35});
    stack.push({35,45});

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

    while(stack.peek() != Grade(-1, -1)){
        stack.pop();
    }

    cout << stack << endl;

    cout << "test 6: remove a node off an empty stack" << endl;
    cout << "-------------------------------------------" << endl;

    stack.pop();

    cout << stack << endl;

    return 0;
}