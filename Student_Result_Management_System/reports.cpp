#include "reports.h"
#include <iostream>
#include <iomanip>

using namespace std;

int findStudent(vector<Student> &students, string rollNo)
{
    for (int i = 0; i < (int)students.size(); i++)
    {
        if (students[i].getRollNo() == rollNo)
            return i;
    }

    return -1;
}

void showTopper(vector<Student> &students)
{
    int topperIndex = -1;

    for (int i = 0; i < (int)students.size(); i++)
    {
        if (students[i].hasMarks())
        {
            if (topperIndex == -1 ||
                students[i].getSGPA() >
                    students[topperIndex].getSGPA())
            {
                topperIndex = i;
            }
        }
    }

    if (topperIndex == -1)
    {
        cout << "\nNo result records available.\n";
    }
    else
    {
        cout << "\n========== SEMESTER TOPPER ==========\n";
        students[topperIndex].displayResult();
    }
}

void showPassFailList(vector<Student> &students)
{
    bool found = false;

    cout << "\n========== PASSED STUDENTS ==========\n";

    for (int i = 0; i < (int)students.size(); i++)
    {
        if (students[i].hasMarks() && students[i].isPass())
        {
            cout << students[i].getRollNo()
                 << " - " << students[i].getName() << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No passed students found.\n";

    found = false;

    cout << "\n========== FAILED STUDENTS ==========\n";

    for (int i = 0; i < (int)students.size(); i++)
    {
        if (students[i].hasMarks() && !students[i].isPass())
        {
            cout << students[i].getRollNo()
                 << " - " << students[i].getName() << endl;
            found = true;
        }
    }

    if (!found)
        cout << "No failed students found.\n";
}

void showClassSummary(vector<Student> &students)
{
    int resultCount = 0;
    int passCount = 0;
    int failCount = 0;
    float sgpaSum = 0;

    for (int i = 0; i < (int)students.size(); i++)
    {
        if (students[i].hasMarks())
        {
            resultCount++;
            sgpaSum += students[i].getSGPA();

            if (students[i].isPass())
                passCount++;
            else
                failCount++;
        }
    }

    if (resultCount == 0)
    {
        cout << "\nNo result records available.\n";
        return;
    }

    cout << "\n========== CLASS SUMMARY ==========\n";

    cout << "Students with Results : " << resultCount << endl;
    cout << "Passed Students       : " << passCount << endl;
    cout << "Failed Students       : " << failCount << endl;

    cout << "Average SGPA          : "
         << fixed << setprecision(2)
         << sgpaSum / resultCount << endl;
}
