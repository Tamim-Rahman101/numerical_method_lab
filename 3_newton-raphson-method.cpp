#include <bits/stdc++.h>
using namespace std;
#define h 0.000001
#define total_steps 100

class Newton_Raphson_Method {
private:
    double epsilon = 0.0001;
    double root, previous_root, step;
    
    double generate() {      //to generate random number between 0 - 9
        srand((int)time(0));
        return (rand() % 10);
    }

    double f(double x) {

    }

    double df(double x) {
        return (f(x+h) - f(x)) / h;
    }


public:
    void solve() {
        while(true) {
            previous_root = -10 + rand() % 20;
            if (df(previous_root) != 0.0)
                break;
        }

        step = 0;
        while(step++ < total_steps) {       //maximum 100 iterations
            root = previous_root - (f(previous_root) / df(previous_root));
            
            if(f(root) == 0.0) 
                break;
            if(abs((root - previous_root) / root) < epsilon) 
                break;

            previous_root = root;
        }

        if(step >= total_steps)
            cout << "Non Convergence!" << endl;
        else
            cout << "The root is " << root << "\n";
    } 
};

int main() {
    Newton_Raphson_Method nrm;
    nrm.solve();
    return 0;
}