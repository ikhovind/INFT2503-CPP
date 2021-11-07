//
// Created by ingebrigt on 05.11.2021.
//

#include <string>
#ifndef OVING10___PROG_1_STUDENT_H
#define OVING10___PROG_1_STUDENT_H


class student {
private:
    std::string name;
    size_t num_tasks;
public:
    explicit student(const std::string& name_) : name(name_), num_tasks(0) {}
    const std::string get_name();
    int get_num_tasks();
    void increase_num_tasks(size_t increase);
};

std::ostream &operator<<(std::ostream &out, student &nums);


#endif //OVING10___PROG_1_STUDENT_H
