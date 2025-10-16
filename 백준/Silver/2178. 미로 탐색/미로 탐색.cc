#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n, m;
int arr[101][101];
int vis[101][101];
int cnt;


struct Node {
	int y;
	int x;
};

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

//시작점(1,1) -> (n,m)까지의 거리 -> flood fill
void bfs(int y, int x) {
	queue<Node>q;
	memset(vis, 0, sizeof(vis));

	vis[y][x] = 1; // 거리: 시작을 1로
	q.push({ y,x });

	while (!q.empty()) {
		Node now = q.front(); q.pop();
		for (int i = 0; i < 4; i++)
		{
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny >= n || ny < 0 || nx >= m || nx < 0) continue;
			if (vis[ny][nx] != 0) continue; // 이미 방문
			if (arr[ny][nx] == 0) continue; // 이동 불가

			vis[ny][nx] = vis[now.y][now.x] + 1;
			q.push({ ny,nx });
		}
	}


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < m; j++)
		{
			arr[i][j] = s[j] - '0';
		}
	}
	bfs(0, 0);

	cout << vis[n - 1][m - 1] << "\n";

	return 0;
}