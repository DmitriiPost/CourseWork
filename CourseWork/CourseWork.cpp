#include <iostream>

using namespace std;

int main()
{
    setlocale(0, "");
    int c1();
    int c2();
    int c3();
    int c4();
    short menu;
    while (true)
    {
        cout << "1. ТИПЫ ДАННЫХ И ИХ ВНУТРЕННЕЕ ПРЕДСТАВЛЕНИЕ В ПАМЯТИ\n2. ОДНОМЕРНЫЕ СТАТИЧЕСКИЕ МАССИВЫ\n3. ДВУМЕРНЫЕ СТАТИЧЕСКИЕ МАССИВЫ. УКАЗАТЕЛИ\n4. РАБОТА СО СТРОКАМИ\n0. Выход\n";
        cin >> menu;
        switch (menu)
        {
        case(1):
            c1();
            break;
        case(2):
            c2();
            break;
        case(3):
            c3();
            break;
        case(4):
            c4();
            break;
        default:
            exit(0);
        }
    }
    return 0;
}
