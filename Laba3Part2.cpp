#include <iostream>
#include <vector>
#include <ostream>
#include <istream>
#include <map>
#include <fstream>
#include <string>
#include <algorithm>
#include <iterator>
#include <cstdlib>


using namespace std;

string str;

void fun(map<string, int>mp) {
    for (auto elem : mp)
    {
        cout<< "map[" << elem.first<< "]="<< elem.second << endl;
    }

}



int main()
{
    setlocale(LC_ALL, "ru");
    map <string, int> mp;
    ifstream fin;
    fin.open("text.txt");
    int abc = 0;
    if (fin.is_open())
    {
        
        int i = 1;
        while (!fin.eof())
        {
            str = "";
            fin >> str;
            size_t pos = 0;
            const char del = ' ';
            while (pos != str.npos) {
                pos = str.find_first_not_of(del, pos);
                if (pos == str.npos) break;
                if(str[pos]=='a'|| str[pos] == 'b'||str[pos] == 'c') {
                    std::cout << str[pos] << " "<<del;
                    pos = str.find(del, pos + 1);
                    abc++;
                }
                else {
                    str[pos] << del;
                    pos = str.find(del, pos + 1);
                }
            }
            
            
            
            if (mp.count(str) == 0)
            {
           
                mp.insert(make_pair(str, 1));
            }
            else
            {
                mp[str]++;
            }
            
        }
        
            
        
    }

    fun(mp);
    cout << "Кол-во слов начинающихся на a,b,c-" << abc;

    fin.close();
    return (0);
}
