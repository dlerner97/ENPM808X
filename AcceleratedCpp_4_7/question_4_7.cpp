#include <numeric>
#include <vector>

using std::vector;

/**
 * @brief Compute average of a vector
 * 
 * @param vec 
 * @return double 
 */
double average(const vector<double>& vec) {
    if (vec.size() > 0)
        return std::accumulate(vec.begin(), vec.end(), 0.0)/vec.size();
    else
        return 0.0;
}
