#include <iostream>
#include <cstring>

int main() {

    const int BUFFER_SIZE = 256;
    const int STREAM_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    bool done = false;

    while(!done){
        std::cout << "Enter some text: ";
        std::cin.getline(buffer,BUFFER_SIZE);
        if (!std::cin){
            std::cin.clear();
            std::cin.ignore(STREAM_SIZE,'\n');
        }
        if(!strncmp(buffer,"end",BUFFER_SIZE - 1)) {
            done = true;
        }
        else {
            std::cout << "You typed: " << buffer << std::endl;
        }
    }
    return 0;
}
