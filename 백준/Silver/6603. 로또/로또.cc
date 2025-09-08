#include <iostream>
using namespace std;


int k;
int arr[14];
int path[14];
int used[14];

void func(int now) {
	if (now == 6) {
		for (int i = 0; i < 6; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}

	for (int i = 0; i < k; i++)
	{
		if (used[i] == 1) continue;
		if (now > 0 && path[now - 1] > arr[i]) continue;
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

	while (true) {
		cin >> k;
		if (k == 0) break;
		for (int i = 0; i < k; i++)
		{
			cin >> arr[i];
		}
		func(0);
		cout << "\n";
	}
	
	return 0;
}