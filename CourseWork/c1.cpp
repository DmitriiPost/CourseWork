#include <iostream>

using namespace std;

int getSeniorDegreeOfTwo(int number)
{
	int i = 1;
	int n = 2;
	if (number < 0)
	{
		number = -number;
	}
	while (number >= n)
	{
		n = n * 2;
		i = i + 1;
	}
	return i;
}

void newNum(int num, int intOrFloat)
{
	unsigned int mask = 2;
	int order = sizeof(int) * 8 / 2;
	for (int i = 0; i < order - 1; i++)
	{
		mask = (mask << 2) + 2;
	}
	if (num > 0)
	{
		num = num | mask;
	}
	else
	{
		num = num & mask;
	}
	unsigned mask1 = 1 << order * 2 - 1;
	if (intOrFloat == 1)
	{
		for (int i = 0; i < order * 2; i++)
		{
			cout << ((num & mask1) ? 1 : 0);
			mask1 = mask1 >> 1;
			if (!i)
			{
				cout << " ";
			}
		}
	}
	else if (intOrFloat == 2)
	{
		mask1 = 1 << order * 2 - 1;
		for (int i = 1; i < order * 2; i++)
		{
			cout << ((num & mask1) ? 1 : 0);
			mask1 = mask1 >> 1;
			if (i == 8)
			{
				cout << " ";
			}
		}
	}
	else
	{
		unsigned int mask1 = 1 << order * 2 - 1;
		for (int j = 0; j < order * 2; j++)
		{
			cout << ((num & mask1) ? 1 : 0);
			mask1 = mask1 >> 1;
			if ((j == 10) || (j == 0))
			{
				cout << " ";
			}
		}
	}
}

void sizeOfTypes()
{
	cout << "int: " << sizeof(int) << '\n' << "short int: " << sizeof(short int) << '\n' << "long int: " << sizeof(long int) << '\n' << "float: " << sizeof(float) << '\n' << "double: " << sizeof(double) << '\n' << "long double: " << sizeof(long double) << '\n' << "char: " << sizeof(char) << '\n' << "bool: " << sizeof(bool) << '\n';
}

void showBinaryInt()
{
	int num;
	cout << "Введите целое число" << '\n';
	cin >> num;
	int order = sizeof(int) * 8;
	unsigned int mask = 1 << order - 1;
	cout << '\n';
	cout << num << " " << mask << " " << &num << '\n';
	int seniorDegree = getSeniorDegreeOfTwo(num);
	cout << ((num & mask) ? 1 : 0);
	cout << " ";
	mask = mask >> 1;
	for (int i = 1; i < order; i++)
	{
		cout << ((num & mask) ? 1 : 0);
		mask = mask >> 1;
		if (!i)
		{
			cout << " ";
		}
		if (i == order - seniorDegree - 1)
		{
			cout << " ";
		}
	}
	cout << '\n';
	cout << "Хотите ли вы увидеть ИДЗ?\n1. Да\n0. Нет\n";
	int choise;
	cin >> choise;
	if (choise == 1)
	{
		newNum(num, 1);
		cout << '\n';
	}
}

void showBinaryFloat()
{
	int order = sizeof(int) * 8;
	union
	{
		int num;
		float floatNum;
	};
	cout << '\n' << "Введите вещественное число" << '\n';
	cin >> floatNum;
	cout << '\n';
	cout << num << " " << num << " " << &floatNum << " " << floatNum << '\n';
	unsigned mask = 1 << order - 1;
	cout << ((num & mask) ? 1 : 0);
	cout << " ";
	mask = mask >> 1;
	for (int i = 1; i < order; i++)
	{
		cout << ((num & mask) ? 1 : 0);
		mask = mask >> 1;
		if (i == 8)
		{
			cout << " ";
		}
	}
	cout << '\n';
	cout << "Хотите ли вы увидеть ИДЗ?\n1. Да\n0. Нет\n";
	int choise;
	cin >> choise;
	if (choise == 1)
	{
		newNum(num, 2);
		cout << '\n';
	}
}

void showBinaryDouble()
{
	union
	{
		int nums[2];
		double num;
	};
	cout << '\n' << "Введите вещественное число" << '\n';
	cin >> num;
	cout << '\n';
	cout << &nums << " " << nums[0] << " " << nums[1] << " " << &num << " " << num << '\n';
	int k = 1;
	int order = sizeof(int) * 8;
	for (int i = 1; i >= 0; i--)
	{
		unsigned int mask = 1 << order - 1;
		for (int j = i; j < order; j++)
		{
			cout << ((nums[i] & mask) ? 1 : 0);
			mask = mask >> 1;

			if ((k == 11) || (k == 1))
			{
				cout << " ";
			}
			k++;
		}
	}
	cout << '\n';
	cout << "Хотите ли вы увидеть ИДЗ?\n1. Да\n0. Нет\n";
	int choise;
	cin >> choise;
	if (choise == 1)
	{
		for (int i = 1; i >= 0; i--)
		{
			newNum(nums[i], 3);
		}
	}
	cout << '\n';
}

int c1()
{
	setlocale(0, "");
	short menu;
	bool resume1 = true;
	while (resume1)
	{
		cout << "1. Типы данных\n2. Целое число\n3. Float число\n4. Double число\n0. Выход\n";
		cin >> menu;
		switch (menu)
		{
		case(1):
			sizeOfTypes();
			break;
		case(2):
			showBinaryInt();
			break;
		case(3):
			showBinaryFloat();
			break;
		case(4):
			showBinaryDouble();
			break;
		default:
			resume1 = false;
		}
	}
	return 0;
} 
