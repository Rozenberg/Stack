#ifndef _TPARSER_H_
#define _TPARSER_H_
#include "TStack.h"

class TParser
{

private:
	char Inf[MaxLen];
	char Post[MaxLen];
	TStack<char> st_c;
	TStack<double> st_d;

public:
	TParser(char *str = NULL);
	bool Check_of_brackets();
	double Polish_system();
	void InfToPost();	
	char* Get_Inf() { return Inf; };
	char* Get_Post() { return Post; };
	~TParser();

private:
	int Priority(char symb);
	bool IsOpearation(char symb);
	void Normalization();
};

#endif