#include <iostream>
#include <string>
#include "easystring.hpp"

using namespace std;

int main() {

    // Reverse function examples
    string text = "Hello world, this is reverse example";

    cout << "Main string:" << endl;
    cout << text + "\n" << endl;
    cout << "Reverse:" << endl;
    cout << easystring::reverse(text) + "\n" << endl;
    cout << "Reverse words:" << endl;
    cout << easystring::reverse_w(text) + "\n" << endl;
    cout << "Reverse words position:" << endl;
    cout << easystring::reverse_wp(text) << endl;

    return 0;

}
