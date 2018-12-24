#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

/* Written by Shaswato Mondol
 * This header file contains some function to make string (std::string) related works a bit easy.
 * May not be that efficient or accurate, only made for my own practice and making thins a bit easy
 * If efficiency matters, please use your own code...
 * Use cpp standard 17 to compile sources using this header ( -std=c++17 ) */
namespace easystring {

    const string whitespace(" \n\t\r\v\f"); // white space chars

    /* Spliting function for std::string
     * First argument is the input string and second is the delimiter.
     * Returns a vector of strings splited by the provided delimiter.
     * Supports multiple chars, aka string delimiter. */
    vector <string> split(const string &str, const string &delimiter = " ") {
        vector <string> splited; // Vector of all tokens (splited substrings)
        string data{str}, token; // "data" is the copy of the main const argument "str", "token" is used to cut substrings
        size_t position{0}; // Working position on data string
        if(delimiter.length() != 0) { // Checks if the delimiter is not empty
            while((position = data.find(delimiter)) != string::npos) { // Loops till the end of string
                token = data.substr(0, position); // Cuts substring from main string according to delimiter
                splited.push_back(token); // Adds the token to the vector "splited"
                data.erase(0, position + delimiter.length()); // Erases the previous part of string
            }
            splited.push_back(data); // Adds remaining string to the vector "splited"
        } else { // Adds every single chars of the string to vector "splited" if delimiter is empty
            for(auto &c: data) {
                splited.push_back(string(1, c));
            }
        }
        return splited; // Returns the vector of all splited parts
    }

    /* These below functions are for striping a string from either left or right or both side.
     * Takes only one argument as its input string
     * Returns the striped string */
    string lstrip(const string &str) {
        string data{str}; // Copy of argument "str"
        size_t start{data.find_first_not_of(whitespace)}; // Position of first non-whitespace char
        if(start != string::npos) { // Checks if start is a valid position
            data = data.substr(start); // Strips string from left
        } else {
            data = ""; // If string is empty
        }
        return data; // Returns stripped string
    }

    string rstrip(const string &str) {
        string data{str}; //Copy of argument "str"
        size_t end{data.find_last_not_of(whitespace)}; // Position of last non-whitespace char
        if(end != string::npos) { // Checks if end is a valid position
            data = data.substr(0, end + 1); // Strips string from right;
        } else {
            data = ""; // If string is empty
        }
        return data; // Returns stripped string
    }

    string strip(const string &str) {
        string data{str}; // Copy of argument "str"
        data = lstrip(data); // Strips string from left
        data = rstrip(data); // Strips string from right
        return data; // Returns stripped string
    }

    /* This function is for triming a given string
     * Replaces any amount of whitespace with a single whitespace char using string stream.
     * Takes string as argument and returns trimmed string */
    string trim(const string &str) {
        istringstream buffer{str}; // Creates a string stream using argument "str"
        string word, data; // Operational variables
        while(buffer >> word) { // Reads the stream word by word and adds single whitespace to separate them
            data += word + " ";
        }
        data.erase(data.length() - 1); // Removes the last extra whitespace
        return data; // Returns trimmed string
    }

    /* These below functions are for case related works.
     * Takes only a single argument as its input string.
     * Returns the case modified string */
    string lower(const string &str) { // Converts the whole string to lower case
        string data; // Stores the case modified string
        for(auto &c: str) {
            data.push_back((char)tolower(c)); // Comverts to lower case and adds to result string
        }
        return data; // Returns modified string
    }

    string upper(const string &str) { // Converts the whole string to upper case
        string data; // Stores the case modified string
        for(auto &c: str) {
            data.push_back((char)toupper(c)); // Converts to upper case and adds to result string
        }
        return data; // Returns modified string
    }

    string swapcase(const string &str) { // Swaps the case of every chars in the string
        string data; // Stores the case modified string
        for(auto &c: str) {
            if(isupper(c)) { // Converts to lower if char is upper
                data.push_back((char)tolower(c));
            } else { // Converts to upper if char is lower
                data.push_back((char)toupper(c));
            }
        }
        return data; // Returns modified string
    }

    string title(const string &str) { // Converts string to title case
        string data{lower(str)}; // Converts the string to lowercase first
        data[0] = (char)toupper(data[0]); // Converts the first char to upper
        for(int i{0}; i < data.length(); i++) { // Loops the string
            bool check{false}; // True if char is whilespace
            if(whitespace.find(data[i]) != string::npos) { // Checks if the char is whitespace and sets "check" to True
                check = true;
            }
            if(check) { // If True, turns the next char to uppercase
                data[i + 1] = (char)toupper(data[i + 1]);
            }
        }
        return data; // Returns modified string
    }

    /* These below functions can be used to check the case of a string
     * Returns True if case match, otherwise False */
    bool isspace(const string &str) { // Checks if a string only contains whitespace
        bool status{false};
        if(strip(str).length() == 0) { // Sets status to true if string contains only whitespace
            status = true;
        }
        return status;
    }

    bool isupper(const string &str) { // Checks if a string is in upper case
        bool status{true};
        if(!isspace(str)) { // Checks if the string is not whitespace
            for(auto &c: str) { // Checks case of every chars in the input string
                if(std::islower(c)) {
                    status = false;
                    break;
                }
            }
        } else {
            status = false;
        }
        return status;
    }

    bool islower(const string &str) { // Checks if a string is in lower case
        bool status{true};
        if(!isspace(str)) { // Checks if the string is not whitespace
            for(auto &c: str) { // Checks case of every chars in the input string
                if(std::isupper(c)) {
                    status = false;
                    break;
                }
            }
        } else {
            status = false;
        }
        return status;
    }

    bool istitle(const string &str) { // Checks if a string is in title case
        bool status{false};
        if((!isspace(str)) && title(str) == str) { // Checks if the string is not whitespace and title case
            status = true;
        }
        return status;
    }

    /* String padding function
     * Fills left, right or both side with specified substring
     * First argument is input string, second is length and last is optional substring (default is space) */
    string lfill(const string &str, const size_t &length, const string &fill_str = " ") { // Fills from left
        string data{str}, filler;
        for(int i{0}; i < length; i++) {
            filler += fill_str;
        }
        data = filler + data;
        return data;
    }

    string rfill(const string &str, const size_t &length, const string &fill_str = " ") { // Fills from right
        string data{str}, filler;
        for(int i{0}; i < length; i++) {
            filler += fill_str;
        }
        data = data + filler;
        return data;
    }

    string center(const string &str, const size_t &length, const string &fill_str = " ") { // Fills from both side
        string data{str}, filler;
        for(int i{0}; i < length; i++) {
            filler += fill_str;
        }
        data = filler + data + filler;
        return data;
    }

    /* Reverse string with verious methods
     * Takes one argument as input string */
    string reverse(const string &str) { // Reverse the whole string
        string data; // Stores the reversed string
        size_t position{str.length()}; // Index
        while(position--) { // Fills chars from end
            data.push_back(str[position]);
        }
        return data;
    }

    string reverse_w(const string &str) { // Reverse words only
        string data, word; // Holds the reversed string and words
        istringstream buffer{str}; // String stream
        size_t position{0}; // Position
        while(position < str.length()) {
            if(whitespace.find(str[position]) != string::npos) { // Adds char to string if char is a whitespace
                data.push_back(str[position]);
                position++;
            } else { // Extracts a single word and reverses it
                buffer >> word; // Reads a single word from the stream
                string reversed;
                size_t length{word.length()}; // Word length
                position += length;
                while(length--) { // Reverse word
                    reversed.push_back(word[length]);
                }
                data += reversed;
            }
        }
        return data;
    }

    string reverse_wp(const string &str) { // Rvserse word position
        string data{reverse(str)}; // Reverse the entire string
        data = reverse_w(data); // Reverse words only to get back original words
        return data;
    }

    /* Some extra functions for string replace or count and file reading writing */
    unsigned int count(const string &str, const string &substr) { // Counts the number of occurrence of a substring in a given string
        unsigned int count{0};
        if(str.length() != 0) {
            for(size_t offset{str.find(substr)};
                offset != string::npos;
                offset = str.find(substr, offset + substr.length())) {
                count++;
            }
        }
        return count;
    }

    string replace(const string &str, const string &search, const string &substr) { // Replaces all matched search string with a substring from input string
        string data{str};
        size_t index{0};
        while(true) {
            index = data.find(search, index);
            if(index == string::npos) {
                break;
            }
            if(substr.length() == 0) {
                data.erase(index, search.length());
            } else {
                data.replace(index, search.length(), substr);
            }
            index += substr.length();
        }
        return data;
    }

    /* Note: this function will not give any exception upon failure. A second argument can be used as a failure message.
     * Don't use this for complex works */
    string ftostr(const string &file_name, const string & failure_message) { // Reads a file in a string
        ifstream file(file_name, ios::binary); // Opens the file stream
        stringstream buffer; // String stream
        string data;
        if(file.is_open()) {
            buffer << file.rdbuf(); // Reads the file contents in buffer
            data = buffer.str(); // Reads content in string from buffer
            file.close(); // Close file
        } else {
            if(failure_message.length() != 0) {
                cout << failure_message;
            }
        }
        return data;
    }

    /* Note: this function will not give any exception upon failure. A second argument can be used as a failure message.
     * Don't use this for complex works, this function will overwrite the file if filename already exists */
    void strtof(const string &str, const string file_name, const string &failure_message) { // Writes a string to a file
        ofstream file(file_name, ios::binary); // Opens the out file stream
        if(file.is_open()) {
            file << str; // Writes the string to file
            file.close(); // Close file
        } else {
            if(failure_message.length() != 0) {
                cout << failure_message;
            }
        }
    }

}

namespace estr = easystring;