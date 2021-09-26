#include <iostream>
#include <vector>
#include <string>

using std::string;
using std::vector;

#include "../SoftwareEngineering_3_10/question_3_10.cpp"
#include "../AcceleratedCpp_3_5/question_3_5.cpp"
#include "../AcceleratedCpp_4_5/question_4_5.cpp"
#include "../AcceleratedCpp_4_7/question_4_7.cpp"
#include "../AcceleratedCpp_6_9/question_6_9.cpp"

int main()
{
    const std::string sep = "\n" + std::string(30, '=') + "\n";

    std::cout << "\nSoftware Engineering Book" << sep;
    std::cout << sep << "Question 3-10" << sep << std::endl;

    Grading grading(2);
    grading.set_student_grade(1, 100.0);
    std::cout << "GPA in 100 pt scale: " << grading.compute_gpa() << std::endl;
    std::cout << "GPA in 4.0 pt scale: " << grading.compute_gpa(4.0) << std::endl;

    std::cout << "\n\nAccelerated C++ Book" << sep;
    std::cout << sep << "Question 3-5" << sep << std::endl;
    Classroom cls;
    cls.read_students();
    std::cout << std::endl;
    cls.print_students();

    std::cout << sep << "Question 4-5" << sep << std::endl;
    std::cout << "Please enter words into the terminal. Submit an empty line to exit (i.e. hit ENTER with no words on line)." << std::endl;
    auto words = read();
    std::cout << "\n\nThere are " << get_num_words(words) << " words in that input." << std::endl;
    auto word_map = get_num_counts(words);
    for (const auto &pair: word_map) {
        std::cout << "'" << pair.first << "' was used " << pair.second << " times." << std::endl;
    }

    std::cout << sep << "Question 4-7" << sep << std::endl;
    vector<double> my_vec{4.5, 24.2, 6.0, 12.2};
    std::cout << "The average of this vector is: " << average(my_vec) << std::endl;

    std::cout << sep << "Question 6-9" << sep << std::endl;
    vector<string> word_vec{"patch", "me", "up", "please!"};
    std::cout << "Concatenated word vec: " << concat_vec(word_vec) << std::endl << std::endl;

    return 0;
}
