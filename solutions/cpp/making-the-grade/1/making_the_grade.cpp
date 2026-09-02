#include <array>
#include <string>
#include <vector>

// Round down all provided student scores.
std::vector<int> round_down_scores(std::vector<double> student_scores) {
    // TODO: Implement round_down_scores
    int i = 0;
    std::vector<int> updated_scores;
    while(i < student_scores.size()) {
        updated_scores.emplace_back(static_cast<int>(student_scores.at(i)));
        i++;
    }
    return updated_scores;
}

// Count the number of failing students out of the group provided.
int count_failed_students(std::vector<int> student_scores) {
    // TODO: Implement count_failed_students
    int i = 0;
    int number_of_failed_students;
    while (i < student_scores.size()) {
        if (student_scores.at(i) < 41)
            number_of_failed_students++;
        i++;
    }
    return number_of_failed_students;
}

// Create a list of grade thresholds based on the provided highest grade.
std::array<int, 4> letter_grades(int highest_score) {
    // TODO: Implement letter_grades
    int threshold = (highest_score - 40) / 4;
    std::array<int, 4> grades = {41, 41 + threshold, 41 + threshold * 2, 41 + threshold * 3};
    return grades;
}

// Organize the student's rank, name, and grade information in ascending order.
std::vector<std::string> student_ranking(
    std::vector<int> student_scores, std::vector<std::string> student_names) {
    // TODO: Implement student_ranking
    std::vector<std::string> student_infos;
    int i = 0;
    while(i < student_names.size()) {
        student_infos.emplace_back(std::to_string(i+1) + ". " + student_names.at(i) + ": " + std::to_string(student_scores.at(i)));
        i++;
    }
     
    return student_infos;
}

// Create a string that contains the name of the first student to make a perfect
// score on the exam.
std::string perfect_score(std::vector<int> student_scores,
                          std::vector<std::string> student_names) {
    // TODO: Implement perfect_score
    int i = 0;
    while(i < student_names.size()) {
        if (student_scores[i] == 100) return student_names[i];
        i++;
    }
    return "";
}