/***
 *
 * Algorithm to calculate the Normal Culmulative Distribution Function based on method presented by Soch(arXiv:1512.04858).
 *
 ***/

#include<cmath>
#include<iostream>
#include<string>

double normal_cdf(double z, int sum_size);
double gaussian(double z);
double aux_polynomial(double x, int sum_size);
int double_fact(int n);
double divide_by_double_fact(double r, int n);
double c = 0.5;

int main(int argc, char** argv) {

    double z = std::atof(argv[1]);
    int n = std::atoi(argv[2]); //number of terms of the auxiliary polynomial to be calculated.

    std::cout << "Φ(" << z << ") = " << normal_cdf(z, n) << '\n';
    return 0;
}

double normal_cdf(double z, int sum_size) {
    return gaussian(z)*aux_polynomial(z, sum_size) + c;
}

double gaussian(double z) {
    return std::exp(-z*z*0.5) / std::sqrt(2*M_PI);
}

double aux_polynomial(double x, int sum_size) {
    double px = 0;

    for (int i = 1; i <= sum_size; i++) {
        px += divide_by_double_fact(std::pow(x, 2*i - 1), 2*i - 1);
    }

    return px;
}

int double_fact(int n) {
    int dfact = 1;

    for (int i = n; i > 0; i -= 2) {
        dfact *= i;
    }

    return dfact;
}

double divide_by_double_fact(double r, int n) {
    for (int i = n; i > 0; i -= 2) {
        r /= i;
    }
    return r;
}