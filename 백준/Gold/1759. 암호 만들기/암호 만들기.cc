#include <iostream>
#include <algorithm>
using namespace std;


int L, C;
char arr[16];
char path[16];
int used[16];

bool isVowel(char ch) {
	return ch == 'a' || ch == 'e' || ch == 'i' || ch=='o' || ch == 'u';
}

void func(int now,int v, int c) { // 모음,자음
	if (now == L) {
		if (v >= 1 && c >= 2) {
			for (int i = 0; i < L; i++)
			{
				cout << path[i];
			}
			cout << "\n";
		}
		return;
	}
	for (int i = 0; i < C; i++)
	{
		if (used[i] == 1) continue;
		if (now > 0 && path[now - 1] > arr[i]) continue;
		used[i] = 1;
		path[now] = arr[i];
		if (isVowel(arr[i])) {
			func(now + 1, v + 1, c);
		}
		else {
			func(now + 1, v, c + 1);
		}
		used[i] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> L >> C;
	for (int i = 0; i < C; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + C);
	func(0,0,0);

	return 0;
}