#include <iostream>
#include <vector>

using namespace std;

int main()
{
    std::vector<int> numbers;

    size_t numbers_count;
    std::cin >> numbers_count;
    numbers.resize(numbers_count);

    for (size_t i = 0; i != numbers_count; i++)
    {
        numbers[i] = rand() % 200 - 100;
        cout << numbers[i] << " ";

    }
    cout << endl;
    int flag = 0;
    for (size_t t = 0; t != numbers_count; t++)
    {

        if (t % 2 == 0)
        {
            flag = 0;
            for (size_t i = 0; i < numbers_count - 1; i += 2)
            {
                if (numbers[i] > numbers[i + 1])
                {
                    swap(numbers[i], numbers[i + 1]);
                    flag++;
                }
            }
        }
        else
        {
            for (size_t i = 1; i < numbers_count - 1; i += 2)
            {
                if (numbers[i] > numbers[i + 1])
                {
                    swap(numbers[i], numbers[i + 1]);
                    flag++;
                }
            }
        }
        for (size_t i = 0; i < numbers_count; i++)
        {
            cout << numbers[i] << " ";
        }
        cout << endl;
        if (t % 2 != 0 && flag == 0)
            break;


    }

    return (0);
}
