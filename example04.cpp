#include <iostream>
#include <string>
#include "easystring.hpp"

using namespace std;

int main() {

    // Case check examples
    string input;

    cout << "Enter your string: ";
    getline(cin, input);

    if(estr::isspace(input)) cout << "Space only";
    else if(easystring::islower(input)) cout << "Lower case";
    else if(easystring::isupper(input)) cout << "Upper case";
    else if(easystring::istitle(input)) cout << "Title case";
    else cout << "Normal or empty";

    cout << endl;
    return 0;

}