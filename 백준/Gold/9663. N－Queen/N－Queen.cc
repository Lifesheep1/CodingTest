#include <iostream>
using namespace std;

bool isused1[40]; // 같은열
bool isused2[40]; // 좌상대각
bool isused3[40]; // 우하대각

int cnt = 0;
int n;

void func(int cur) {
	//종료조건
	if (cur == n) {
		cnt++;
		return;
	}

	for (int i = 0; i < n; i++)
	{
		if (isused1[i] || isused2[i + cur] || isused3[cur - i + n - 1]) continue;
		isused1[i] = 1;
		isused2[i + cur] = 1;
		isused3[cur - i + n - 1] = 1;
		func(cur + 1);
		isused1[i] = 0;
		isused2[i + cur] = 0;
		isused3[cur - i + n - 1] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n;
	func(0);

	cout << cnt;

	return 0;
}