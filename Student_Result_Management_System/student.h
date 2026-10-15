#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>

using namespace std;

const int SUBJECT_COUNT = 5;

struct Subject
{
    string code;
    string name;
    int credits;

    float ie1, ie2, internal, external;
    float midAverage, total;

    string grade;
    int gradePoint;
    bool pass;
};

class Student
{
private:
    string rollNo;
    string name;
    int semester;

    int previousCredits;
    float previousCGPA;

    Subject subjects[SUBJECT_COUNT];

    float sgpa, cgpa, percentage;
    int totalCredits;

    bool semesterPass;
    bool marksEntered;
    bool studentAdded;

public:
    Student();

    void addStudent();
    void enterMarks();
    void calculateResult();
    void displayResult();
    void displaySGPACGPA();

    string getRollNo() const;
    string getName() const;
    float getSGPA() const;

    bool isPass() const;
    bool hasMarks() const;
    bool isAdded() const;
};

#endif