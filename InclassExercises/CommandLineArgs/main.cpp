#include <iostream>
using namespace std;
int main(int argc, char** argv) {

    for(int i=0;i < argc; ++i) {
        cout << (i+1) << ") " << argv[i] << endl;
    }
    if(argc > 1) {
        cout << "Filename: " << argv[1] << endl;
    }
    else {
        cout << "Example: Filename Args";
    }
    return 0;
}
