#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;


int N, M;
int map[501][501];
int vis[501];


int bfs(int start, bool scan) {
	memset(vis, 0, sizeof(vis));
	queue<int> q;
	vis[start] = 1; // 자기 자신 방문했다고 설정
	q.push(start);

	int cnt = 0;

	while (!q.empty()) {
		int u = q.front(); q.pop();

		if (!scan) {
			//정방향  a->b
			for (int v = 1; v <= N; v++) {
				if (map[u][v] && !vis[v]) {
					//간선이 있고 아직 방문 안한 정점v라면 큐에 넣고 방문처리
					vis[v] = 1;
					q.push(v);
					cnt++;
				}
			}
		}
		else {
			//역방향 b->a
			for (int v = 1; v <=N; v++)
			{
				if (map[v][u] && !vis[v])
				{
					vis[v] = 1;
					q.push(v);
					cnt++;
				}
			}
		}
	}
	return cnt++;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	
	cin >> N >> M;
	memset(map, 0, sizeof(map));
	
	for (int i = 0; i < M; i++)
	{
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;

	}

	int ans = 0; 
	for (int i = 1; i <=N; i++)
	{
		int tall = bfs(i, false); // i보다 큰 사람 수
		int short_ = bfs(i, true); //i보다 작은 사람 수
		if (tall + short_ == N - 1) ans++;	//둘이 합쳤을때 n-1개 나오면 그게 ans++
	}

	cout << ans << "\n";

	return 0;
}