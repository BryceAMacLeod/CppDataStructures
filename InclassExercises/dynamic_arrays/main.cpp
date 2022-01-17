#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

ostream &operator<<(ostream &output, const vector<int> &nums);

int main() {
    int static_nums[] ={1,2,3,4,5};

    // new dynamic array
    vector<int> nums{1, 2, 3, 4, 5};
    // reserving memory
    nums.reserve(5);
    // prefixing each line with some text
    // setw(idth) method to line up text by reserving space
    cout << setw(11) << "initial) ";
    // displaying capacity of array
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // add to the vector
    nums.push_back(6);
    cout << setw(11) << "push_back) ";
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    //remove from the vector
    nums.resize(4);
    cout << setw(11) << "resize) ";
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // shrink the capacity
    nums.shrink_to_fit();
    cout << setw(11) << "shrink) ";
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // clear the elements out
    nums.clear();
    cout << setw(11) << "clear) ";
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    // shrink the capacity
    nums.shrink_to_fit();
    cout << setw(11) << "shrink) ";
    cout << "capacity: " << setw(2) << nums.capacity() << ") ";
    cout << nums << endl;

    return 0;
}

ostream &operator<<(ostream &output, const vector<int> &nums) {
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i] << ' ';
    }
    return output;
}
