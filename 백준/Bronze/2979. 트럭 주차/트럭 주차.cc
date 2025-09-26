#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <stack>
#include <set>
#define INF 2147483647

using namespace std;

int a, b, c;
int cnt[101];
int sum = 0;
int x, y;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> a >> b >> c;
	for (int i = 0; i < 3; i++)
	{
		cin >> x >> y;
		for (int j = x; j < y; j++) cnt[j]++;
	}
	for (int i = 1; i < 100; i++)
	{
		if (cnt[i]) {
			if (cnt[i] == 1) sum += a;
			else if (cnt[i] == 2) sum += b * 2;
			else if (cnt[i] == 3) sum += c * 3;
		}
	}

	cout << sum;

	return 0;
}