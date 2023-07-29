//NOT VERIFIED
#include<bits/stdc++.h>
using namespace std;

class Polynomial_Method {
private:
    int size = 5;
    double x[100], y[100];
    
    //ax2 + bx + c = y
    double a, b, c, xsum, x2sum, x3sum, x4sum, ysum, xysum, x2ysum;
    double p[2], q[2], r[2];


public:
    void fit_the_curve() {
        cout << "Number of points: ";
        cin >> size;
        cout << "Enter " << size << " points: " << endl;
        for(int i = 0; i<size; i++) {
            cin >> x[i] >> y[i];
        }

        xsum = x2sum = x3sum = x4sum = ysum = xysum = x2ysum = 0;
        for(int i = 0; i<size; i++) {
            xsum += x[i];
            x2sum += x[i]*x[i];
            x3sum += x[i]*x[i]*x[i];
            x4sum += x[i]*x[i]*x[i]*x[i];
            ysum += y[i];
            xysum += x[i]*y[i];
            x2ysum += x[i]*x[i]*y[i];
        }

        //after eliminating a from first three equations we get 
        //bp0 + cq0 = r0
        //bp1 + cq1 = r1
        if(x2sum * x3sum < 0.0) {           //if the constent with a are of opposite sign
            p[0] = ((xsum * x3sum) + (x2sum * x2sum));
            q[0] = ((size * x3sum) + (xsum * x2sum));
            r[0] = ((ysum * x3sum) + (xysum * x2sum));
        }
        else {                              //if the constent with a are of same sign
            p[0] = ((xsum * x3sum) - (x2sum * x2sum));
            q[0] = ((size * x3sum) - (xsum * x2sum));
            r[0] = ((ysum * x3sum) - (xysum * x2sum));
        }

        if(x3sum * x4sum < 0.0) {           //if the constent with a are of opposite sign
            p[1] = ((x2sum * x4sum) + (x3sum * x3sum));
            q[1] = ((xsum * x4sum) + (x2sum * x3sum));
            r[1] = ((xysum * x4sum) + (x2ysum * x3sum));
        }
        else {                              //if the constent with a are of same sign
            p[1] = ((x2sum * x4sum) - (x3sum * x3sum));
            q[1] = ((xsum * x4sum) - (x2sum * x3sum));
            r[1] = ((xysum * x4sum) - (x2ysum * x3sum));
        }
        
        c = ((p[0] * r[1] - r[0] * p[1]) / (p[0] * q[1] - q[0] * p[1]));
        b = ((r[0] - c * q[0]) / p[0]);
        a = ((ysum - b * xsum - size * c) / x2sum);

        cout << "a = " << a << endl;
        cout << "b = " << b << endl;
        cout << "c = " << c << endl;
    }

};

int main() {
    Polynomial_Method pm;
    pm.fit_the_curve();
    return 0;
}

/*
Test case 1
5
0 1
1 1.8
2 1.3
3 2.5
4 6.3

a = 0.55
b = -1.07
c = 1.42

Test case 2
3
1 4
2 0
3 12

a = 8
b = -28
c = 24

Test case 3
5
-2 -19
-1 -10
0 -5
2 -7
1 -4

a = -2
b = 3
c = -5
*/