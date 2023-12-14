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

int main() {
    std::pair<double, double> interval = localize(A, B);
    std::cout << interval.first << ' ' << interval.second << '\n';

    std::cout << newtonMethod(interval.first, interval.second, Eps) << '\n';


    return 0;
}


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

double chordIter(double a, double b) {
    return (a+b)/2;
}

double halfDivIter(double a, double b) {
    return a - (b-a)*f0(a)/(f0(b)-f0(a));
}

double newtonIter(double x) {
    return x - f0(x)/f1(x);
}

double newtonMethod(double a0, double b0, double eps) {
    double a = a0, b = b0;
    double prev_x = (-1)*pow(10,4);
    double current_x = a;
    while ( std::abs(prev_x - current_x) > eps) {
        prev_x = current_x;
        current_x = newtonIter(prev_x);
        if (!(current_x >= a and current_x <= b)) {
            current_x = halfDivIter(a, b);
            std::cout << "YEAH BUDDY\n";
        }
        double c = f0(current_x);
        if (c > 0) {
            b = c;
        } else {
            a = c;
        }
        std::cout << current_x << '\n';        
    } 
    return current_x;
}