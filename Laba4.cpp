#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "ru");
    int steck[20];
    int i = -1;  // объявили стек

    for (int j = 0; j < 3; j++) {
        int a;

        cin >> a;

        i++;  // увеличиваем i на один

        steck[i] = a;  // добавляем в стек элемент
    }

    if (i == -1) cout << "Стек пуст\n";  // проверяем пуст ли стек (нет)

    cout << steck[i] << " это верхний элемент стека\n";

    cout << "Сейчас мы удалим верхний элемент\n";

    i--;  // уменьшаем i на один

    cout << steck[i]<<"Новый верхний элемент стека";

    system("pause");
    return 0;
}
