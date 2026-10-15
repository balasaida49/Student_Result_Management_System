Student Result Management System
================================

Contents
--------
main.cpp      Console menu and program entry point
student.cpp   Student records, marks, grades, SGPA and CGPA
student.h     Student and subject declarations
reports.cpp  Search, topper, pass/fail and class summary reports
reports.h    Report function declarations
utils.cpp    Includes the utility header for IDE project compatibility
utils.h      Input validation and grade helper functions

Open and build with Dev-C++
---------------------------
1. Extract this ZIP to a folder you can write to.
2. In Dev-C++, choose File > New > Project > Console Application and select C++.
3. Save the project in the extracted folder.
4. Add main.cpp, student.cpp, reports.cpp and utils.cpp to the project. Do not add header files as source files.
5. In Project Options, enable C++11 support (often the -std=c++11 compiler option).
6. Build and run the project.

The source files use matching lowercase header names. Keep all .cpp and .h files in the same folder.

Command-line build (MinGW GCC)
------------------------------
From this folder, run:
  g++ -std=c++11 -Wall -Wextra -pedantic main.cpp student.cpp reports.cpp utils.cpp -o StudentResultManagement.exe

Then run StudentResultManagement.exe.

Notes
-----
Student records are held in memory and are cleared when the program exits. Each student record accepts five subjects. The program uses a 40-point total pass threshold and also requires at least 24 external marks to pass a subject.
