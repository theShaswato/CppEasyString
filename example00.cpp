#include <iostream>
#include <string>
#include <vector>
#include "easystring.hpp"

using namespace std;

int main() {
    // example00: spliting a string into parts using a delimiter and storing in vector
    string fruits = "Apple,Banana,Mango";
    vector <string> splited = easystring::split(fruits, ",");

    cout << "Main string:\n" + fruits << "\n" << endl;
    cout << "Splited into vector:" << endl;

    for(int i = 0; i < splited.size(); i++) {
        cout << i + 1 << ". " + splited[i] << endl;
    }

    return 0;

}