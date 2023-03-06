void mass()
{
    int m;
    std::cout << "Введите размерность массива-\n";
    std::cin >> m;
    int n{ m };
    int* p{ new int[n] };

    for (int i = 0; i < m; i = i++)
    {
        std::cout << "Введите элемент массива-";
        std::cin >> p[i];
    }

    for (int i = 0; i < m; i = i + 2)
    {
        std::cout << "\nНечетный элемент-";
        std::cout << p[i];
    }
    int max = 0;
    for (int i = 1; i < m; i++)
    {
        if (p[i] > max)
            max = p[i];
    }
    std::cout << "Максимальный элемент-" << max;

}


template <typename type> 
    type max(type* arr, int size) 
{
    type max = arr[0];
    for (int i = 1; i < size; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

int function(int a, int b) {
    std::cout << "\n";
    if (a < b) {
        return a;
        
    }
    return b;
    
}

double function(double a, double b) {
    std::cout << "\n";
    if (a < b) {
        return a;        
    }
    return b;
    
}



int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");
    f1::fun();
    f1::fun(0);
    f1::fun('a', 3);
    f1::fun1();
    function(10,200);
    function(19.3,200.3);
    void mass();
    
    return 0;
}
