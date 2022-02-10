/* 
    For each student roll, name and phone number are to be maintained. For each subject store subject code, name. A student may choose number of subjects from a list of subjects. A subject may be chosen by number of students. Given a roll number system must able to display the subjects chosen by the student and also be able to display the students corresponding to a subject code. Design the classes and implement the system. 
 */
#include <iostream>
#include <cstring>
#define uint unsigned int
class SUBJECT;
class STUDENT;
struct choice
{
    STUDENT *std;
    SUBJECT *sub;
    choice *nxt_sub, *nxt_std;
    choice(STUDENT &st, SUBJECT &sb) : std(&st), sub(&sb), nxt_std('\0'), nxt_sub('\0') {}
};

/* ------------------------------------------------------------------------------------------------------------------------------------------- */

class STUDENT
{
    char name[31], ph_no[11];
    choice *sub_list; // stores location of a choice object whose linked choices via nxt_sub contains subjects of the student

public:
    const uint roll;                                          // roll cannot be changed and hence is public
    STUDENT(uint, const char *, const char * = "--NOTSET--"); // ph no not necessary default --NOTSET--
    void changePh(const char *ph) { strcpy(ph_no, ph); }      // change ph no
    void changeName(const char *nm) { strcpy(name, nm); }     // change name of a student
    void print();                                             // prints student name and roll
    void printDetails();                                      // prints full details of student
    bool does_study(SUBJECT &);                               // tells if students studies the subject
    void list_subjects();                                     // lists subjects that have been chosen
    void choose(SUBJECT &);                                   // for chosing subject
};
STUDENT::STUDENT(uint rll, const char *nm, const char *ph) : roll(rll)
{
    strcpy(name, nm);
    strcpy(ph_no, ph);
    sub_list = '\0';
}
void STUDENT::printDetails()
{
    std::cout << "Roll: " << roll << '\n';
    std::cout << "Name: " << name << '\n';
    std::cout << "Ph: " << ph_no << '\n';
    std::cout << "Chosen subjects: \n";
    list_subjects();
}
void STUDENT::print()
{
    std::cout << "Roll: " << roll << '\t';
    std::cout << "Name: " << name << '\n';
}

/* ------------------------------------------------------------------------------------------------------------------------------------------- */

class SUBJECT
{
    char name[21];
    choice *std_list;

public:
    const uint sub_code; // subject code is public because it cannot be changed
    SUBJECT(uint, const char * = "--NOTSET--");
    void changeName(const char *);          // to change subject name
    void list_students();                   // gives list of students who study this subject
    bool is_studied_by(STUDENT &);          // tells if a student studies this subject
    void print();                           // prints subject code and name
    friend void STUDENT::choose(SUBJECT &); // to help choose subject
};
SUBJECT::SUBJECT(uint code, const char *nm) : sub_code(code) { strcpy(name, nm); }
void SUBJECT::changeName(const char *nm) { strcpy(name, nm); }
void SUBJECT::print()
{
    std::cout << "Sub Code: " << sub_code << '\t';
    std::cout << "Name: " << name << '\n';
}
void SUBJECT::list_students()
{
    choice *ptr = std_list;
    if (std_list == '\0')
        std::cout << "No student has chosen this subject yet\n";
    else
    {
        while (ptr != NULL)
        {
            ptr->std->print();
            ptr = ptr->nxt_std;
        }
    }
}
bool SUBJECT::is_studied_by(STUDENT &t)
{
    choice *ptr = std_list;
    while (ptr != NULL)
    {
        if (ptr->std->roll == t.roll)
            return true;
        ptr = ptr->nxt_std;
    }
    return false;
}

/* ------------------------------------------------------------------------------------------------------------------------------------------- */

void STUDENT::list_subjects()
{
    choice *ptr = sub_list;
    if (sub_list == '\0')
        std::cout << "No subjects chosen yet\n";
    else
    {
        while (ptr != NULL)
        {
            ptr->sub->print();
            ptr = ptr->nxt_sub;
        }
    }
}
bool STUDENT::does_study(SUBJECT &t)
{
    choice *ptr = sub_list;
    while (ptr != NULL)
    {
        if (ptr->sub->sub_code == t.sub_code)
            return true;
        ptr = ptr->nxt_sub;
    }
    return false;
}
void STUDENT::choose(SUBJECT &sb)
{
    choice *ch;
    if (does_study(sb))
    {
        return;
    }
    ch = new choice(*this, sb);
    ch->nxt_sub = sub_list;
    ch->nxt_std = sb.std_list;
    sub_list = ch;
    sb.std_list = ch;
}
