#include <iostream>

using namespace std;

class Craptor {
private:
    int *m_nums;
    int m_capacity;
    int m_size;

public:
    Craptor() : m_nums(nullptr), m_capacity(0), m_size(0){}
    virtual ~Craptor() {
        delete[] m_nums;
    }
    void add(int num) {

        if (m_size == m_capacity) {
            int *temp = m_nums;
            // allocate a block of memory
            m_nums = new int[m_capacity + 5];
            m_capacity += 5;

            int i;
            for(i = 0; i < m_size; ++i){
                m_nums[i] = temp[i];
            }

            delete[] temp;
        }

        m_nums[++m_size] = num;
    }

    void resize(int size) {
        int *temp = m_nums;
        m_nums = new int[size];

        int i;
        for(i = 0; i < size; i++){
            m_nums[i] = temp[i];
        }
        m_size = size;

        delete[] temp;
    }

    friend ostream& operator<<(ostream& output, Craptor& c);
};

// augmented operator overload to use member variables of Craptor
ostream &operator<<(ostream &output, Craptor& c) {
    cout << " capacity: " << c.m_capacity << ") ";
    for (int i = 0; i < c.m_size; i++) {
         cout << c.m_nums[i] << " ";
    }
    return output;
}

int main() {
//    int len = 0;
//    // starting point: static array
//    int nums[] = {1, 2, 3, 4, 5};
//    len = sizeof(nums) / sizeof(nums[0]);
//
//    cout << nums << endl;
//
//    // add an element to the array
//    int nums2_len = len + 1;
//    int nums2[nums2_len];
//
//    // copy from old array into the new array
//    int i = 0;
//    for (; i < len; ++i) {
//        nums2[i] = nums[i];
//    }
//
//    // add new element to new array
//    nums2[i] = 6;
//
//    // set array len to new array size
//    len = nums2_len;
//
//    cout << nums2 << endl;
//
//    // move to the heap!
//    int nums3_len = len;
//    int *nums3 = new int[nums3_len];
//
//    memcpy(nums3, nums2, nums3_len * sizeof(int));
//    cout << nums3 << endl;
//
//    // new element
//    int nums4_len = len+1;
//    int *nums4 = new int[nums4_len];
//
//    memcpy(nums4, nums3, nums4_len * sizeof(int));
//    len = nums4_len;
//    nums4[len-1] = 7;
//
//    delete[] nums3;
//
//    cout << nums4 << endl;
//
//    // free up mem
//    delete[] nums4;

    // create a new Craptor
    Craptor craptor;

    craptor.add(1);
    craptor.add(2);
    craptor.add(3);
    craptor.add(4);
    craptor.add(5);

    cout << craptor << endl;

    // resize method call
    craptor.resize(6);

    cout << craptor << endl;

    return 0;
}
