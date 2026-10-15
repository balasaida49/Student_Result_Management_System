#ifndef REPORTS_H
#define REPORTS_H

#include "Student.h"
#include <vector>
#include <string>

using namespace std;

int findStudent(vector<Student>& students, string rollNo);

void showTopper(vector<Student>& students);
void showPassFailList(vector<Student>& students);
void showClassSummary(vector<Student>& students);

#endif