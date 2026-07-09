#include <string>
#include <fstream>
#include <iostream>
#include <vector>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        std::cerr << "Error: No input file provided." << std::endl;
        return 1;
    }
    std::string inputFile = argv[1];
    std::fstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << inputFile << std::endl;
        return 1;
    }

    char ch;

    std::vector<unsigned char> cells(30000, 0);
    int ptr = 0;
    std::vector<char> whole_thing;

    while (file.get(ch)) {
        whole_thing.push_back(ch);
    }

    int file_ptr = 0;
    while (file_ptr < whole_thing.size()) {
        ch = whole_thing[file_ptr];

        if (ch == '>') {
            ptr++;
        } else if (ch == '<') {
            ptr--;
        } else if (ch == '+') {
            cells[ptr]++;
        } else if (ch == '-') {
            cells[ptr]--;
        } else if (ch == '.') {
            putchar(cells[ptr]);
        } else if (ch == ',') {
            fflush(stdout);
            unsigned char input;
            input = getchar();
            cells[ptr] = input;
        } else if (ch == '[') {
            if (cells[ptr] == 0) {
                int depth = 0;
                for (;;) {
                    file_ptr++;
                    if (whole_thing[file_ptr] == '[') {
                        depth++;
                    } else if (whole_thing[file_ptr] == ']') {
                        if (depth == 0) {
                            // file_ptr++;
                            break;
                        } else {
                            depth--;
                        }
                    }
                }
            }
        } else if (ch == ']') {
            if (cells[ptr] != 0) {                
                int depth = 0;
                for (;;) {
                    file_ptr--;
                    if (whole_thing[file_ptr] == ']') {
                        depth++;
                    } else if (whole_thing[file_ptr] == '[') {
                        if (depth == 0) {
                            // file_ptr++;
                            break;
                        } else {
                            depth--;
                        }
                    }
                }
            }
        }
        
        file_ptr++;
    }

    fflush(stdout);

    return 0;
}