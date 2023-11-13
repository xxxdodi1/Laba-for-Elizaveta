#include <iostream>

using namespace std;

class Figure
{ 
public: 
    static int count;
    virtual double perimeter() = 0; 
    virtual void show() 
    {
        cout << "Figure: " << typeid(*this).name() << ", Perimeter: " << perimeter() << endl;
    }
    Figure()
    {
        count++;
    }
    virtual ~Figure() 
    {
        count--; 
    }
};

int Figure::count = 0;


class Circle : public Figure 
{
private: 
    double radius; 
    public: Circle(double r) 
    {
        radius = r; 
    } 
    double perimeter() 
    {
    return 2 * 3.14 * radius; 
    }
};

class Square : public Figure 
{
private:
    double side; 
public:
    Square(double s) { side = s; } 
    double perimeter() 
    { 
        return 4 * side; 
    }
};

class Triangle : public Figure 
{ 
private: double side1, side2, side3; 
public: 
    Triangle(double s1, double s2, double s3) { side1 = s1; side2 = s2; side3 = s3; } 
    double perimeter() 
    { 
        return side1 + side2 + side3; 
    } 
};

int main() {
    
    Figure* fig[3]; 
    fig[0] = new Circle(5); 
    fig[1] = new Square(3); 
    fig[2] = new Triangle(4, 5, 6);

    for (int i = 0; i < 3; i++)
    {
        fig[i]->show();
    }
    cout << "Number of Figures: " << Figure::count << endl;

    delete fig[0];
    delete fig[1];
    delete fig[2];

    cout << "Number of Figures: " << Figure::count << endl;

    return 0;
}
