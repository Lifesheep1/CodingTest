/*
D[i] = 2 x i 의 타일을 채우는 방법의 수

*/
#include <iostream>
using namespace std;

int n;
int dp[1004];

int main() {

	cin >> n;

	// dp[n] = dp[n - 1] + dp[n - 2];
	dp[1] = 1;
	dp[2] = 2;
	
	for (int can = 3; can <= n; can++) {
		dp[can] = dp[can - 1] + dp[can - 2];
		dp[can] %= 10007;
	}

	cout << dp[n];

	return 0;
}


// 2^20 마지노선임 << 재귀 