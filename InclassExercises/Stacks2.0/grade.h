//
// Created by Bryce on 2022-02-04.
//

#ifndef STACKS2_0_GRADE_H
#define STACKS2_0_GRADE_H

#include <iostream>

class Grade {
public:
    int m_mark;
    int m_total;

    Grade(int,int);

    bool operator!=(Grade grade);
};

std::ostream& operator<<(std::ostream& output, Grade grade);


#endif //STACKS2_0_GRADE_H
