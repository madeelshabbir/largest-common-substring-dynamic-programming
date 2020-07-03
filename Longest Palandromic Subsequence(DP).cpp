#include<iostream>
#include<algorithm>
using namespace std;
int lps(char *seq, int i, int j, int** arr)
{
	if (i == j)
		return 1;
	if (seq[i] == seq[j] && i + 1 == j)
		return 2;
	if (arr[i][j] != 9999999)
		return arr[i][j];
	if (seq[i] == seq[j])
	{
		arr[i][j] = lps(seq, i + 1, j - 1, arr) + 2;
		return arr[i][j];
	}
	arr[i][j] = max(lps(seq, i, j - 1, arr), lps(seq, i + 1, j, arr));
	return arr[i][j];
}
int main()
{
	int **arr = new int*[7];
	for (int i = 0; i < 7; i++)
	{
		arr[i] = new int[7];
		for (int j = 0; j < 7; j++)
			arr[i][j] = 9999999;
	}
	cout << lps("adeleda", 0, 6, arr) << endl;
	system("pause");
}
