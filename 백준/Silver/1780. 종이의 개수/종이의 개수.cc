#include<iostream>

using namespace std;

int n;
int cnt_1 = 0; // -1개수
int cnt_2 = 0; // 0개수
int cnt_3 = 0; // 1개수
int arr[2200][2200];

bool isSame(int y, int x, int n) {
	int num = arr[y][x];
	for (int i = y; i < y+n; i++)
	{
		for (int j = x; j < x+n; j++)
		{
			if (num != arr[i][j]) {
				return false;
			}
		}
	}
	return true;
}
void func(int y, int x, int n) {// 숫자가 같으면 cnt++;
	if (isSame(y,x,n)) {
		if (arr[y][x] == -1) {
			cnt_1++;
		}
		else if (arr[y][x] == 0) {
			cnt_2++;
		}
		else if (arr[y][x] == 1) {
			cnt_3++;
		}
	}
	else {
		int volume = n / 3;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				func(volume * i + y, volume * j + x, volume);
			}
		}
	}
	
		
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
		}
	}

	func(0, 0, n);

	cout << cnt_1 << "\n" << cnt_2 << "\n" << cnt_3;
	
	return  0;
}