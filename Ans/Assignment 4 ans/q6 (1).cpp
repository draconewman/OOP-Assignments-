#include <iostream>
#include "q6-list.h"
/* 
1. Student menu
    1. List all students
    2. Find a student
    3. Select a student
        1. Print details
        2. Print subject list
        3. Change Name
        4. Change ph no.
        5. Choose a subject
        6. Unselect
    4. Add a Student
    5. Go back
2. Subject Menu
    1. List all subjects
    2. Find a subject
    3. Add a subject
    4. Change a subject's name
    5. Get list of students who have chosen a subject
    6. Go back
3. Exit
 */
stdlist *students;
sublist *subjects;
void student();
void select_student(STUDENT &);
void subject();
void mainmenu()
{
    std::cout << "Main Menu:\n";
    std::cout << "1: Student Menu\n";
    std::cout << "2: Subject Menu\n";
    std::cout << "3: Exit\n";
}
int main()
{
    stdlist *t1;
    sublist *t2;
    char ch;
    mainmenu();
    while (true)
    {
        std::cout << "Enter Choice: ";
        std::cin >> ch;
        switch (ch)
        {
        case '1':
            std::cout << '\n';
            student();
            mainmenu();
            break;
        case '2':
            std::cout << '\n';
            subject();
            mainmenu();
            break;
        case '3':
            stdlist::empty(students);
            sublist::empty(subjects);
            return 0;
        default:
            mainmenu();
        }
    }
}
void studentmenu()
{
    std::cout << "Student Menu:\n";
    std::cout << "1: List all students\n";
    std::cout << "2: Find a student\n";
    std::cout << "3: Select a student\n";
    std::cout << "4: Add a Student\n";
    std::cout << "5: Go back to Main Menu\n";
}
void student()
{
    char ch;
    uint t1;
    stdlist *t2;
    studentmenu();
    while (true)
    {
        std::cout << "Enter Choice: ";
        std::cin >> ch;
        switch (ch)
        {
        case '1':
            if (students == '\0')
                std::cout << "No students in list\n";
            stdlist::display(students);
            break;
        case '2':
            std::cout << "Enter roll to find: ";
            std::cin >> t1;
            t2 = stdlist::find(t1, students);
            if (t2 == '\0')
            {
                std::cout << "Not Found\n";
            }
            else
            {
                t2->std->printDetails();
            }
            break;
        case '3':
            std::cout << "Enter roll to select: ";
            std::cin >> t1;
            t2 = stdlist::find(t1, students);
            if (t2 == '\0')
            {
                std::cout << "Cannot select! No match found\n";
            }
            else
            {
                std::cout << '\n';
                select_student(*(t2->std));
                studentmenu();
            }
            break;
        case '4':
            std::cout << "Enter roll to add: ";
            std::cin >> t1;
            students = stdlist::add(students, t1);
            break;
        case '5':
            std::cout << '\n';
            return;
            break;
        default:
            studentmenu();
        }
    }
}
void select_studentmenu()
{
    std::cout << "Selected Student Menu:\n";
    std::cout << "1: Print details\n";
    std::cout << "2: Print subject list\n";
    std::cout << "3: Change Name\n";
    std::cout << "4: Change ph no.\n";
    std::cout << "5: Choose a subject\n";
    std::cout << "6: Unselect\n";
}
void select_student(STUDENT &t)
{
    char ch, buff[31];
    uint t1;
    sublist *t2;
    std::cout << "Selected Student\n";
    t.print();
    std::cout << '\n';
    select_studentmenu();
    while (true)
    {
        std::cout << "Enter Choice: ";
        std::cin >> ch;
        switch (ch)
        {
        case '1':
            t.printDetails();
            break;
        case '2':
            std::cout << "List of subjects chosen by roll " << t.roll << " :\n";
            t.list_subjects();
            break;
        case '3':
            std::cin.ignore(100, '\n');
            std::cout << "Enter new name: ";
            std::cin.getline(buff, 31);
            t.changeName(buff);
            break;
        case '4':
            std::cin.ignore(100, '\n');
            std::cout << "Enter new Ph number: ";
            std::cin.getline(buff, 11);
            t.changePh(buff);
            break;
        case '5':
            std::cout << "List of all subjects available:\n";
            sublist::display(subjects);
            std::cout << "Enter subject code to choose: ";
            std::cin >> t1;
            t2 = sublist::find(t1, subjects);
            if (t2 == '\0')
                std::cout << "Entered code is not valid\n";
            else
                t.choose(*(t2->sub));
            break;
        case '6':
            std::cout << '\n';
            return;
        default:
            select_studentmenu();
            break;
        }
    }
}
void subjectmenu()
{
    std::cout << "Subject Menu:\n";
    std::cout << "1: List all subjects\n";
    std::cout << "2: Find a subject\n";
    std::cout << "3: Add a subject\n";
    std::cout << "4: Change a subject's name\n";
    std::cout << "5: Get list of students who study a subject\n";
    std::cout << "6: Go to Main Menu\n";
}
void subject()
{
    char ch, buff[21];
    uint t1;
    sublist *t2;
    subjectmenu();
    while (true)
    {
        std::cout << "Enter Choice: ";
        std::cin >> ch;
        switch (ch)
        {
        case '1':
            if (subjects == '\0')
                std::cout << "No subjects in list\n";
            sublist::display(subjects);
            break;
        case '2':
            std::cout << "Enter subject code to find: ";
            std::cin >> t1;
            t2 = sublist::find(t1, subjects);
            if (t2 == '\0')
                std::cout << "Not Found\n";
            else
            {
                std::cout << "Subject found:\n";
                t2->sub->print();
            }
            break;
        case '3':
            std::cout << "Enter subject code to add: ";
            std::cin >> t1;
            subjects = sublist::add(subjects, t1);
            break;
        case '4':
            std::cout << "Enter subject code to change name: ";
            std::cin >> t1;
            t2 = sublist::find(t1, subjects);
            if (t2 == '\0')
                std::cout << "No Match Found\n";
            else
            {
                std::cin.ignore(100, '\n');
                std::cout << "Enter new name: ";
                std::cin.getline(buff, 21);
                t2->sub->changeName(buff);
            }
            break;
        case '5':
            std::cout << "Enter subject code to find list of students: ";
            std::cin >> t1;
            t2 = sublist::find(t1, subjects);
            if (t2 == '\0')
                std::cout << "No Match Found\n";
            else
                t2->sub->list_students();
            break;
        case '6':
            std::cout << '\n';
            return;
        default:
            subjectmenu();
            break;
        }
    }
}
