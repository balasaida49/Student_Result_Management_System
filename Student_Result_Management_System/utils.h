#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <cctype>

using namespace std;

inline string readRollNumber()
{
    string rollNo;

    while (true)
    {
        cout << "Enter Roll Number (digits only): ";
        cin >> rollNo;

        bool valid = !rollNo.empty();

        for (char c : rollNo)
        {
            if (!isdigit((unsigned char)c))
            {
                valid = false;
                break;
            }
        }

        if (valid)
            return rollNo;

        cout << "Invalid roll number! Enter digits only.\n";
    }
}

inline string readName(string message)
{
    string name;

    while (true)
    {
        cout << message;
        getline(cin >> ws, name);

        bool valid = !name.empty();

        for (char c : name)
        {
            if (!isalpha((unsigned char)c) && c != ' ')
            {
                valid = false;
                break;
            }
        }

        if (valid)
            return name;

        cout << "Invalid input! Use letters and spaces only.\n";
    }
}

inline string readSubjectCode()
{
    string code;

    while (true)
    {
        cout << "Enter Subject Code: ";
        cin >> code;

        bool valid = !code.empty();

        for (char c : code)
        {
            if (!isalnum((unsigned char)c) && c != '-')
            {
                valid = false;
                break;
            }
        }

        if (valid)
            return code;

        cout << "Invalid code! Use letters, digits, or hyphens.\n";
    }
}

inline int readInteger(string message, int minimum, int maximum)
{
    int value;

    while (true)
    {
        cout << message;

        if (!(cin >> value))
        {
            cout << "Invalid input! Enter an integer.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (value < minimum || value > maximum)
        {
            cout << "Enter a value between "
                 << minimum << " and " << maximum << ".\n";
            continue;
        }

        return value;
    }
}

inline float readMarks(string message, float minimum, float maximum)
{
    float value;

    while (true)
    {
        cout << message;

        if (!(cin >> value))
        {
            cout << "Invalid input! Enter a number.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (value < minimum || value > maximum)
        {
            cout << "Enter a value between "
                 << minimum << " and " << maximum << ".\n";
            continue;
        }

        return value;
    }
}

inline string getGrade(float total)
{
    if (total >= 90) return "O";
    if (total >= 80) return "A+";
    if (total >= 70) return "A";
    if (total >= 60) return "B+";
    if (total >= 50) return "B";
    if (total >= 40) return "C";

    return "F";
}

inline int getGradePoint(string grade)
{
    if (grade == "O") return 10;
    if (grade == "A+") return 9;
    if (grade == "A") return 8;
    if (grade == "B+") return 7;
    if (grade == "B") return 6;
    if (grade == "C") return 5;

    return 0;
}

#endif