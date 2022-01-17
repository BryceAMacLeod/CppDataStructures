#include <iostream>
#include <sstream>
#include <string>
#include <cstring>

int main() {

    char input[256];
    char command[256];
    int start, end;

    std::cout << "Enter a command: ";
    std::cin.getline(input, 256);

    std::stringstream ss;
    ss << input;


    ss >> command;

    // check for possible command
    // commands are 1 letter, text is multiple characters.
    if(std::strlen(command) > 1) {
        // More than one character means that it is text
        std::cout << "You entered some text. " << std::endl;
    } else {
        // One character means that it could be a command
        // Check to see if it is one of the possible commands
        if(command[0] == 'I') {
            // I command
            std::cout << "I command" << std::endl;

            ss >> start;
            if (!ss) {
                std::cout << "error!" << std::endl;
            } else {
                ss >> end;
            }

            std::cout << "You entered: " <<  command << " command." << std::endl;
            std::cout << "The range is from lines" << start << " to " << end << std::endl;
        }
    }

    return 0;
}
