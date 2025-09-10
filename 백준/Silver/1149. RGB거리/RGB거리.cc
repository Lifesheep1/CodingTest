/*
1.테이블 정의하기
D[i][0] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 빨강
D[i][1] = i번째 집까지 칠할 때 비용의 최솟값, 단i번째 집은 초록
D[i][2] = i번째 집까지 칠할 때 비용의 최솟값, 단 i번째 집은 파랑
2.점화식 찾기
D[k][0] = min(D[k-1][1], D[k-1][2]) + R[k]
// k-1번째 집은 초록 혹은 파랑이여야 하고 둘중에 최소 + 현재 k번째 집을 빨강으로 칠하는 비용


3.초기값 설정
D[1][0] = R[1]
D[1][1] = G[1]
D[1][2] = B[1]

*/

#include <iostream>
#include <algorithm>
using namespace std;

int r[1001],  g[1001],  b[1001];
int dp[1001][3];

int main() {

	int N;
	cin >> N;
	

	for (int i = 1; i <= N; i++)
	{
		cin >> r[i] >> g[i] >> b[i];
	}

	dp[1][0] = r[1];
	dp[1][1] = g[1];
	dp[1][2] = b[1];

	for (int i = 2; i <= N; i++)
	{
		dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + r[i];
		dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + g[i];
		dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + b[i];
	}

	cout << min({ dp[N][0], dp[N][1],dp[N][2] });

}