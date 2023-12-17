#include <iostream>
#include <cmath>
#include <tuple>
#include <float.h>
#include <cmath>

const double A = -10;
const double B = 10;
const double Eps = pow(10, -4);

double f0(double x);
double f1(double x);
double f2(double x);

std::pair<double, double> localize(double A, double B);

double chordIter(double a, double b);
double halfDivIter(double a, double b);

double newtonIter(double x);
double newtonMethod(double a, double b, double eps);
double newtonAdvMethod(double a, double b, double eps);

double f0(double x) {
    return 3*x - cos(x) - 1;
}

double f1(double x) {
    return 3 + sin(x);
}

double f2(double x) {
    return cos(x);
}

std::pair<double, double> localize(double A, double B) {    
    double i = 1; 
    while (true) {
        double step = 1/i;
        double current = A;
        while (current < B) {
            // std::cout << current << " " << current + step << '\n';
            if ( f0(current) * f0(current + step) < 0 ) {
                return std::pair<double, double>(current, current + step);
            }
            current += step;
        }
        i++;
    }
}

double haldDivIter(double a, double b) {
    return (a+b)/2;
}

double chordIter(double a, double b) {
    return a - (b-a)*f0(a)/(f0(b)-f0(a));
}

double newtonIter(double x) {
    return x - f0(x)/f1(x);
}

int main() {
    std::pair<double, double> interval = localize(-10, 10);
    std::cout << 
    std::cout << newtonMethod(interval.first, interval.first, Eps) << '\n';
    //std::cout << newtonIter(3.3) << '\n';

    return 0;
}


// double newtonAdvMethod(double a, double b, double eps) {
//     double a0 = a, b0 = b;
//     double current_x = 3.3;
//     double prev_x = (-1)*pow(10, 4);
//     while ( std::abs(current_x - prev_x) > eps ) {
//         prev_x = current_x;
//         current_x = newtonIter(prev_x);           
//         if (a <= current_x and current_x <= b) {
            
//         } 
//     }

//     return current_x;
// }

double newtonMethod(double a, double b, double eps) {
    double a0 = a, b0 = b;
    double current_x = 3.3;
    double prev_x = (-1)*pow(10, 6);
    while ( std::abs(current_x - prev_x) > eps ) {
        if (f0(a0)*f0(b0) < 0 and f1(current_x) != 0 and f2(current_x) != 0) {
            prev_x = current_x;
            current_x = newtonIter(prev_x);            
        } else {
            prev_x = current_x;
            current_x = newtonIter(prev_x);   
            if (current_x >= a0 and current_x <= b0) {
                double c = f0(current_x);
                if (c > 0) {
                    a0 = c;
                } else {
                    b0 = c;
                }
            } else {
                current_x = chordIter(a0, b0);
                double c = f0(current_x);
                if (c > 0) {
                    a0 = c;
                } else {
                    b0 = c;
                }                
                current_x = newtonIter(current_x);
            }
            std::cout << current_x << '\n';
        }
    }
    return current_x;
}