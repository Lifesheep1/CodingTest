#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n, m, k;
int y, x;
int arr[51][51];
int vis[51][51];
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

			vis[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}


}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int T;
	cin >> T;
	
	for (int i = 0; i < T; i++)
	{
		cin >> n >> m >> k;
		memset(arr, 0, sizeof(arr));
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		for (int j = 0; j < k; j++)
		{
			cin >> y >> x;
			arr[y][x] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (arr[i][j] == 1 && vis[i][j] == 0) {
					bfs(i, j);
					cnt++;
				}
			}
		}
		cout << cnt<<"\n";
	}

	
	


	return 0;
}