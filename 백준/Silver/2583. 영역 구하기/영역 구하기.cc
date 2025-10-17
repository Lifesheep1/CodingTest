#include <iostream>
#include <string>
#include <queue>
#include <cstring>
#include <algorithm>
using namespace std;

int m,n,k;
int arr[101][101];

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

struct Node {
	int y;
	int x;
};

int bfs(int y, int x) {
	queue<Node> q;
	arr[y][x] = 1; // 시작하는 칸 방문처리하고 큐에 넣기
	q.push({ y,x });
	int cnt = 1; // 넣었으니 시작사이즈 당연히 1

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			//예외 처리
			if (ny >= m || ny < 0 || nx >= n || nx < 0) continue;
			if (arr[ny][nx] != 0) continue;

			arr[ny][nx] = 1;
			q.push({ ny,nx });
			cnt++;
		}
	}
	return cnt;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int x1, y1, x2, y2, cnt = 0;
	int area[100];
	
	cin >> m >> n >> k;
	
	for (int i = 0; i < k; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		for (int y = y1; y < y2; y++)
		{
			for (int x = x1; x < x2; x++)
			{
				arr[y][x] = 1; // 직사각형 포함되는 칸 1로
			}
		}
	}

	vector<int> areas;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 0) { // 빈칸이면 
				int a = bfs(i, j); // bfs탐색후 나온 영역의 사이즈를 areas에 저장
				areas.push_back(a);
			}
		}
	}

	sort(areas.begin(), areas.end()); // 정렬
	cout << areas.size() << "\n";
	for (int i : areas) {
		cout << i << " "; // 정렬된 areas에 저장된 영역크기 출력
	}
	cout << "\n";
	return 0;
}