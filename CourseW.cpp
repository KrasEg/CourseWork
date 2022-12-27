#include <iostream>
#include "course.h"

using namespace std;

int main()
{
    setlocale(0, "");
    char input;

Menu: {
    system("cls");
    cout << "Введите номер работы:\n"
        "1. Типы данных и их внутреннее представление в памяти.\n"
        "2. Одномерные статические массивы.\n"
        "3. Двумерные статические массивы. Указатели.\n"
        "4. Текстовые строки.\n"
        "5. Wake up to reality.\n";
    }
cin >> input;

switch (input) {
case '1': {
    system("cls");
    course1();
    system("pause");
    goto Menu;
}
case '2': {
    system("cls");
    course2();
    system("pause");
    goto Menu;
}
case '3': {
    system("cls");
    course3();
    system("pause");
    goto Menu;
}
case '4': {
    system("cls");
    course4();
    system("pause");
    goto Menu;
}
default: {
    goto Menu;
}
case '5': {
    exit;
}
}
}