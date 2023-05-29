#include <iostream>

using namespace std;

class BankAccount {
private:
    string ownerName;
    int accountNumber;
    float balance;
public:
    // Конструктор с параметрами
    BankAccount(string ownerName, int accountNumber, float balance) {
        this->ownerName = ownerName;
        this->accountNumber = accountNumber;
        this->balance = balance;
    }

    // Деструктор
    ~BankAccount() {}

    // Конструктор копирования
    BankAccount(const BankAccount& other) {
        ownerName = other.ownerName;
        accountNumber = other.accountNumber;
        balance = other.balance;
    }

    // Конструктор перемещения
    BankAccount(BankAccount&& other) {
        ownerName = std::move(other.ownerName);
        accountNumber = other.accountNumber;
        balance = other.balance;
    }

    // Оператор присваивания копированием
    BankAccount& operator=(const BankAccount& other) {
        if (this != &other) {
            ownerName = other.ownerName;
            accountNumber = other.accountNumber;
            balance = other.balance;
        }
        return *this;
    }

    // Оператор присваивания перемещением
    BankAccount& operator=(BankAccount&& other) {
        if (this != &other) {
            ownerName = std::move(other.ownerName);
            accountNumber = other.accountNumber;
            balance = other.balance;
        }
        return *this;
    }

    // Оператор равенства
    bool operator==(const BankAccount& other) {
        return ownerName == other.ownerName;
    }

    // Оператор больше чем
    bool operator>(const BankAccount& other) {
        return balance > other.balance;
    }

    // Оператор меньше чем
    bool operator<(const BankAccount& other) {
        return balance < other.balance;
    }

    // Оператор сложения счета и вещественного числа
    BankAccount operator+(float amount) {
        balance += amount;
        return *this;
    }

    // Оператор вывода на экран
    friend std::ostream& operator<<(std::ostream& os, const BankAccount& account) {
        os << "Owner Name: " << account.ownerName << ", Account Number: " << account.accountNumber << ", Balance: $" << account.balance;
        return os;
    }
};





int main() {
	setlocale(LC_ALL, "ru");

    BankAccount account1("Женя Баранов", 123456789, 100.0);

    //Копирование банковского счета
    BankAccount account2 = account1;
    cout << account2 << endl;

    // Перемещение банковского счета
    BankAccount account3 = move(account2);
    cout << account3 << endl;

    // Comparing BankAccounts
    BankAccount account4("Лиза Неснова", 987654321, 50.0);
    if (account1 == account4)
        cout << "Тот же владелец" << endl;
    else
        cout << "Разные владельцы" << endl;

    if (account1 > account4)
        cout << "Account 1 has more money" << endl;
    else
        cout << "Account 4 has more money" << endl;

    // Пополнение баланса банковского счета
    BankAccount account5 = account1 + 50.0;
    cout << account5 << endl;

    // Вывод информации о банковском счете
    cout <<"На счету-"<< account1 << endl;

    return 0;
}
