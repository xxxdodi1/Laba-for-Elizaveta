#pragma once
#ifndef ADD_H
#define ADD_H

#endif

namespace f1
{
    void fun()
    {
        int a = 0;
        std::cout << "Заданный символ 'a' 100 раз-";
        while (a != 100)
        {
            a++;
            std::cout << "a";
        }
        std::cout <<"\n";
    }

    void fun(char z)
    {
        int a = 0;
        std::cout << "Введите символ:";
        std::cin >> z;
        std::cout << "Данный символ 100 раз-";
        while (a != 100)
        {
            a++;
            std::cout << z;
        }
        std::cout << "\n";

    }

    void fun(char z, int b)
    {
        int a = 0;
        std::cout << "Введите символ:";
        std::cin >> z;
        std::cout << "Введите кол-во раз:";
        std::cin >> b;
        while (a!=b)
        {
            a++;
            std::cout << z;
        }
        std::cout << "\n";
    }

    void fun1()
    {
        std::cout << "Функция использующая аргументы по умолчанию:\n";
        int a = 0;
        char b = 'a';
        while (a <= 100)
        {
            a++;
            std::cout << b;
        }
        std::cout << "\n";
        int c = 0;
        char z = 'z';
        while (c <= 100)
        {
            c++;
            std::cout << z;
        }
        std::cout << "\n";
        int k = 0;
        char g = 'g';
        int l = 30;
        while (k <= l)
        {
            k++;
            std::cout << g;
        }
        std::cout << "\n";
        

    }
    
}
