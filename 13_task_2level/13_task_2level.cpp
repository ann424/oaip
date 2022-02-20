// задача 13 ур 2: Удалить из строки группы символов, расположенные внутри скобок 
#include <iostream>
#include <cstring>

using namespace std;

int main()
{
    char* text, * temp;
    int  i, j, first=0, last=0;

    setlocale(LC_ALL, "ru");

    text = new char[300]; // выделяем память динамически
    temp = new char[300];

    cout << "Введите строку:\n";
    cin.getline(text, 300); // функция getline читает полностью всю строку даже с пробелами

    for (i = 0; text[i] && text[i] == ' '; i++);

    if (!text[i])
    {
        cerr << "\nВ строке слов нет.\n";

        return 1;
    }

    for (i = 0; text[i]; i++)
    {
        if (text[i] =='(')
        {
            for (i++; text[i] && text[i] != ')'; i++)
            {
                for (j = i + 1; text[j]; j++)
                    text[j - 1] = text[j];
                text[j-1] = '\0';
                i--;
            }
        }
    }

    text[i] = '\0';
    cout << "\nПолученная строка:\n" << text << endl;

  

    delete[] text;
    text = NULL;

    return 0;
}

