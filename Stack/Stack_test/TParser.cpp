#include "TParser.h"

TParser::TParser(char * str): st_c(MaxLen), st_d(MaxLen)
{
	if (str == NULL) Inf[0] = '\0';
	else strcpy(Inf, str);
}

bool TParser::Check_of_brackets()
{
	st_c.Clear();
	int i = 0;
	while (Inf[i] != '\0')
	{
		if (Inf[i] == '(') st_c.Push(Inf[i]);
		if (Inf[i] == ')')
		{
			if (st_c.IsEmpty()) return false;
			st_c.Pop();
		}
		i++;
	}
	if (st_c.IsEmpty()) return true;
	else return false;
}

double TParser::Polish_system()
{

	int Max = 0;
	while (Post[Max] != '\0')
		Max++;
	TStack<double> S(Max);

	int i = 0;
	char tmp[MaxLen], tmp_post[2];
	tmp[0] = '\0';
	double EQU;
	for (int i = 0; i < Max; i++)
	{
		tmp_post[0] = Post[i]; tmp_post[1] = '\0';
		if (Post[i] != ' ')	strcat(tmp, tmp_post);
		else
			if ((tmp[0] != '^') && (tmp[0] != '*') && (tmp[0] != '/') && (tmp[0] != '+') && (tmp[0] != '-'))
			{
				double tmp_d = atof(tmp);
				tmp[0] = '\0';
				S.Push(tmp_d);
			}
			else
			{
				double a_2 = S.Pop();
				double a_1 = S.Pop();
				double c;
				switch (tmp[0])
				{
				case '^': c = pow(a_1, a_2); break;
				case '*': c = a_1 * a_2; break;
				case '/': c = a_1 / a_2; break;
				case '+': c = a_1 + a_2; break;
				case '-': c = a_1 - a_2; break;
				}
				S.Push(c); EQU = c;
				tmp[0] = '\0';
			}
		tmp_post[0] = '\0';
	}
	return EQU;
}

void TParser::InfToPost()
{
	//-----------------------------------------// 
	st_c.Clear(); int i = 0, j = 0;
	st_c.Push('='); 
	while (Inf[i] != '\0')
	{
		if (Inf[i] == '(') st_c.Push('(');
		else if (Inf[i] == ')')
		{
			char tmp = st_c.Pop();
			while (tmp != '(')
			{
				Post[j] = tmp;
				j++;
				tmp = st_c.Pop();
			}
		}
		else if (IsOpearation(Inf[i]))
		{
			char tmp = st_c.Pop();
			while (Priority(tmp) >= Priority(Inf[i]))
			{
				Post[j] = tmp;
				j++;
				tmp = st_c.Pop();
			}
			st_c.Push(tmp);
			st_c.Push(Inf[i]);
		}
		else
		{
			Post[j] = Inf[i];
			j++;
		}
		i++;
	}
	while (!st_c.IsEmpty())
	{
		Post[j] = st_c.Pop();
		j++;
	}
	//-----------------------------------------// 
	True_Polish();
}

int TParser::Priority(char symb)
{
	switch (symb)
	{
	case '(': return 0;
	case ')': return 0;
	case '+': return 1;
	case '-': return 1;
	case '*': return 2;
	case '/': return 2;
	case '^': return 3;
	default:  return -1;
	}
}

bool TParser::IsOpearation(char symb)
{
	if ((symb == '+') ||
		(symb == '-') ||
		(symb == '*') ||
		(symb == '/') ||
		(symb == '^'))
		return true; 
	else return false;
}

void TParser::True_Polish()
{
	char tmp_1[MaxLen], tmp_2[MaxLen];
	//-----------------------------------------//   удаление лишних пробелов
	int i = -1, k = 0;
	bool flag = true;
	do
	{
		i++;
		if (Post[i] != ' ')
		{
			tmp_1[k] = Post[i];
			k++;
			flag = true;
		}
		else
		{
			if (flag)
			{
				tmp_1[k] = ' ';
				k++;
				flag = false;
			}
		}
	} while (Post[i] != '\0');
	//-----------------------------------------// добавление пробелов перед знаками препинания
	i = -1; k = 0;
	do
	{
		i++;
		if ((Priority(tmp_1[i]) > 0) || (tmp_1[i] == '=')) { tmp_2[k] = ' '; k++; }
		tmp_2[k] = tmp_1[i]; k++;
	} while (tmp_1[i] != '\0');
	//-----------------------------------------// 
	i = -1;
	do
	{
		i++;
		Post[i] = tmp_2[i];
	} while (tmp_2[i] != '\0');
	//-----------------------------------------//
	i = -1, k = 0;
	flag = true;
	do
	{
		i++;
		if (Post[i] != ' ')
		{
			tmp_1[k] = Post[i];
			k++;
			flag = true;
		}
		else
		{
			if (flag)
			{
				tmp_1[k] = ' ';
				k++;
				flag = false;
			}
		}
	} while (Post[i] != '\0');
	//-----------------------------------------//
	i = -1;
	do
	{
		i++;
		Post[i] = tmp_1[i];
	} while (tmp_1[i] != '\0');
	//-----------------------------------------//
	tmp_1[0] = '\0';
	tmp_2[0] = '\0';
}

TParser::~TParser()
{
}

char* FuncToExpr(char* str_f, char symb_f, int x_f)
{
	int i = -1, j = 0, k = 0; char tmp[MaxLen], tmp_int[10];
	do
	{
		i++;
		if (str_f[i] != symb_f) { tmp[k] = str_f[i]; k++; }
		else
		{
			
			itoa(x_f, tmp_int, 10);
			while (tmp_int[j] != '\0')
			{
				tmp[k] = tmp_int[j];
				j++; k++;
			}
		}
		j = 0;
		
	} while (str_f[i] != '\0');
	return tmp;
}