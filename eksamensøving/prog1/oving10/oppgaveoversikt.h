//
// Created by ingebrigt on 07.11.2021.
//
#include <map>
#include <string>
#include "student.h"

#ifndef OVING10_OPPGAVEOVERSIKT_H
#define OVING10_OPPGAVEOVERSIKT_H


class oppgaveoversikt {
private:
    std::map<std::string, student> students_map;
public:
    oppgaveoversikt() {}
    std::map<std::string, student> get_student_map();
    size_t get_num_students();
    size_t num_tasks_of_students(std::string name);
    bool register_new_student(student s);
    void increase_points_for_student(std::string name, size_t num_points);
};
std::ostream &operator<<(std::ostream &out, oppgaveoversikt &nums);

#endif //OVING10_OPPGAVEOVERSIKT_H
