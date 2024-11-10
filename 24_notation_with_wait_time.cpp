#include <iostream>
using namespace std;

void inputTime(int &hours, int &minutes, char &am_pm);
void calculateNewTime(int hours, int minutes, int wait_hours, int wait_minutes, int &new_hours, int &new_minutes);
void determineAmPm(int hours, char &am_pm);
void outputTime24(int hours, int minutes, char am_pm);

int main() {
    int hours, minutes, wait_hours, wait_minutes;
    char am_pm;
    char repeat;

    do {
        inputTime(hours, minutes, am_pm);
        cout << "Enter waiting time (HH MM): ";
        cin >> wait_hours >> wait_minutes;

        int new_hours, new_minutes;
        calculateNewTime(hours, minutes, wait_hours, wait_minutes, new_hours, new_minutes);

        determineAmPm(new_hours, am_pm);
        outputTime24(new_hours, new_minutes, am_pm);

        cout << "Do you want to calculate another waiting period? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

void inputTime(int &hours, int &minutes, char &am_pm) {
    cout << "Enter current time in 24-hour format (HH MM): ";
    cin >> hours >> minutes;

    if (hours == 12) {
        cout << "Is this 12 AM or 12 PM? Enter 'A' for AM or 'P' for PM: ";
        cin >> am_pm;

        // If it's 12 AM, treat it as 00:00 in 24-hour format
        if (am_pm == 'A') {
            hours = 0;
        }
    } else if (hours < 12) {
        am_pm = 'A';
    } else {
        am_pm = 'P';
    }
}

void calculateNewTime(int hours, int minutes, int wait_hours, int wait_minutes, int &new_hours, int &new_minutes) {
    new_minutes = (minutes + wait_minutes) % 60;
    new_hours = (hours + wait_hours + (minutes + wait_minutes) / 60) % 24;
}

void determineAmPm(int hours, char &am_pm) {
    if (hours < 12) {
        am_pm = 'A';
    } else {
        am_pm = 'P';
    }
}

void outputTime24(int hours, int minutes, char am_pm) {
    cout << "Time after waiting period: "
         << (hours < 10 ? "0" : "") << hours << ":"
         << (minutes < 10 ? "0" : "") << minutes << " "
         << am_pm << "M" << endl;
}
