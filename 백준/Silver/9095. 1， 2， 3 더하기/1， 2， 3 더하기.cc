/*
1.테이블 정의하기
D[i] = i를 1,2,3 의 합으로 나타내는 방법의 수
2.점화식 찾기
D[4] = D[1] + D[2] + D[3]
3.초기값 정하기
D[1] =1, D[2] =2 // 1+ 1,2
D[3] =4,
D[i] = D[i-1] + D[i-2] + D[i-3]이니 초기값이 최소3개는 주어져야 함

*/
#include <iostream>
#include <algorithm>
using namespace std;

int T;
int N;
int dp[11];

int main() {
	cin >> T;
	for (int tc = 0; tc < T; tc++)
	{
		cin >> N;
		dp[1] = 1; dp[2] = 2; dp[3] = 4;

		for (int i = 4; i < 11; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[N]<<"\n";
	}


}