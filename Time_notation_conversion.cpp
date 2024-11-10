/*
Write a program that converts from 24-hour notation to 12-hour notation. For example, it
should convert 14:25 to 2:25 PM. The input is given as two integers. There should be at
least three functions, one for input, one to do the conversion, and one for output. Record
the AM/PM information as a value of type char, ‘A’ for AM and ‘P’ for PM. Thus, the
function for doing the conversions will have a call-by-reference formal parameter of type
char to record whether it is AM or PM. (The function will have other parameters as
well.) Include a loop that lets the user repeat this computation for new input values again
and again until the user says he or she wants to end the program.
*/
#include <iostream>
using namespace std;

void inputTime(int &hours, int &minutes);
void convertTo12Hour(int &hours, char &am_pm);
void outputTime(int hours, int minutes, char am_pm);

int main() {
    int hours, minutes;
    char am_pm;
    char repeat;

    do {
        inputTime(hours, minutes);
        convertTo12Hour(hours, am_pm);
        outputTime(hours, minutes, am_pm);

        cout << "Do you want to convert another time? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

void inputTime(int &hours, int &minutes) {
    cout << "Enter time in 24-hour format (HH MM): ";
    cin >> hours >> minutes;
}

void convertTo12Hour(int &hours, char &am_pm) {
    if (hours >= 12) {
        am_pm = 'P';
        if (hours > 12) {
            hours -= 12;
        }
    } else {
        am_pm = 'A';
        if (hours == 0) {
            hours = 12;
        }
    }
}

void outputTime(int hours, int minutes, char am_pm) {
    cout << "Converted time: " << hours << ":" << (minutes < 10 ? "0" : "") << minutes << " " << am_pm << "M" << endl;
}
