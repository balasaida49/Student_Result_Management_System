#include <iostream>
#include <vector>

#include "student.h"
#include "utils.h"
#include "reports.h"

using namespace std;

int main()
{
    vector<Student> students;

    int choice;
    string rollNo;
    int index;

    do
    {
        cout << "\n=================================================\n";
        cout << " UNIVERSITY SEMESTER RESULT MANAGEMENT SYSTEM\n";
        cout << "=================================================\n";

        cout << "1. Add Student Semester Result\n";
        cout << "2. Enter Subject Marks\n";
        cout << "3. Display Student Semester Result\n";
        cout << "4. Search Student by Roll Number\n";
        cout << "5. Show Semester Topper\n";
        cout << "6. Show Pass/Fail Student List\n";
        cout << "7. Show Class Summary\n";
        cout << "8. Show SGPA and CGPA\n";
        cout << "9. Show Total Student Records\n";
        cout << "10. Exit\n";

        choice = readInteger("Enter your choice: ", 1, 10);

        switch (choice)
        {
            case 1:
            {
                Student student;
                student.addStudent();

                if (findStudent(students, student.getRollNo()) != -1)
                {
                    cout << "Roll number already exists. "
                         << "Student not added.\n";
                }
                else
                {
                    students.push_back(student);
                }

                break;
            }

            case 2:
            {
                rollNo = readRollNumber();
                index = findStudent(students, rollNo);

                if (index == -1)
                    cout << "Student not found. Add student first.\n";
                else
                    students[index].enterMarks();

                break;
            }

            case 3:
            case 4:
            {
                rollNo = readRollNumber();
                index = findStudent(students, rollNo);

                if (index == -1)
                    cout << "Student not found.\n";
                else
                    students[index].displayResult();

                break;
            }

            case 5:
                showTopper(students);
                break;

            case 6:
                showPassFailList(students);
                break;

            case 7:
                showClassSummary(students);
                break;

            case 8:
            {
                rollNo = readRollNumber();
                index = findStudent(students, rollNo);

                if (index == -1)
                    cout << "Student not found.\n";
                else
                    students[index].displaySGPACGPA();

                break;
            }

            case 9:
                cout << "\nTotal Student Records: "
                     << students.size() << endl;
                break;

            case 10:
                cout << "\nThank you for using the system.\n";
                break;
        }

    } while (choice != 10);

    return 0;
}
