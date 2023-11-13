#include <iostream>
#include <string>
#include <memory>

using namespace std;

//Public — доступ открыт всем, кто видит определение данного класса.
//Private — доступ открыт самому классу(т.е.функциям - членам данного класса) и друзьям(friend) данного класса, как функциям, так и классам.
//Protected — доступ открыт классам, производным от данного



class Car {
protected:
    string _brand;
    string _model;
    int _year;
    int _price;
    

public:
    // Конструктор без параметров, инициализирует поля значениями по умолчанию
    Car() : _brand(""), _model(""), _year(0), _price(0) {}      //конструктор по умолчанию
    Car(std::string brand, std::string model, int year, int price)
        : _brand(brand), _model(model), _year(year), _price(price) {}

    virtual ~Car() {}    //диструктор Виртуальная функция — это функция-член, которую предполагается переопределить в производных классах.

    int value;

    Car(int v) : value(v) {}        

    //сеттеры для всех полей 
    void setBrand(std::string brand) {
        _brand = brand;
    }

    void setModel(std::string model) {
        _model = model;
    }

    void setYear(int year) {
        _year = year;
    }
    void setPrice(int price)
    {
        _price = price;
    }

    // Геттеры для всех  полей
    string getBrand() { return _brand; }
    string getModel() { return _model; }
    int getYear() { return _year; }
    int setPrice() { return _price; }

    void startEngine() {
        std::cout << "Starting the " << _brand << " " << _model << " engine..." << std::endl;
    }

    void stopEngine() {
        std::cout << "Stopping the " << _brand << " " << _model << " engine..." << std::endl;
    }

    void accelerate() {
        std::cout << "Accelerating the " << _brand << " " << _model << "..." << std::endl;
    }

    // Метод, который возвращает строку с описанием автомобиля
    string toString() {
        return "Brand: " + _brand + "\nModel: " + _model + "\nYear: " + to_string(_year) + "\nPrice: " + to_string(_price);
    }
    //метод,Который выводит приветствие владельца автомобиля 
    void sayHello(string ownerName) {
        cout << "Hello, my name is " << ownerName << " and I have a " << _brand << " " << _model << " from " << _year << ",which is worth " << _price << "." << endl;
    }
};



class LuxCar :public Car      //наследование класса Car
{
private:
    string _Luke;        //
public:
    //создает объект по значению через конструктор;
    LuxCar(int v) : Car(v) {}
    void createParentObject() {
        Car obj(10);
        std::cout << "Получен объект Car по значению: " << obj.value << std::endl;
    }



    LuxCar(std::string brand, std::string model, int year, int price)
        : Car(brand, model, year, price), _Luke(_Luke) {}
    void burnout() {
        std::cout << "class LuxCar" << endl;
        std::cout << _model << " " << _brand << "-Have Luke " << "!\n" << std::endl;
    }
    
    
};



class SportsCar : public Car {
protected:
    int _maxSpeed; // максимальная скорость
public:



    // создает объект с помощью умного указателя unique_ptr;
    SportsCar(int v) : Car(v) {}
    void createParentObject() {
        std::unique_ptr<Car> ptr(new Car(30));
        std::cout << "Получен объект Car по умному указателю unique_ptr: " << ptr->value << std::endl;
    }



    SportsCar(std::string brand, std::string model, int year, int price,int _maxSpeed)
        : Car(brand, model, year, price), _maxSpeed(_maxSpeed) {}

    void drift() {
        std::cout << "\nclass SportsCar" << endl;
        std::cout << "Drifting the " << _brand << " " << _model << "!\n" << std::endl;
    }


    
};



class SuperSportCar : public SportsCar
{
private:
    bool hasNitro;

public:
    SuperSportCar( string brand, string model, int year, int price, int maxSpeed, bool nitro)
        : SportsCar(brand, model, year, price, maxSpeed), hasNitro(nitro) {}
    SuperSportCar(int v) : SportsCar(v) {}

    //Car по умному указателю shared_ptr
    void createParentObject() {
        std::shared_ptr<Car> ptr(new Car(40));
        std::cout << "Получен объект Car по умному указателю shared_ptr: " << ptr->value << std::endl;
    }


    void useNitro()
    {
        if (hasNitro) {
            cout << "class SuperSportCar" << endl;
            std::cout << _model << " is now using nitro!\n\n";
        }
        else {
            cout << "class SuperSportCar" << endl;
            std::cout << _model << " doesn't have nitro installed.\n\n";
        }
    }
    bool hasNitroInstalled() 
    {
        return hasNitro;
    }

    
};



int main() {
    setlocale(LC_ALL, "ru");   


    Car myCar;
    myCar.setBrand("Lamborghini");
    myCar.setModel("Urus");
    myCar.setYear(2023);
    myCar.setPrice(30000000);
    myCar.startEngine();
    myCar.accelerate();

    cout << myCar.toString() << endl;//вывод описания автомобиля 
    myCar.sayHello("Elizaveta");//Выводит приветствие владельца 


    SportsCar mspor("Lamborghini", "Urus", 2023, 30000000,3);
    mspor.drift();
    mspor.createParentObject();

    
    bool value = true;
    SuperSportCar super("Lamborghini", "Urus", 2023, 30000000, 3,value);
    super.useNitro();
    super.createParentObject();

    LuxCar Lux("Lamborghini", "Urus", 2023, 30000000);
    Lux.burnout();
    Lux.createParentObject();
    //Car myCar2("Toyota", "Corolla", 2015, 12000);
    //cout << myCar2.toString() << endl;//вывод описания автомобиля 
    //myCar2.sayHello("Elizaveta");//Выводит приветствие владельца 
    //cout << "\n\n\n";

    


    return 0;

} 
