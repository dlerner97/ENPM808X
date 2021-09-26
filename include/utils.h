#pragma once

#include <cctype>
#include <iostream>
#include <vector>
#include <string>

/**
 * @brief Non checks whether character is not alpha-numeric
 * 
 * @param c 
 * @return boolean  
 */
bool isnot_alnum(char c) {
    return !std::isalnum(c);
}

/**
 * @brief Utility function operator overload for printing string contents of a vector.
 * 
 * @param os 
 * @param vec 
 * @return std::ostream& 
 */
std::ostream& operator<<(std::ostream& os, std::vector<std::string> vec) {
    for (const auto& val : vec) {
        std::cout << val << " ";
    }
    std::cout << std::endl;
    return os;
}

/**
 * @brief Splits a string into a series of alpha-numeric words
 * 
 * @param input 
 * @return vector<string> 
 */
vector<string> split(const string& input) {
    // Chapter 6 method
    string::const_iterator iter{input.begin()};
    vector<string> ret;

    while (iter != input.end()) {
        iter = std::find_if(iter, input.end(), isalnum);
        string::const_iterator word_end =
            std::find_if(iter, input.end(), isnot_alnum);

        if (iter != input.end())
            ret.push_back(string(iter, word_end));
        iter = word_end;
    }
    return ret;
}

/**
 * @brief Checks if string has any alpanumeric values
 * 
 * @param str 
 * @return true 
 * @return false 
 */
bool isempty(const string& str) {
    for (auto chr : str) {
        if (isalnum(chr)) {
            return false;
        }
    }
    return true;
}
