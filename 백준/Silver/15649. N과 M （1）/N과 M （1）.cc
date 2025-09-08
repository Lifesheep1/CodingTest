/*
문제
자연수 N과 M이 주어졌을 때, 아래 조건을 만족하는 길이가 M인 수열을 모두 구하는 프로그램을 작성하시오.

1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
입력
첫째 줄에 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

출력
한 줄에 하나씩 문제의 조건을 만족하는 수열을 출력한다. 중복되는 수열을 여러 번 출력하면 안되며, 각 수열은 공백으로 구분해서 출력해야 한다.

수열은 사전 순으로 증가하는 순서로 출력해야 한다.
*/

#include <iostream>
#include <cstring>
using namespace std;

int N, M;
int used[10]; // index: 어떤 숫자, value: 사용 여부
int path[10]; // index: now번째 , value: 선택한 숫자

void func(int now) {
	//기저조건
	if (now == M) {
		for (int i = 0; i < M; i++)
		{
			cout << path[i] << " ";
		}
		cout << "\n";
		return;
	}
	//for문
	for (int i = 1; i <= N; i++)
	{
		//판별
		if (used[i] == 1) continue;
		used[i] = 1;
		path[now] = i;
		func(now + 1);
		used[i] = 0;
		path[now] = 0;
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	cin >> N >> M;
	func(0);

	return 0;
}