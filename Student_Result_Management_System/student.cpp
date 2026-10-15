#include "student.h"
#include "utils.h"

Student::Student()
{
    semester = 1;
    previousCredits = 0;
    previousCGPA = 0;

    sgpa = 0;
    cgpa = 0;
    percentage = 0;
    totalCredits = 0;

    semesterPass = false;
    marksEntered = false;
    studentAdded = false;
}

string Student::getRollNo() const { return rollNo; }
string Student::getName() const { return name; }
float Student::getSGPA() const { return sgpa; }
bool Student::isPass() const { return semesterPass; }
bool Student::hasMarks() const { return marksEntered; }
bool Student::isAdded() const { return studentAdded; }

void Student::addStudent()
{
    cout << "\n========== ADD STUDENT ==========\n";

    rollNo = readRollNumber();
    name = readName("Enter Student Name: ");

    semester = readInteger("Enter Semester (1 to 8): ", 1, 8);

    if (semester == 1)
    {
        previousCredits = 0;
        previousCGPA = 0;
    }
    else
    {
        previousCredits = readInteger(
            "Enter Previous Total Credits: ", 1, 300);

        previousCGPA = readMarks(
            "Enter Previous CGPA (0 to 10): ", 0, 10);
    }

    studentAdded = true;
    marksEntered = false;

    cout << "\nStudent added successfully!\n";
}

void Student::enterMarks()
{
    if (!studentAdded)
    {
        cout << "\nPlease add student details first.\n";
        return;
    }

    cout << "\n========== ENTER SUBJECT MARKS ==========\n";

    for (int i = 0; i < SUBJECT_COUNT; i++)
    {
        cout << "\n---------- Subject " << i + 1 << " ----------\n";

        subjects[i].code = readSubjectCode();
        subjects[i].name = readName("Enter Subject Name: ");

        subjects[i].credits =
            readInteger("Enter Credits (1 to 5): ", 1, 5);

        subjects[i].ie1 =
            readMarks("Enter IE1 Marks (out of 16): ", 0, 16);

        subjects[i].ie2 =
            readMarks("Enter IE2 Marks (out of 24): ", 0, 24);

        subjects[i].internal =
            readMarks("Enter Internal Marks (out of 10): ", 0, 10);

        subjects[i].external =
            readMarks("Enter Semester-End Marks (out of 70): ", 0, 70);
    }

    marksEntered = true;
    calculateResult();

    cout << "\nMarks entered successfully!\n";
}

void Student::calculateResult()
{
    float totalMarks = 0;
    float totalCreditPoints = 0;

    totalCredits = 0;
    semesterPass = true;

    for (int i = 0; i < SUBJECT_COUNT; i++)
    {
        subjects[i].midAverage =
            (subjects[i].ie1 + subjects[i].ie2) / 2.0f;

        subjects[i].total =
            subjects[i].midAverage +
            subjects[i].internal +
            subjects[i].external;

        if (subjects[i].total >= 40 &&
            subjects[i].external >= 24)
        {
            subjects[i].pass = true;
            subjects[i].grade = getGrade(subjects[i].total);
            subjects[i].gradePoint =
                getGradePoint(subjects[i].grade);
        }
        else
        {
            subjects[i].pass = false;
            subjects[i].grade = "F";
            subjects[i].gradePoint = 0;
            semesterPass = false;
        }

        totalMarks += subjects[i].total;
        totalCredits += subjects[i].credits;

        totalCreditPoints +=
            subjects[i].gradePoint * subjects[i].credits;
    }

    percentage = totalMarks / SUBJECT_COUNT;

    if (totalCredits > 0)
        sgpa = totalCreditPoints / totalCredits;
    else
        sgpa = 0;

    if (previousCredits == 0)
    {
        cgpa = sgpa;
    }
    else
    {
        cgpa =
            ((previousCGPA * previousCredits) +
             (sgpa * totalCredits)) /
            (previousCredits + totalCredits);
    }
}

void Student::displayResult()
{
    if (!studentAdded)
    {
        cout << "\nPlease add student details first.\n";
        return;
    }

    if (!marksEntered)
    {
        cout << "\nMarks have not been entered for this student.\n";
        return;
    }

    cout << "\n===============================================================\n";
    cout << "               UNIVERSITY SEMESTER RESULT\n";
    cout << "===============================================================\n";

    cout << "Roll Number : " << rollNo << endl;
    cout << "Name        : " << name << endl;
    cout << "Semester    : " << semester << endl;

    cout << "\n--------------------------------------------------------------------------\n";

    cout << left
         << setw(10) << "Code"
         << setw(17) << "Subject"
         << setw(6) << "IE1"
         << setw(6) << "IE2"
         << setw(9) << "Internal"
         << setw(9) << "External"
         << setw(8) << "Total"
         << setw(7) << "Grade"
         << setw(7) << "Point"
         << "Result\n";

    cout << "--------------------------------------------------------------------------\n";

    for (int i = 0; i < SUBJECT_COUNT; i++)
    {
        cout << left
             << setw(10) << subjects[i].code
             << setw(17) << subjects[i].name
             << setw(6) << subjects[i].ie1
             << setw(6) << subjects[i].ie2
             << setw(9) << subjects[i].internal
             << setw(9) << subjects[i].external
             << setw(8) << fixed << setprecision(2)
             << subjects[i].total
             << setw(7) << subjects[i].grade
             << setw(7) << subjects[i].gradePoint
             << (subjects[i].pass ? "PASS\n" : "FAIL\n");
    }

    cout << "--------------------------------------------------------------------------\n";

    cout << "Average Percentage : "
         << fixed << setprecision(2) << percentage << "%\n";

    cout << "SGPA               : "
         << fixed << setprecision(2) << sgpa << endl;

    cout << "CGPA               : "
         << fixed << setprecision(2) << cgpa << endl;

    cout << "Semester Result    : "
         << (semesterPass ? "PASS\n" : "FAIL / SUPPLEMENTARY\n");

    cout << "===============================================================\n";
}

void Student::displaySGPACGPA()
{
    if (!studentAdded || !marksEntered)
    {
        cout << "\nStudent details or marks are not available.\n";
        return;
    }

    cout << "\n========== SGPA AND CGPA ==========\n";
    cout << "Roll Number : " << rollNo << endl;
    cout << "Name        : " << name << endl;

    cout << "SGPA        : "
         << fixed << setprecision(2) << sgpa << endl;

    cout << "CGPA        : "
         << fixed << setprecision(2) << cgpa << endl;
}
