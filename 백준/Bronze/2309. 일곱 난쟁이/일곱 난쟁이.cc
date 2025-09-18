#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;

int a[9];
int sum;

int main() {
	for (int i = 0; i < 9; i++)
	{
		cin >> a[i];
		sum += a[i];
	}

	sort(a, a + 9);

	int ad, bd;
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (sum - a[i] - a[j] == 100) {
				ad = i;
				bd = j;
				goto OUT;
			}
		}
	}
OUT:

	for (int i = 0; i < 9; i++)
	{
		if (i == ad || i == bd) continue;
		cout << a[i] << "\n";
	}

	return 0;

}