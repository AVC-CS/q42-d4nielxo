#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double weight, distance;
    cin >> weight >> distance;

    cout << fixed << setprecision(2);

    if (weight <= 0 || weight > 20) {
        cout << "Invalid weight" << endl;
        return 0;
    }
    if (distance < 10 || distance > 3000) {
        cout << "Invalid distance" << endl;
        return 0;
    }

    double rate;
    if (weight <= 2) {
        rate = 1.10;
    } else if (weight <= 6) {
        rate = 2.20;
    } else if (weight <= 10) {
        rate = 3.70;
    } else {
        rate = 4.80;
    }

    double totalCharge;
    if (distance < 500) {
        totalCharge = rate;
    } else {
        totalCharge = (distance / 500.00) * rate;
    }

    cout << totalCharge << endl;

    return 0;
}