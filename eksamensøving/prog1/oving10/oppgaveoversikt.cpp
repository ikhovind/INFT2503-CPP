//
// Created by ingebrigt on 07.11.2021.
//

#include <iostream>
#include "oppgaveoversikt.h"


size_t oppgaveoversikt::get_num_students() {
    return this->students_map.size();
}

void oppgaveoversikt::increase_points_for_student(const std::string name, const size_t num_points) {
    if (students_map.contains(name)){
        this->students_map.find(name)->second.increase_num_tasks(num_points);
    }
}

size_t oppgaveoversikt::num_tasks_of_students(const std::string name) {
    return this->students_map.find(name)->second.get_num_tasks();
}

bool oppgaveoversikt::register_new_student(student s) {
    if (students_map.contains(s.get_name())) {
        return false;
    }
    students_map.insert(std::map<std::string, student>::value_type(s.get_name(), s));
    return true;
}
std::ostream &operator<<(std::ostream &out, oppgaveoversikt &nums) {
    std::string vals = "oppgaveoversikt:\n";
    for (auto a : nums.get_student_map()) {
        vals += "navn: " + a.second.get_name() + ", antall oppgaver: " + std::to_string(a.second.get_num_tasks()) + "\n";
    }
    out << vals;
    return out;
}
