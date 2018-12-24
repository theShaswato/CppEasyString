#include <iostream>
#include <string>
#include "easystring.hpp"

using namespace std;

int main() {

    // Writing string to a file
    string file_name, text;

    cout << "Enter file name: ";
    getline(cin, file_name);
    cout << "Enter your text: ";
    getline(cin, text);

    easystring::strtof(text, file_name, "error");
    return 0;

}