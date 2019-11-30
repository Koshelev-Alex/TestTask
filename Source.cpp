#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<Windows.h>
#include<iostream>

#define SIZE 8

#define GET_INDEX(x) ((x)-1)


using namespace std;

void sort(int *A, int p, int r);

void Merge(int *A, int p, int q, int r)
{
	int first, second, i;
	int *mas = new int[SIZE];
	first = GET_INDEX(p);
	second = GET_INDEX(q) + 1;
	for (i = GET_INDEX(p); i <= GET_INDEX(r); i++)
		if ((first <= GET_INDEX(q)) && ((second > GET_INDEX(r)) || (A[first] < A[second])))
		{
			mas[i] = A[first];
			first++;
		}
		else
		{
			mas[i] = A[second];
			second++;
		}
	for (i = GET_INDEX(p); i <= GET_INDEX(r); i++) A[i] = mas[i];
	delete[]mas;
};

void sort(int *A, int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		sort(A, p, q);
		sort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

int main(void)
{
	int *A = (int*)malloc(SIZE * sizeof(int));
	
	for (int i = 0; i < SIZE; i++)
	{
		cin >> A[i];
	}
	for (int i = 0; i < SIZE; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;

	sort(A, 1, SIZE);

	for (int i = 0; i < SIZE; i++)
	{
		cout << A[i] << " ";
	}
	cout << endl;
	system("pause");
}