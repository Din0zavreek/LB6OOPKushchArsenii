#include <iostream>
#include "Money.h"
#include <Windows.h>

using namespace std;

int main()
{
    SetConsoleOutputCP(65001);
	SetConsoleCP(65001);

    cout << "--- Демонстрація конструкторів ---" << endl;
    MoneySpace::Money m1;
    cout << "m1 (створений за замовчуванням): "; m1.Display();

    MoneySpace::Money m2(0, 0, 7, 1, 0, 1, 0, 1, 0, 2);
    cout << "m2 (створений конструктором з параметрами): "; m2.Display();

    MoneySpace::Money m3(m2);
    cout << "m3 (копія m2): "; m3.Display();

    cout << "\n--- Ввід даних через Read() ---" << endl;
    m1.Read();
    cout << "Оновлений m1: "; m1.Display();

    cout << "\n--- Виконання перевантажених операцій ---" << endl;
    MoneySpace::Money sum = m1 + m2;
    cout << "m1 + m2 = "; sum.Display();

    MoneySpace::Money diff = m1 - m2;
    cout << "m1 - m2 = "; diff.Display();

    double divRes = m1 / m2;
    cout << "Ділення (m1 / m2): " << divRes << endl;

    double divVal = 2.2;
    cout << "Введене дробове число для ділення першої суми: " << divVal << endl;
    MoneySpace::Money divD = m1 / divVal;
    cout << "Ділення (m1 на дробове число): "; divD.Display();

    double multVal = 5.3;
    cout << "Введене дробове число для множення першої суми: " << multVal << endl;
    MoneySpace::Money multD = m1 * multVal;
    cout << "Множення (m1 на дробове число): "; multD.Display();

    cout << "\nРезультати порівняння:" << endl;
    if (m1 == m2) cout << "Суми рівні." << endl;
    else cout << "Суми не рівні." << endl;

    if (m1 > m2) cout << "Перша сума більша за другу суму." << endl;
    else cout << "Перша сума не більша за другу суму." << endl;

    return 0;
}