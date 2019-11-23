#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <cassert>

const char* s = "";

int GetG(char*);

int GetE();

int GetT();

int GetP();

int GetN();

int main()
{
	char* str = (char*)calloc(50, sizeof(char));

	scanf("%s", str);

	int ans = GetG(str);

	printf("%d", ans);

	return 0;
}

int GetG(char* str)
{
	s = str;
	int val = GetE();
	assert(*s == '\0');

	return val;
}

int GetE()
{
	int val = 0;
	val = GetT();
	while (*s == '+' || *s == '-')
	{
		char op = *s;
		s++;
		int val2 = GetT();

		if (op == '+') 
			val += val2;
		else 
			val -= val2;
	}

	return val;
}

int GetT()
{
	int val = 0;
	val = GetP();
	while (*s == '*' || *s == '/')
	{
		char op = *s;
		s++;
		int val2 = GetP();

		if (op == '*')
			val *= val2;
		else
			val /= val2;
	}

	return val;
}

int GetP()
{
	if (*s == '(')
	{
		s++;
		int val = GetE();
		assert(*s == ')');
		s++;
		return val;
	}

	else
		return GetN();
}

int GetN()
{
	int val = 0;
	while ('0' <= *s && *s <= '9')
	{
		val = 10 * val + (*s - '0');
		s++;
	}

	return val;
}