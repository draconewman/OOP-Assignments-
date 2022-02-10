#include "q6-student.h"
struct stdlist
{
    STUDENT *std;
    stdlist *nxt;
    stdlist() : std('\0'), nxt('\0') {} // default constructor
    stdlist(STUDENT &st, stdlist *next = '\0') : std(&st), nxt(next) {}
    ~stdlist() { delete std; } // also deletes std
    static void display(stdlist *head)
    {
        while (head != '\0')
        {
            head->std->print();
            head = head->nxt;
        }
    }
    static stdlist *find(uint rll, stdlist *head)
    {
        stdlist *ptr = head;
        while (ptr != '\0')
        {
            if (ptr->std->roll == rll)
                return ptr;
            ptr = ptr->nxt;
        }
        return ptr;
    }
    static bool is_available(uint rll, stdlist *head)
    {
        if (head =='\0')
            return true;
        return stdlist::find(rll, head) == '\0';
    }
    static stdlist *add(stdlist *head, uint rll)
    {
        STUDENT *newstd;
        char buff1[31], buff2[11];
        if (!is_available(rll, head))
        {
            std::cout << "Roll not available\n";
            return head;
        }
        std::cin.ignore(100, '\n');
        std::cout << "Enter Name [required]: ";
        std::cin.getline(buff1, 31);
        std::cout << "Enter Ph: ";
        std::cin.getline(buff2, 11);
        newstd = strlen(buff2) == 0 ? new STUDENT(rll, buff1) : new STUDENT(rll, buff1, buff2);
        return new stdlist(*newstd, head);
    }
    static void empty(stdlist *&head)
    {
        stdlist *t;
        while (head != '\0')
        {
            t = head;
            head = head->nxt;
            delete t;
        }
    }
};
struct sublist
{
    SUBJECT *sub;
    sublist *nxt;
    sublist() : sub('\0'), nxt('\0') {}
    sublist(SUBJECT &sb, sublist *next = '\0') : sub(&sb), nxt(next) {}
    ~sublist() { delete sub; }
    static void display(sublist *head)
    {
        while (head != '\0')
        {
            head->sub->print();
            head = head->nxt;
        }
    }
    static sublist *find(uint code, sublist *head)
    {
        sublist *ptr = head;
        while (ptr != '\0')
        {
            if (ptr->sub->sub_code == code)
                return ptr;
            ptr = ptr->nxt;
        }
        return ptr;
    }
    static bool is_available(uint code, sublist *head)
    {
        if (head == '\0')
            return true;
        return sublist::find(code, head) == '\0';
    }
    static sublist *add(sublist *head, uint code)
    {
        SUBJECT *newsub;
        char buff[21];
        if (!is_available(code, head))
        {
            std::cout << "Subject code not available\n";
            return head;
        }
        std::cin.ignore(100, '\n');
        std::cout << "Enter Name : ";
        std::cin.getline(buff, 21);
        newsub = strlen(buff) == 0 ? new SUBJECT(code) : new SUBJECT(code, buff);
        return new sublist(*newsub, head);
    }
    static void empty(sublist *&head)
    {
        sublist *t;
        while (head != '\0')
        {
            t = head;
            head = head->nxt;
            delete t;
        }
    }
};
