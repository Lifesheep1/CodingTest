#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

int n;
int arr[101][101];
int vis[101][101];
int maxH = 0; // 입력된 비의 양의 최대
int maxCnt = 0; //안전한 영역의 최대개수
int cnt = 0; //안전한 영역세는변수

int dy[] = { -1,1,0,0 };
int dx[] = { 0,0,-1,1 };

void dfs(int y, int x) {
	vis[y][x] = 1; // 방문처리

	for (int i = 0; i < 4; i++)
	{
		int ny = dy[i] + y;
		int nx = dx[i] + x;

		//예외처리
		if (ny >= n || ny < 0 || nx >= n || nx < 0) continue; 
		if (vis[ny][nx] != 0) continue;
		dfs(ny, nx);
	}

}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> arr[i][j];
			if (maxH < arr[i][j]) maxH = arr[i][j]; //최대비의양 갱신
		}
	}

	for (int i = 0; i <= maxH; i++) // 안전한 영역 구하기
	{
		cnt = 0; // 초기화
		for (int j = 0; j < n; j++) // 잠긴영역은 방문처리
		{
			for (int k = 0; k < n; k++)
			{
				if (arr[j][k] <= i) { // 비보다 밑에 있으면 방문처리
					vis[j][k] = 1;
				}
				else vis[j][k] = 0;
			}
		}

		for (int j = 0; j < n; j++) // 완전탐색
		{
			for (int k = 0; k < n; k++)
			{
				if (vis[j][k] == 0) // 잠기지 않았으면(방문하지 않았으면)
				{
					dfs(j, k);
					cnt++;
				}
			}
		}
		if (maxCnt < cnt) maxCnt = cnt;

	}
	cout << maxCnt;
	
	return 0;
}