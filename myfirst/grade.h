#ifndef GUARD_grade_h
#define GUARD_grade_h

#include <vector>
#include "Student_info.h"

using namespace std;

double grade(double, double, double);

double grade(double, double, const vector<double>&);

double grade(const Student_info&);

#endif