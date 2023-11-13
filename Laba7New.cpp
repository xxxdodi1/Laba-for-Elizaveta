#include <iostream>
#include <string>

class Triangle {    
private:
    static int count;

public:
    Triangle() {
        count++;
    }

    virtual ~Triangle() {
        count--;
    }

    static int getCount() {
        return count;
    }

    virtual double getPerimeter() const = 0;
    virtual void printInfo() const = 0;
};

int Triangle::count = 0;

class EquilateralTriangle : public Triangle {           //класс равностороний треугольник
private:
    double side;

public:
    EquilateralTriangle(double s) : side(s) {}

    double getPerimeter() const override {
        return 3 * side;
    }

    void printInfo() const override {
        std::cout << "Периметр равностороннего треугольника=" << getPerimeter() << std::endl;
    }
};

class IsoscelesTriangle : public Triangle {             //класс Равнобедренный треугольник
private:
    double base;
    double legs;

public:
    IsoscelesTriangle(double a, double b) : base(a), legs(b) {}

    double getPerimeter() const override {
        return 2 * legs + base;
    }

    void printInfo() const override {
        std::cout << "Периметр равнобедренного треугольника  =" << getPerimeter() << std::endl;
    }
};

int main() {
    
    setlocale(LC_ALL, "ru");

    Triangle* eqTri1 = new EquilateralTriangle(4.0);
    std::cout << "Triangle count=" << Triangle::getCount() << std::endl;

    Triangle* eqTri2 = new EquilateralTriangle(5.0);
    std::cout << "Triangle count=" << Triangle::getCount() << std::endl;

    Triangle* isoTri = new IsoscelesTriangle(2.0, 3.0);
    std::cout << "Triangle count=" << Triangle::getCount() << std::endl;

    eqTri1->printInfo();
    eqTri2->printInfo();
    isoTri->printInfo();

    delete eqTri1;
    std::cout << "Triangle count=" << Triangle::getCount() << std::endl;

    delete eqTri2;
    std::cout << "Triangle count=" << Triangle::getCount() << std::endl;

    delete isoTri;
    std::cout << "Triangle count=" << Triangle::getCount() << std::endl;

    return 0;
}
