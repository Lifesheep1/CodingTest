#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int n;
string arr[64];

void dfs(int size, int y, int x) {
	char cur = arr[y][x];

	for (int i = y; i < y+size; i++)
	{
		for (int j = x; j < x+size; j++)
		{
			if (arr[i][j] != cur) {
				cout << "(";
				dfs(size / 2, y, x); // 왼쪽위
				dfs(size / 2, y, x + size / 2); // 오른쪽위
				dfs(size / 2, y + size / 2, x); // 왼쪽아래
				dfs(size / 2, y + size / 2, x + size / 2); // 오른쪽아래
				cout << ")";
				return;
			}
		}
	}
	cout << cur;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	dfs(n,0,0); // 사이즈, 시작 좌표

	return 0;
}