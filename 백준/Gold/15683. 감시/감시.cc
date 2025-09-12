#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


int N, M;
int map[10][10] , area[10][10];
int min_ret = 1e9;

const int dy[] = { -1,0,1,0 };// 상 우 하 좌
const int dx[] = { 0,1,0,-1 };

struct A {
	int y;
	int x;
	int type;
};

vector<A> cctvs;

int getRet() {
	
	int ret = 0;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			if (!area[i][j] && !map[i][j]) ret++;
		}
	}
	return ret;
}

void seeGo(int y, int x, int d, int type) { // d: 방향 type: 거길갔는지 체크

	int dist = 1; // 거리

	while (true) {
		int ny = y + dist * dy[d];
		int nx = x + dist * dx[d];

		//오버 플로우
		if (ny >= N || ny < 0 || nx >= M || nx < 0) break;
		if (map[ny][nx] == 6) break;

		if (type == 1) area[ny][nx]++;

		else {
			area[ny][nx]--;
			if (area[ny][nx] < 0) area[ny][nx] = 0;
		}

		dist++;
	}

}

void see(int y, int x, int num, int d, int type) {
	if (num == 1) {
		seeGo(y, x, d, type);
	}
	else if (num == 2) {
		seeGo(y, x, d, type);
		seeGo(y, x, (d + 2) % 4, type);
	}
	else if (num == 3) {
		seeGo(y, x, d, type);
		seeGo(y, x, (d + 1) % 4, type);
	}
	else if (num == 4) {
		seeGo(y, x, d, type);
		seeGo(y, x, (d + 1) % 4, type);
		seeGo(y, x, (d + 2) % 4, type);
	}
	else if (num == 5) {
		seeGo(y, x, d, type);
		seeGo(y, x, (d + 1) % 4, type);
		seeGo(y, x, (d + 2) % 4, type);
		seeGo(y, x, (d + 3) % 4, type);
	}
}


void go(int idx, int d) {

	if (idx + 1 == cctvs.size()) {
		//사각 지대 업데이트
		min_ret = min(min_ret, getRet());
		return;
	}

	A cctv = cctvs[idx + 1];

	for (int i = 0; i < 4; i++)
	{
		see(cctv.y, cctv.x, cctv.type, i, 1);
		go(idx + 1, i);
		see(cctv.y, cctv.x, cctv.type, i, 0); // unsee
	}
}

int main() {

	cin >> N >> M;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> map[i][j];
			if (map[i][j] >= 1 && map[i][j] <= 5) cctvs.push_back({ i,j,map[i][j] });
		}
	}

	go(-1, 0);

	cout << min_ret;

	return 0;


}