#include <bits/stdc++.h>
using namespace std;

class Least_Square_Method {
private:
    int size;
    double x[100], y[100];

    // y = ax + b
    double a, b, xSum, ySum, xySum, xxSum;


public:
    void fit_the_curve() {
        cout << "Number of points: ";
        cin >> size;
        cout << "Enter " << size << " points: " << endl;
        for(int i = 0; i<size; i++) {
            cin >> x[i] >> y[i];
        }
        
        xSum = ySum = xySum = xxSum = 0.0;
        for(int i = 0; i<size; i++) {
            xSum += x[i];
            ySum += y[i];
            xxSum += x[i] * x[i];
            xySum += x[i] * y[i];
        }
        
        a = (size * xySum - xSum * ySum) / (size * xxSum - xSum * xSum);
        b =  (ySum - a * xSum) / size;

        cout << "The value of a = " << a << endl;
        cout << "The value of b = " << b << endl;
        cout << fixed << setprecision(4) << "Y  =  " << a << "x  +  " << b << endl;
    }
};

int main() {
    Least_Square_Method lscf;
    lscf.fit_the_curve();
    return 0;
}

/*
4
50 12
70 15
100 21
120 25

Y  =  0.1879x  +  2.276
*/