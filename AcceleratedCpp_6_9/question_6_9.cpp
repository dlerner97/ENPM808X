#include <algorithm>
#include <string>
#include <vector>

using std::vector;
using std::string;

/**
 * @brief Concatenate a vector of strings
 * 
 * @param vec input vector 
 * @return elongated string 
 */
string concat_vec(const vector<string>& vec) {
    string ret{};
    for (const auto& val : vec) {
        std::copy(val.begin(), val.end(), std::back_inserter(ret));
    }
    return ret;
}
