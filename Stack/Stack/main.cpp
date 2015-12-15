#include "TParser.h"
#define MaxStart 100
int main()
{
	TParser expr_1, expr_2;
	setlocale(LC_ALL, "RUS");
	int tr, i = 0, min_lim, max_lim;
	char var_f, str_f[MaxLen];
	do
	{
		system("CLS");
		cout << "1 - Проверить расстановку скобок" << endl;
		cout << "2 - Проверить выражение" << endl;
		cout << "0 - Выход из программы \n" << endl;
		cout << "Введите число: ";
		cin >> tr;
		switch (tr)
		{
		case 1:
			system("CLS");
			//-----------------------------------------//
			getchar(); gets_s(expr_1.Get_Inf(), MaxLen);
			if (expr_1.Check_of_brackets()) cout << endl << "true\n\n";
			else cout << endl << "false" << endl << endl;
			//-----------------------------------------//
			system("pause");
			break;
		case 2:
			system("CLS");
			//-----------------------------------------//
			getchar(); gets_s(expr_2.Get_Inf(), MaxLen);
			expr_2.InfToPost();
			cout << endl << expr_2.Get_Inf() << " = " << expr_2.Polish_system() << "\n\n";
			//-----------------------------------------//
			system("pause");
			break;
		case 0:
			system("CLS");
			tr = 0;
			break;
		}
	} while (tr);
	return 0;
}

