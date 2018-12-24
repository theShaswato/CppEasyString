#include <iostream>
#include <string>
#include "easystring.hpp"

using namespace std;

int main() {

    // Reading content from a file in string
    string file_name, file_content;

    cout << "Enter a file name to read: ";
    getline(cin, file_name);

    file_content = easystring::ftostr(file_name, "error");
    cout << file_content << endl;

    return 0;

}