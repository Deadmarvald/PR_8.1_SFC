// Lab_08_1_SFC.cpp
// Вольвенко Іван
// Лабораторна робота № 8.1(SFC)
// Пошук та заміна символів у літерному рядку
// Варіант 13

#pragma warning(disable : 4996)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

using namespace std;

int Count(char* str)
{
	if (strlen(str) < 3)
		return -1;
	else
	{
		int k = 0, pos = 0;
		char* t;
		while (t = strchr(str + pos, '!'))
		{
			pos = t - str + 1;
			if (str[pos + 1] == '!')
				if (str[pos - 1] == '!')
					k++;
		}
		return k;
	}
}

char* Change(char* str)
{
	char* t = new char[strlen(str)];
	char* p = 0;
	int pos1 = 0, pos2 = 0;
	*t = 0;

	while (p = strchr(str + pos1, '!'))
	{
		if (str[p - str + 1] == '!')
		{
			if (str[p - str + 2] == '!')
			{
				pos2 = p - str + 3;
				strncat(t, str + pos1, pos2 - pos1 - 3);
				strcat(t, "**");
				pos1 = pos2;
			}
		}
	}
	strcat(t, str + pos1);

	strcpy(str, t);

	return t;
}

int main()
{
	char str[228];

	cout << "Enter String:" << endl;
	cin.getline(str, 227);

	if (Count(str) == -1)
		cerr << "Enter more characters" << endl;
	else
	{
		cout << "String conteined " << Count(str) << " groups of '!!!'" << endl;

		char* dest = new char[228];
		dest = Change(str);

		cout << "Modified string (param): " << str << endl;
		cout << "Modified string (result): " << dest << endl;
	}

	return 0;
}