#include <iostream>
#include <vector>
#include <ostream>
#include <istream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>


using namespace std;



//int fun() {

//}


int main()
{

    map <string, int> mp;
    ifstream fin;
    fin.open("text.txt");
    
    if (fin.is_open())
    {
        string str;
        int i = 1;
        while (!fin.eof())
        {
            str = "";
            fin >> str;
            cout << str<<" ";
            mp.insert(make_pair("str",i ));
            i++;
        }
    }

    
    


    fin.close();

    


    /*
    vector<int> numbers;

    size_t numbers_count;
    cin >> numbers_count;
    
    // Размер вектора остаётся нулевым, меняется только резерв:
    numbers.reserve(numbers_count);

    for (size_t i = 0; i != numbers_count; ++i)
    {
        numbers[i] = rand() % 100;

    }
    for (size_t i = 0; i < numbers_count; i++)
    {
        if (i % 2 == 0)//не четн. тк индексы начинаются с 0
        {
            if (numbers[i] > numbers[i + 2])
            {
                swap(numbers[i], numbers[i + 2]);
            }
            else
            {
                if (numbers[i] > numbers[i + 2])
                {
                    swap(numbers[i], numbers[i + 2]);
                }
            }
        }
        for (size_t i = 0; i < numbers_count; i++)
        {
            cout << numbers[i] << " ";
            cout << "\n";
        }
        
        
    }
    */
    return (0);
}
