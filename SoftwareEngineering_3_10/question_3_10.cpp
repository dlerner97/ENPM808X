#include <vector>
#include <string>
#include <stdexcept>
#include <numeric>

/**
 * @brief Class to store student grades
 * 
 * @param n Number of students in class
 */
class Grading {
 private:
    std::vector<double> _students;

 public:

    /**
     * @brief Construct a new Grading object
     * 
     * @param n 
     */
    Grading(const int n) : 
        _students{std::vector<double>(n, 0.0)} {}

    /**
     * @brief Set specific student grade
     * 
     * @param n student 
     * @param grade 
     */
    void set_student_grade(const int n, const double grade) {
        try {
            _students[n] = grade;
        } catch (std::out_of_range& e) {
            throw std::out_of_range("Student " +
                std::to_string(n) + " does not exist!");
        }
    }

    /**
     * @brief Computes and returns GPA in given scale
     * 
     * @param upper_scale 
     * @return double 
     */
    double compute_gpa(double upper_scale = 100.0) {
        double mean;
        if (_students.size() > 0)
            mean = std::accumulate(_students.begin(),
                    _students.end(), 0.0)/_students.size();
        else
            mean = 0.0;

        return upper_scale*mean/100.0;
    }
};
