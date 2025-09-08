#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[10]; // index: n이 저장되는 값주소 value: n의 값들
int path[10];
int used[10];

void func(int now) {
	//종료
	if (now == m) {
		for (int i = 0; i < m; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if (used[i] == 1) continue;
		used[i] = 1;
		path[now] = arr[i];
		func(now + 1);
		used[i] = 0;
		path[now] = 0;
	}
	

}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	func(0);

	return 0;

}