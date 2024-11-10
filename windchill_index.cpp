#include <iostream>
#include <cmath>
using namespace std;

double calculateWindchill(double temperature, double wind_speed);

int main() {
    double temperature, wind_speed;
    char repeat;

    do {
        cout << "Enter temperature (in degrees Celsius, <= 10): ";
        cin >> temperature;

        if (temperature > 10) {
            cout << "Temperature must be 10 degrees Celsius or less.\n";
            continue;
        }

        cout << "Enter wind speed (in m/s): ";
        cin >> wind_speed;

        double windchill = calculateWindchill(temperature, wind_speed);
        cout << "The windchill index is: " << windchill << "°C" << endl;

        cout << "Do you want to calculate another windchill index? (y/n): ";
        cin >> repeat;
    } while (repeat == 'y' || repeat == 'Y');

    return 0;
}

double calculateWindchill(double temperature, double wind_speed) {
    return 13.12 + 0.6215 * temperature - 11.37 * pow(wind_speed, 0.16) + 0.3965 * temperature * pow(wind_speed, 0.16);
}
