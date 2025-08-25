#include<iostream>
#include<vector>

using namespace std;

int arr[128][128];
int cnt = 0;
int cnt1 = 0;
bool chk(int y, int x, int n) {
	int num = arr[y][x];
	for (int i = y; i < y+n; i++)
	{
		for (int j = x; j < x+n; j++)
		{
			if (num != arr[i][j]) return false;
		}
	}
	return true;
}
void func(int y, int x, int n) {
	if (chk(y,x,n)) {
		if (arr[y][x] == 0) {
			cnt++;
		}
		else if (arr[y][x] == 1) {
			cnt1++;
		}
	}
	else {
		int vol = n / 2;
		for (int i = 0; i < 2; i++)
		{
			for (int j = 0; j < 2; j++)
			{
				func(vol * i + y, vol * j + x, vol);
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	func(0, 0, n);

	cout << cnt<<"\n"<<cnt1;


	return 0;
}