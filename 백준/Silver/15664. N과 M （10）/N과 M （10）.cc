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
	int temp = 0; // 중복 수열인지 확인하기 위해 필요한 임시 변수
	for (int i = 0; i < n; i++)
	{
		if (used[i] == 1) continue;
		if (arr[i]==temp) continue; // 같은 깊이에서 같은 값을 한번만
		if (now > 0 && path[now - 1] > arr[i]) continue;
		used[i] = 1;
		path[now] = arr[i];
		temp = arr[i]; // 이번 깊이에서 이 값은 다시 쓰지않도록
		func(now + 1);
		used[i] = 0;
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