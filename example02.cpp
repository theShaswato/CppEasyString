#include <iostream>
#include <string>
#include "easystring.hpp"

using namespace std;

int main() {

    // Some case examples
    string text = "Hello world, This is case Example";

    cout << "Main string:" << endl;
    cout << text + "\n" << endl;
    cout << "Lower case:" << endl;
    cout << easystring::lower(text) + "\n" << endl;
    cout << "Upper:" << endl;
    cout << easystring::upper(text) + "\n" << endl;
    cout << "Title:" << endl;
    cout << easystring::title(text) + "\n" << endl;
    cout << "Swapcase:" << endl;
    cout << easystring::swapcase(text) << endl;

    return 0;

}