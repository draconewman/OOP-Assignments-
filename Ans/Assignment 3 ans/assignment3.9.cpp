#include<iostream>
#include<string>
using namespace std;

class Time {
    public:
        Time(int h = 0, int m = 0, int s = 0, const std::string &am_or_pm = "");
        void print_time24();
        void print_time12();
        void add_min();
    private:
        int hr;
        int min;
        int sec;
};

Time::Time(int h, int m, int s, const std::string &am_or_pm):
    hr(h), min(m), sec(s)
{
    if (am_or_pm == "AM" && hr == 12)
        hr = 0;
    if (am_or_pm == "PM" && hr != 12)
        hr += 12;
}

void Time::print_time24()
{
    std::cout << hr << ':' << min << ':' << sec;
}

void Time::print_time12()
{
    if (hr == 0 || hr == 12)
        std::cout << "12";
    else
        std::cout << hr % 12;
    std::cout << ':' << min << ':' << sec;

    if (hr / 12 == 0)
        std::cout << " AM";
    else
        std::cout << " PM";
}

void Time::add_min()
{
    if (min == 59)
        hr = (hr + 1) % 24;

    min = (min + 1) % 60;
}

int main()
{
    using namespace std;
    cout << "Choose option(1. 12 hr format 2. 24 hr format): ";
    int op;
    cin >> op;
    cout << "Enter the time: ";
    int hr, min, sec;
    cin >> hr >> min >> sec;
    string am_or_pm;
    if (op == 1)
        cin >> am_or_pm;
    Time t(hr, min, sec, am_or_pm);
    t.print_time12();
    cout << '\n';
    t.print_time24();
    cout << '\n';

    cout << "Adding a minute,\n";
    t.add_min();
    t.print_time12();
    cout << '\n';
    t.print_time24();
    cout << '\n';

    return 0;
}
