// ConsoleApplication1.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <Windows.h>
#include <algorithm>
#include <set>

#define BITSPERWORD 32
#define SHIFT 5
#define MASK 0x1F
#define  N 10000000
int a[1 + N / BITSPERWORD];//a[x] 是一个32位字节
int b[N];

using namespace std;
void sets(int i)//给a[x]某一位赋值1
{
	//i >> SHIFT 将i 右移 SHIFT 位数（i/32）。(1<<(i & MASK)) 想当于 000010 与 111111 求与，然后将1左移 2位。
	a[i >> SHIFT] |= (1 << (i & MASK));
}

void clr(int i)//给a[x]某一位清零
{
	a[i >> SHIFT] &= ~(1 << (i & MASK));
}

int test(int i)//判断a[x], 某个字节是否为1
{
	return a[i >> SHIFT] & (1 << (i & MASK));
}

int intcomp(const void *x, const void *y)
{
	return *(int *)x - *(int *)y;
}

void test1()
{
	for (int i = 0; i < N; i++)
		b[i] = i;
	qsort(b, N, sizeof(int), intcomp);
}

void test2(int nCount)
{
	set<int> s;
	for (int i = 0; i < nCount; i++)
	{
		s.insert(i);
	}
}
void test3(int nCount)//位移
{
	int i;
	for (i = 0; i < nCount; i++)
		clr(i);
	//while (scanf("%d", &i) != EOF)
	for (i = 0; i < nCount; i++)
	{
		sets(i);
		//int j = i >> SHIFT;
		/*int j = i & MASK;*/
		//printf("%d  ", j);
	}

	for (i = 0; i < nCount; i++)
		if (test(i))
		{
			//printf("%d  ", i);
		}
}
int main()
{
	DWORD t1, t2;
	t1 = GetTickCount();
	test1();
	t2 = GetTickCount();
	printf("Use Time:%f\n", (t2 - t1)*1.0 / 1000);//7

	t1 = GetTickCount();
	test3(N);
	t2 = GetTickCount();
	printf("Use Time:%f\n", (t2 - t1)*1.0 / 1000);//7

	t1 = GetTickCount();
	test2(1000000);
	t2 = GetTickCount();
	printf("Use Time:%f\n", (t2 - t1)*1.0 / 1000);//0.733000
    return 0;
}

