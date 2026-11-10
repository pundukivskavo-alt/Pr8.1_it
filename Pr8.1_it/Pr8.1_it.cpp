// Лабораторна робота № 8.1. Пошук та заміна символів у літерному рядку
// Варіант 20. Ітераційний спосіб
//
// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1.   Вияснити, чи є в цій послідовності такі елементи s[i-1], s[i+1],
//      що s[i-1] – це кома (','), а s[i+1] – тире ('-'), та обчислити їх кількість.
// 2.   Замінити кожну групу символів s[i-1], s[i], s[i+1] – таких, що
//      s[i-1] – це кома (','), а s[i+1] – тире ('-') парою зірочок "**".

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

// Обчислює кількість елементів s[i-1], s[i+1], таких що s[i-1] == ',' та s[i+1] == '-'
int Count(const char* str)
{
    if (strlen(str) < 3)
        return 0;

    int k = 0;
    for (int i = 1; str[i + 1] != 0; i++)
        if (str[i - 1] == ',' && str[i + 1] == '-')
            k++;

    return k;
}

// Замінює кожну групу ",?-" парою "**".
// Повертає вказівник на новий динамічний рядок; результат також записує в str.
char* Change(char* str)
{
    size_t len = strlen(str);

    if (len < 3)
        return str;

    char* tmp = new char[len + 1];  // група з 3 символів -> 2 символи, тож рядок не зростає
    char* t = tmp;
    *t = '\0';

    size_t i = 0;
    while (i < len && str[i + 2] != 0)
    {
        if (str[i] == ',' && str[i + 2] == '-')
        {
            *t++ = '*';
            *t++ = '*';
            *t = '\0';
            i += 3;                 // пропускаємо всю групу
        }
        else
        {
            *t++ = str[i++];
            *t = '\0';
        }
    }
    // копіюємо залишок рядка (останні 0, 1 або 2 символи)
    while (str[i] != 0)
        *t++ = str[i++];
    *t = '\0';

    strcpy(str, tmp);

    return tmp;
}

int main()
{
    char str[101];

    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int k = Count(str);
    cout << "String contained " << k << " groups of ', -'"
        << (k > 0 ? " (such elements exist)" : " (no such elements)") << endl;

    char* dest = Change(str);

    cout << "Modified string (param) : " << str << endl;
    cout << "Modified string (result): " << dest << endl;

    return 0;
}