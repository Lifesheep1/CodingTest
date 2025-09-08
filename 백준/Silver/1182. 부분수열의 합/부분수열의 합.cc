#include <iostream>
using namespace std;

int n, s;
int arr[21];
int cnt = 0;

void func(int now, int total) {
	if (now == n) {
		if (total == s) cnt++;
		return;
	}
	func(now + 1, total);
	func(now + 1, total + arr[now]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	func(0, 0);
	if (s == 0) cnt -= 1;
	cout << cnt;

	return 0;
}