#include <iostream>
#include <algorithm>


using namespace std;

class Polynomial {
    int degree;
    double* coefficients;

public:
    Polynomial() {
        degree = 0;
        coefficients = new double[1];
        coefficients[0] = 0;
        cout << "Default Constructor" << endl;
    }

    Polynomial(int deg, double* coeff) {
        degree = deg;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = coeff[i];
        }
        cout << "Parametrized Constructor" << endl;
    }

    Polynomial(const Polynomial& p) {
        degree = p.degree;
        coefficients = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coefficients[i] = p.coefficients[i];
        }
        cout << "Copy Constructor" << endl;
    }

    ~Polynomial() {
        delete[] coefficients;
        cout << "Destructor" << endl;
    }

    Polynomial operator+(const Polynomial& p2) const {
        int maxDegree = max(degree, p2.degree);
        auto coeff = std::make_unique<double[]>(maxDegree + 1);

        for (int i = 0; i <= maxDegree; i++) {
            double c1 = (i <= degree) ? coefficients[i] : 0;
            double c2 = (i <= p2.degree) ? p2.coefficients[i] : 0;
            coeff[i] = c1 + c2;
        }
        Polynomial result(maxDegree, coeff.get());
        return result;
    }

    Polynomial operator-(const Polynomial& p2) const {
        int maxDegree = max(degree, p2.degree);
        auto coeff = std::make_unique<double[]>(maxDegree + 1);

        for (int i = 0; i <= maxDegree; i++) {
            double c1 = (i <= degree) ? coefficients[i] : 0;
            double c2 = (i <= p2.degree) ? p2.coefficients[i] : 0;
            coeff[i] = c1 - c2;
        }

        Polynomial result(maxDegree, coeff.get());
        return result;
    }

    Polynomial operator*(double d) const {
        double* coeff = new double[degree + 1];
        for (int i = 0; i <= degree; i++) {
            coeff[i] = coefficients[i] * d;
        }
        Polynomial result(degree, coeff);
        delete[] coeff;
        return result;
    }

    friend Polynomial operator+(const Polynomial& p, double d) {
        double* coeff = new double[p.degree + 1];
        for (int i = 0; i <= p.degree; i++) {
            coeff[i] = p.coefficients[i];
        }
        coeff[0] += d;
        Polynomial result(p.degree, coeff);
        return result;
    }

    friend Polynomial operator+(double d, const Polynomial& p) {
        double* coeff = new double[p.degree + 1];
        for (int i = 0; i <= p.degree; i++) {
            coeff[i] = p.coefficients[i];
        }
        coeff[0] += d;
        Polynomial result(p.degree, coeff);
        return result;
    }

    friend Polynomial operator*(const Polynomial& p, double d) {
        double* coeff = new double[p.degree + 1];
        for (int i = 0; i <= p.degree; i++) {
            coeff[i] = p.coefficients[i] * d;
        }
        Polynomial result(p.degree, coeff);
        return result;
    }

    friend Polynomial operator*(double d, const Polynomial& p) {
        double* coeff = new double[p.degree + 1];
        for (int i = 0; i <= p.degree; i++) {
            coeff[i] = p.coefficients[i] * d;
        }
        Polynomial result(p.degree, coeff);
        return result;
    }

    Polynomial& operator=(const Polynomial& p) {
        if (this != &p) {
            delete[] coefficients;
            degree = p.degree;
            coefficients = new double[degree + 1];
            for (int i = 0; i <= degree; i++) {
                coefficients[i] = p.coefficients[i];
            }
        }
        return *this;
    }

    friend ostream& operator<<(ostream& os, const Polynomial& p) {
        for (int i = p.degree; i >= 0; i--) {
            os << p.coefficients[i] << "x^" << i << " ";
        }
        return os;
    }
};

int main() {
    double c1[] = {2, 3, 5};
    Polynomial p1(2, c1);
    cout << "p1: " << p1 << endl;

    double c2[] = {1, 4, 6, 2};
    Polynomial p2(3, c2);
    cout << "p2: " << p2 << endl;

    Polynomial p3 = p1 + p2;
    cout << "p3 = p1 + p2: " << p3 << endl;

    Polynomial p4 = p1 - p2;
    cout << "p4 = p1 - p2: " << p4 << endl;

    Polynomial p5 = p1 + 2;
    cout << "p6 = p1 + 2: " << p5 << endl;

    Polynomial p6 = 2 + p1;
    cout << "p6 = 2 + p1: " << p6 << endl;


    Polynomial p7 = 0 * p1;
    cout << "p7 = 0 * p1: " << p7 << endl;

    p1 = p2;
    cout << "p1 = p2: " << p1 << endl;

    return 0;
}
