#include <iostream>
#include <cstring>

void to_lower(char *text, size_t len) {
    for (int i = 0; i < len; ++i) {
        text[i] = char(tolower(text[i]));
    }
}
int main() {

    const int BUFFER_SIZE = 256;
    const int STREAM_SIZE = 1024;
    char buffer[BUFFER_SIZE];
    char input[BUFFER_SIZE];
    bool done = false;

    while(!done){
        std::cout << "Enter some text: ";
        std::cin.getline(buffer,BUFFER_SIZE);
        if (!std::cin){
            std::cin.clear();
            std::cin.ignore(STREAM_SIZE,'\n');
        }
        memcpy(input,buffer,BUFFER_SIZE);
        to_lower(input,strlen(buffer));
        if(!strncmp(input,"end",BUFFER_SIZE - 1)) {
            done = true;
        }
        else {
            std::cout << "You typed: " << buffer << std::endl;
        }
    }
    return 0;
}
