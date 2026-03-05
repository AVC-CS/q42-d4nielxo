#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double rate1 = 1.10;
    const double rate2 = 2.20;
    const double rate3 = 3.70;
    const double rate4 = 4.80;
    double total_charge;
    double weight, distance, rate;

    cout << "Enter the package weight and distance: ";
    cin >> weight >> distance;

    // TODO
    // Validate weight: 0 < weight <= 20
    if (weight <= 0 || weight > 20) {
        cout << "Invalid weight\n";
        return 0;
    }
    // Validate distance: 10 <= distance <= 3000
    if (distance < 10 || distance > 3000) {
        cout << "Invalid distance\n";
        return 0;
    }

    // Determine rate by weight
    if (weight <= 2) {
        rate = rate1;
    } else if (weight <= 6) {
        rate = rate2;
    } else if (weight <= 10) {
        rate = rate3;
    } else {
        rate = rate4;
    }

    // Calculate charge
    if (distance > 500) {
        total_charge = (distance / 500.0) * rate;
    } else {
        total_charge = rate;
    }

    cout << setw(10) << left << setprecision(2) << fixed;
    cout << total_charge << endl;

    return 0;
}
