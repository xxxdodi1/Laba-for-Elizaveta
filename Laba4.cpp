#include <iostream>
#include <cstdlib>
using namespace std;

// Определяем емкость stack по умолчанию
#define SIZE 10

// Класс для представления stack
class Stack
{
    int* arr;         
    int top;
    int capacity;

public:
    Stack(int size = SIZE);         // конструктор
    ~Stack();                       // деструктор

    void push(int);
    int pop();
    int peek();

    int size();
    bool isEmpty();
    bool isFull();
};

// Конструктор для инициализации stack
Stack::Stack(int size)
{
    arr = new int[size];
    capacity = size;    
    top = -1;
}

// Деструктор для освобождения памяти, выделенной для stack
Stack::~Stack() {
    delete[] arr;
}

// Вспомогательная функция для добавления элемента `x` в stack
void Stack::push(int x)
{
    if (isFull())
    {
        cout << "Overflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Ввод  " << x << endl;
    arr[++top] = x;
}

// Вспомогательная функция для извлечения верхнего элемента из stack
int Stack::pop()
{
    // проверка на опустошение stack
    if (isEmpty())
    {
        cout << "Underflow\nProgram Terminated\n";
        exit(EXIT_FAILURE);
    }

    cout << "Удаление " << peek() << endl;

    // уменьшаем размер stack на 1 и (необязательно) возвращаем извлеченный элемент
    return arr[top--];
}

// Вспомогательная функция для возврата верхнего элемента stack
int Stack::peek()
{
    if (!isEmpty()) {
        return arr[top];
    }
    else {
        exit(EXIT_FAILURE);
    }
}

// Вспомогательная функция для возврата размера stack
int Stack::size() {
    return top + 1;
}

// Вспомогательная функция для проверки, пуст stack или нет
bool Stack::isEmpty() {
    return top == -1;               // или return size() == 0;
}

// Вспомогательная функция для проверки, заполнен ли stack или нет
bool Stack::isFull() {
    return top == capacity - 1;     // или return size() == capacity;
}

int main()
{
    setlocale(LC_ALL, "ru");
    Stack pt(3);

    pt.push(4);
    pt.push(6);

    pt.pop();
    pt.pop();

    pt.push(2);

    cout << "Верхний элемент " << pt.peek() << endl;
    cout << "Размер стека" << pt.size() << endl;

    pt.pop();

    if (pt.isEmpty()) {
        cout << "Стек пуст\n";
    }
    else {
        cout << "Стек не пуст\n";
    }

    return 0;
}
