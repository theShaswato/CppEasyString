#include <iostream>
#include <string>
#include "easystring.hpp"

using namespace std;

int main() {

    // some string stripping and triming example
    string text = "   hello     world   ";

    cout << "Main string:" << endl;
    cout << text + "!\n" << endl;
    cout << "Rstrip:" << endl;
    cout << easystring::rstrip(text) + "!\n" << endl;
    cout << "Lstrip:" << endl;
    cout << easystring::lstrip(text) + "!\n" << endl;
    cout << "Strip:" << endl;
    cout << easystring::strip(text) + "!\n" << endl;
    cout << "Trim:" << endl;
    cout << easystring::trim(text) + "!\n" << endl;

    return 0;
}