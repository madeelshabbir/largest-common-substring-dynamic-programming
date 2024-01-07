#include<iostream>
#include<algorithm>
using namespace std;
int al = 0;
int maxLength(char* a, int n, char* b, int m, int **arr)
{
	if (n == 0 || m == 0)
		return 0;
	if (arr[n + 1][m + 1] != 9999999)
		return arr[n + 1][m + 1];
	if (a[n] == b[m])
	{
		arr[n + 1][m + 1] = maxLength(a, n - 1, b, m - 1, arr) + 1;
	}
	else
	{
		maxLength(a, n, b, m - 1, arr);
		maxLength(a, n - 1, b, m, arr);
		arr[n + 1][m + 1] = 0;
	}
	return arr[n + 1][m + 1];
}
void print(char* a, int i, char* b, int j, int **arr)
{
	if (i == 0 || j == 0 || arr[i][j] == 0 || arr[i][j] == 9999999)
		return;
	print(a, i - 1, b, j - 1, arr);
	cout << a[i-1] << endl;
}
void wrapper(char* a, int c, char* b, int d, int **arr) 
{
	maxLength(a, c - 1, b, d - 1, arr);
	int ma = 0;
	int t = 0, k = 0;
	for (int i = 0; i < c + 1; i++)
	{
		for (int j = 0; j < d + 1; j++)
		{
			cout << arr[i][j] << " ";
			if (ma < arr[i][j] && arr[i][j] != 9999999)
			{
				ma = arr[i][j];
				t = i;
				k = j;
			}
		}
		cout << endl;
	}
	print(a, t, b, k, arr);
}
int main()
{
	char a[5] = { 'A', 'D', 'B', 'B', 'H' };
	char b[7] = { 'D', 'D', 'B', 'B', 'H', 'A', 'A' };
	int n = 5;
	int m = 7;
	int **arr = new int*[n + 1];
	for (int i = 0; i < n + 1; i++)
	{
		arr[i] = new int[m + 1];
		for (int j = 0; j < m + 1; j++)
			arr[i][j] = 9999999;
	}
	wrapper(a, 5, b, 7, arr);
	system("pause");
}