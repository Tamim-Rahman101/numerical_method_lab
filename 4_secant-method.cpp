#include <bits/stdc++.h>
using namespace std;
#define total_steps 100

class Secant_Method {
private:
    double epsilon = 0.0001;
    double root, previous_root, new_root, step;
    
    double generate() {      //to generate random number between 0 - 9
        srand((int)time(0));
        return (rand() % 10);
    }

    double function(double x) {
        return x*x*x + x*x - 1;       //0.7548
        //return x*x*x - x - 1;      //1.32474
    }
    

public:
    void solve() {
        while(true) {
            root = -9 + generate();
            previous_root = generate();
            if(root != previous_root)
                break;
        }

        step = 0;
        while(step++ <= total_steps) {       //maximum 100 iterations
            new_root = root - (function(root) * (root - previous_root) /  (function(root) - function(previous_root)));
            if (abs((new_root - root) / new_root) < epsilon)
                break;

            previous_root = root;
            root = new_root;
        }

        if(step >= total_steps)
            cout << "Non Convergence!" << endl;
        else
            cout << "The root is " << root << "\n";
    }
};

int main() {
    Secant_Method secant;
    secant.solve();
    return 0;
}
