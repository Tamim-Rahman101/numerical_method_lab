#include <bits/stdc++.h>
using namespace std;

class Bisection_Method {
private:
    double epsilon = 0.0001;
    double lower, upper, root, previous_root = 1000; 

    double generate() {      //to generate random number between 0 - 9
        srand((int)time(0));
        return (rand() % 10);
    }

    double function(double x) {
        return x*x*x + x*x - 1;       //0.7548
        //return x*x*x - x - 1;      //1.32474
    }


public:
    void find_root() {
        while(true) {
            lower = -9 + generate();
            upper = generate();
            if (function(lower) * function(upper) < 0.0)
                break;
        }
        
        while(true) {
            root = (lower + upper) / 2;
            double condition = function(root)*function(lower);
            
            if(condition < 0.0)
                upper = root;
            else if(condition > 0.0)
                lower = root;
            else
                break;

            if(abs((root - previous_root)/root) < epsilon)
                break;
            
            previous_root = root;
        }
        cout << "The root is " << root << "\n";
    }
};

int main() {
    Bisection_Method bisect;
    bisect.find_root();
}