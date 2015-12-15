#include "lib.h"

template <class ValType>
class TStack
{
protected:
	int MaxSize;
	int Index;
	ValType *mas;
public:
	TStack(int len = 10)
	{
		if (len < 0) throw len;
		MaxSize = len;
		Index = -1;
		mas = new ValType[MaxSize];		
	};
	TStack(const TStack &S)
	{
		MaxSize = S.MaxSize;
		Index = S.Index;
		mas = new ValType[MaxSize];
		for (int i = 0; i <= Index; i++)
			mas[i] = S.mas[i];
	};

	TStack& operator=(const TStack &S)
	{
		if (&s == this) return *this;
		if (MaxSize != S.MaxSize)
		{
			MaxSize = S.MaxSize;
			delete[]mas;
			mas = new ValType[MaxSize];
		}
		Index = S.Index;
		for (int i = 0; i <= Index; i++)
			mas[i] = S.mas[i];
		return (*this);
	};
	bool IsEmpty()
	{
		if (Index == -1) return true;
		else return false;
	};
	bool IsFull()
	{
		return (Index == MaxSize - 1);
	};
	ValType Top()
	{
		if (IsEmpty()) throw Index;
		return mas[Index];
	};
	ValType Pop()
	{
		if (IsEmpty()) throw Index;
		ValType tmp = mas[Index];
		Index--;
		return tmp;
	};
	int Size()
	{
		return (Index + 1);
	};
	void Push(const ValType x)
	{
		if (IsFull()) throw Index;
		Index++;
		mas[Index] = x;
	};
	void Clear()
	{
		Index = -1;
	};
	bool operator==(const TStack &S) const
	{
		bool f = true;
		if (Index != S.Index) f = false; else
		for (int i = 0; i <= Index; i++)
			if (mas[i] != S.mas[i]) { f = false; break; }
		return f;
	}
	bool operator!=(const TStack &S) const { return !(S == *this); }

	~TStack() 
	{ 
		delete[]mas;
	};

};