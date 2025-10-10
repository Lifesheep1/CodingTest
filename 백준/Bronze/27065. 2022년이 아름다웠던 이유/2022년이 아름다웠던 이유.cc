#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <stack>
#include <set>
#include <string>
#define INF 2147483647

using namespace std;

typedef pair<int, int> pi;
typedef long long int ll;

int over[5001];
int ans[5001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	for (int i = 2; i <= 5000; i++) {
		ans[i] = 1;
		int sum = 0; //i를 제외한 i의 모든 약수의 합
		for (int j = i - 1; j >= 1; j--) {
			if (i % j == 0) { //j는 i의 약수
				if (over[j]) //i의 약수 중에 과잉수가 있으면 ans[i] = 0;
 					ans[i] = 0;
				sum += j;
			}
		}
		if (i >= sum) { //i가 과잉수가 아니면 ans[i] = 0;
			ans[i] = 0;
		}
		else { //i가 과잉수면 over[i] = 1;
 			over[i] = 1;
		}
	}
	int t; cin >> t;
	while (t--) {
		int n; cin >> n;
		if (ans[n]) cout << "Good Bye\n";
		else cout << "BOJ 2022\n";
	}

	return 0;
}