/*
1.테이블 정의하기
계단의 점수를 저장해놓은 배열 stair[]
경우의 수에 따라 계단의 점수를 더한 것 중 최댓값을 저장하는 배열 score[]

2.점화식 찾기
score[1] = stair[1]
score[2] = stair[1] + stair[2]
score[3] = stair[1] + stair[3] or stair[2] + stair[3] 둘중 최댓값
score[4] 
 ` 1-2-4 : score[2] + stair[4] ( score[2] = score[1] + stair[2])
 ` 1-3-4 : score[1] + stair[3] + stair[4]

score[5]
 ` 1-3-5,2-3-5 : score[3] + stair[5] (score[3] 에서의 최댓값 + stair[5])
 ` 1-2-4-5 : score[2] + stair[4] + stair[5]

 score[N] = score[N-2] + stair[N]
 score[N] = score[N-3] + stair[N-1] + stair[N]
 둘중에 최대값이 답
3.초기값 설정

*/
#include <iostream>
#include <algorithm>
using namespace std;

int score[301];
int stair[301];

int main() {
	int n;
	cin >> n; // 계단 갯수

	for (int i = 1; i <=n; i++)
	{
		cin >> stair[i]; // 계단 점수 저장
	}
	//초기값 설정
	score[1] = stair[1];
	score[2] = stair[1] + stair[2];
	score[3] = max(stair[1] + stair[3], stair[2] + stair[3]);
	for (int i = 4; i <=n; i++)
	{
		int a = score[i - 2] + stair[i];
		int b = score[i - 3] + stair[i - 1] + stair[i];
		score[i] = max(a, b);
	}
	cout << score[n];
}

