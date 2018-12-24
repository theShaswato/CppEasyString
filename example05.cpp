#include <iostream>
#include <string>
#include "easystring.hpp"

using namespace std;

int main() {

    // Char fill examples
    string text = "Hello world";

    cout << "Main string:" << endl;
    cout << text + "\n" << endl;
    cout << "Right fill:" << endl;
    cout << easystring::rfill(text, 5, "@") + "\n" << endl;
    cout << "Left fill:" << endl;
    cout << easystring::lfill(text, 5, "@") + "\n" << endl;
    cout << "Both fill:" << endl;
    cout << easystring::center(text, 5, "@") << endl;

    return 0;

}