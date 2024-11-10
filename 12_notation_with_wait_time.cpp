#include <iostream>
using namespace std;

// Function prototype
void inputTime(int &hours, int &minutes, char &am_pm);
void calculateNewTime(int hours, int minutes, char am_pm, int wait_hours, int wait_minutes, int &new_hours, int &new_minutes, char &new_am_pm);
void outputTime12(int hours, int minutes, char am_pm);

int main() {
    int hours, minutes, wait_hours, wait_minutes;
    char am_pm;  // AM/PM indicator for input time
    char repeat; // Variable to check if user wants to repeat

    do {
        // Get initial time in 12-hour format, including AM/PM
        inputTime(hours, minutes, am_pm);

        // Get waiting time in hours and minutes
        cout << "Enter waiting time (HH MM): ";
        cin >> wait_hours >> wait_minutes;

        int new_hours, new_minutes;
        char new_am_pm = am_pm; // Start with the same AM/PM as input

        // Calculate new time after the waiting period
        calculateNewTime(hours, minutes, am_pm, wait_hours, wait_minutes, new_hours, new_minutes, new_am_pm);

        // Output the result in 12-hour format with AM/PM
        outputTime12(new_hours, new_minutes, new_am_pm);

        // Ask if user wants to repeat the process
        cout << "Do you want to calculate another waiting period? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

// Function to get the initial time in 12-hour format with AM/PM
void inputTime(int &hours, int &minutes, char &am_pm) {
    cout << "Enter current time in 12-hour format (HH MM): ";
    cin >> hours >> minutes;

    // Prompt user to specify AM or PM
    cout << "Is this time AM or PM? Enter 'A' for AM or 'P' for PM: ";
    cin >> am_pm;

    // Convert to uppercase for consistent comparison
    if (am_pm == 'A' || am_pm == 'a') {
        am_pm = 'A';
    }
    if (am_pm == 'P' || am_pm == 'p') {
        am_pm = 'P';
    }
}

// Function to calculate the new time after adding the waiting period
void calculateNewTime(int hours, int minutes, char am_pm, int wait_hours, int wait_minutes, int &new_hours, int &new_minutes, char &new_am_pm) {
    // Convert 12-hour AM/PM to 24-hour format for easier calculation
    if (hours == 12) {  // Special case: 12 AM is 00 in 24-hour, 12 PM remains 12
        if (am_pm == 'A') {
            hours = 0;
        }
    } else if (am_pm == 'P') {
        hours += 12;
    }

    // Calculate new time in 24-hour format
    int total_minutes = hours * 60 + minutes + wait_hours * 60 + wait_minutes;
    new_hours = (total_minutes / 60) % 24;   // Convert back to hours, mod 24 to wrap around
    new_minutes = total_minutes % 60;        // Remaining minutes after hours calculation

    // Determine AM/PM based on the new hour in 24-hour format
    if (new_hours >= 12) {
        new_am_pm = 'P';
        if (new_hours > 12) {  // Convert to 12-hour format for PM times
            new_hours -= 12;
        }
    } else {
        new_am_pm = 'A';
        if (new_hours == 0) {  // Midnight case
            new_hours = 12;
        }
    }
}

// Function to output the result in 12-hour format with AM/PM
void outputTime12(int hours, int minutes, char am_pm) {
    cout << "Time after waiting period: "
         << hours << ":" << (minutes < 10 ? "0" : "") << minutes
         << " " << am_pm << "M" << endl;
}
