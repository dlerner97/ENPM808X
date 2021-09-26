#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <set>
#include <cctype>

#include "../include/utils.h"

using std::string;
using std::vector;

/**
 * @brief read in values from user
 * 
 * @return vector<string> 
 */
vector<string> read() {
    string input;
    vector<string> out;
    while (getline(std::cin, input)) {
        if (isempty(input)) break;
        auto split_line = split(input);
        std::copy(split_line.begin(), split_line.end(),
            std::back_inserter(out));
    }
    return out;
}

/**
 * @brief Converts string to lowercase
 * 
 * @param str input string
 * @return lowercase string 
 */
string to_lower(string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}

/**
 * @brief Get the num words from vector of strings
 * 
 * @param word_vec list of words
 * @return number of words 
 */
int get_num_words(const vector<string>& word_vec) {
    std::set<string> word_set;
    for (const auto& word : word_vec) {
        word_set.insert(to_lower(word));
    }
    return static_cast<int>(word_set.size());
}

/**
 * @brief Get the word counts for each word
 * 
 * @param word_vec list of words
 * @return an std::unordered_map<string, int> of words with their corresponding count
 */
std::unordered_map<string, int> get_num_counts(const vector<string>& word_vec) {
    std::unordered_map<string, int> word_map;
    for (const auto& word : word_vec) {
        word_map[to_lower(word)]++;
    }
    return word_map;
}
