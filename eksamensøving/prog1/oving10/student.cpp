//
// Created by ingebrigt on 05.11.2021.
//

#include "student.h"
#include "oppgaveoversikt.h"

#include <string>


const std::string student::get_name() {
    return this->name;
}

std::map<std::string, student> oppgaveoversikt::get_student_map() {
    return this->students_map;
}

int student::get_num_tasks() {
    return this->num_tasks;
}

void student::increase_num_tasks(size_t increase) {
    this->num_tasks += increase;
}

std::ostream &operator<<(std::ostream &out, student &nums) {
    std::string numString = "name: " + nums.get_name() + ", num tasks: " + std::to_string(nums.get_num_tasks());
    out << numString;
    return out;
}
