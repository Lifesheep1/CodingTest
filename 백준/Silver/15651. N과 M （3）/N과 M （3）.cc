#include <iostream>
using namespace std;

int n, m;
int used[10];
int path[10];

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
	for (int i = 1; i <= n; i++)
	{
		path[now] = i;
		func(now + 1);
		path[now] = 0;
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> n >> m;
	func(0);

	return 0;
}