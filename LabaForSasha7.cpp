#include <iostream>
#include <cmath>
#include <string>
using namespace std;

class Figure {
protected:
    static int count;
public:
    virtual double calcRadius() = 0;

    virtual void printInfo() {
        cout << "Unknown figure" << endl;
    }

    Figure() {
        count++;
    }

    virtual ~Figure() {
        count--;
    }

    static int getCount() {
        return count;
    }
};

int Figure::count = 0;

class Triangle : public Figure {
private:
    double a, b, c;

public:
    Triangle(double a, double b, double c) {
        this->a = a;
        this->b = b;
        this->c = c;
    }

    double calcRadius() override {
        return (a * b * c) / (4 * sqrt(pow(a + b + c, 2) * (b + c - a) * (c + a - b) * (a + b - c)));
    }

    void printInfo() override {
        cout << "Triangle with radius " << calcRadius() << endl;
    }
};

class Rectangle : public Figure {
private:
    double width, height;

public:
    Rectangle(double width, double height) {
        this->width = width;
        this->height = height;
    }

    double calcRadius() override {
        return sqrt(pow(width, 2) + pow(height, 2)) / 2;
    }

    void printInfo() override {
        cout << "Rectangle with radius " << calcRadius() << endl;
    }
};

class Circle : public Figure {
private:
    double radius;

public:
    Circle(double radius) {
        this->radius = radius;
    }

    double calcRadius() override {
        return radius;
    }

    void printInfo() override {
        cout << "Circle with radius " << calcRadius() << endl;
    }
};

int main() {
    Figure* figures[3];

    figures[0] = new Triangle(3, 4, 5);
    figures[1] = new Rectangle(5, 6);
    figures[2] = new Circle(8);

    for (int i = 0; i < 3; i++) {
        figures[i]->printInfo();
        delete figures[i];
    }

    cout << "Number of figures: " << Figure::getCount() << endl;
    return 0;
}
