#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <stdexcept>
#include <numeric>
#include <cctype>

#include "../include/utils.h"

using std::string;
using std::vector;


/**
 * @brief Stores and handles student grades.
 * 
 */
class Grades {
 private:
    const double INVALID{-1.0};

    vector<double> _homework_all;
    double _hw;
    double _midterm;
    double _final;
    double _end_of_semester;

    /**
     * @brief Convert string input to doubles
     * 
     * @param grade  string representation
     * @return double representation
     */
    double set_value_double(string grade)
        try {
            return std::stod(grade);
        } catch (std::invalid_argument& e) {
            std::cerr << "Midterm grade is not numeric!";
            return INVALID;
        }

    /**
     * @brief Computes average of all homeworks and sets value.
     * 
     * @return homework grade
     */
    double compute_hw_grade() {
        if (_homework_all.size() > 0)
            return std::accumulate(_homework_all.begin(),
                _homework_all.end(), 0.0)/_homework_all.size();
        else
            return 0.0;
    }

 public:
    /**
     * @brief Set the midterm grade
     * 
     * @param midterm string representation
     */
    void set_midterm(string midterm) {
        auto val = set_value_double(midterm);
        if (val != INVALID)
            _midterm = val;
    }

    /**
     * @brief Set the final grade
     * 
     * @param final string representation
     */
    void set_final(string final) {
        auto val = set_value_double(final);
        if (val != INVALID)
            _final = val;
    }

    /**
     * @brief Compute and set the hw grade
     * 
     * @param hw_all all homework grades string representation
     */
    void set_hw(vector<string> hw_all) {
        for (auto hw : hw_all) {
            auto val = set_value_double(hw);
            if (val != INVALID)
                _homework_all.push_back(val);
        }
        _hw = compute_hw_grade();
    }

    /**
     * @brief get homework grade
     * 
     * @return double 
     */
    double hw_grade() const {
        return _hw;
    }

    /**
     * @brief get midterm grade
     * 
     * @return double 
     */
    double midterm_grade() const {
        return _midterm;
    }

    /**
     * @brief get final grade
     * 
     * @return double 
     */
    double final_grade() const {
        return _final;
    }
};


/**
 * @brief Student class
 * 
 */
class Student {
 private:
    string _name;
    Grades _grade;

 public:
    /**
     * @brief parses input string and sets grades
     * 
     * @param input 
     */
    void parse_input(string input) {
        auto split_input = split(input);
        if (split_input.size() >= 3) {
            _name = split_input[0];
            _grade.set_midterm(split_input[1]);
            _grade.set_final(split_input[2]);
            _grade.set_hw(vector<string>(split_input.begin() + 3,
                split_input.end()));
        } else {
            throw std::invalid_argument("Must supply 1 name, 1 midterm grade, "
                                        "1 final grade, respectively. All "
                                        "others will be considered hw grades.");
        }
    }

    /**
     * @brief get student name
     * 
     * @return string 
     */
    string name() const {
        return _name;
    }

    /**
     * @brief get student homework grade
     * 
     * @return double 
     */
    double hw_grade() const {
        return _grade.hw_grade();
    }

    /**
     * @brief get student midterm grade
     * 
     * @return double 
     */
    double midterm_grade() const {
        return _grade.midterm_grade();
    }

    /**
     * @brief get student final grade
     * 
     * @return double 
     */
    double final_grade() const {
        return _grade.final_grade();
    }
};

/**
 * @brief Classroom i.e. all students in class
 * 
 */
class Classroom {
 private:
    const string::size_type NAME_SPACES{15};
    const string::size_type GRADE_SPACES{7};

    vector<Student> _students;

    /**
     * @brief pads string with given number of whitespaces
     * 
     * @param to_pad string to pad
     * @param n      desired number of chars 
     * @param before whether the spaces are added before or after
     * @return string 
     */
    string pad_string(string to_pad, string::size_type n, bool before = false) {
        string spaces(n - to_pad.size(), ' ');
        if (before) {
            return spaces + to_pad;
        } else {
            return to_pad + spaces;
        }
    }

    /**
     * @brief Converts double to string then pads output
     * 
     * @param to_pad 
     * @param n 
     * @param before 
     * @return string 
     */
    string pad_double(double to_pad, string::size_type n, bool before = false) {
        string str = std::to_string(to_pad);
        string shortened = string(str.begin(), str.begin()+5);
        return pad_string(shortened, n, before);
    }

 public:
    /**
     * @brief Reads in student names and grades as user terminal input
     * 
     */
    void read_students() {
        std::cout << "Please enter student grades as \nNAME MIDTERM FINAL HWS\n"
                      "NAME... Submit an empty line to exit (i.e. hit ENTER "
                      "with no words on line)." << std::endl;

        string input;
        while (getline(std::cin, input)) {
            if (isempty(input)) break;
            try {
                Student temp;
                temp.parse_input(input);
                _students.push_back(temp);
            } catch (std::invalid_argument& e) {
                std::cout << "Entry ignored. Must supply 1 name, 1 midterm "
                             "grade, 1 final grade, respectively. All others "
                             "will be considered hw grades." << std::endl;
            }
        }
    }

    /**
     * @brief prints student grades in tabular format
     * 
     */
    void print_students() {
        std::cout << pad_string("Name", NAME_SPACES) << " " <<
            pad_string("Midterm", GRADE_SPACES) << "  ";

        std::cout << pad_string("Final", GRADE_SPACES) << " " <<
            pad_string("HW", GRADE_SPACES) << std::endl;

        for (auto student : _students) {
            std::cout << pad_string(student.name(), NAME_SPACES) << " " <<
                pad_double(student.midterm_grade(), GRADE_SPACES) << " ";

            std::cout << pad_double(student.final_grade(), GRADE_SPACES)
                << " " << pad_double(student.hw_grade(), GRADE_SPACES)
                << std::endl;
        }
    }
};
