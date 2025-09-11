#include <iostream>
#include <vector>
#include <tuple>
#include <cstring>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int n = 5;
int cnt;
char field[n][n];

vector<pair<int, int>> can;

int visited[26];
int selected[26];
vector<int> graph[26];

const int dy[] = { 0,0,1,-1 };
const int dx[] = { 1,-1,0,0 };

//pair<int, int> dfs(int here) {
//
//    pair<int, int> ret;
//    ret.first = 1; // can 수
//
//    int y, x;
//    tie(y, x) = can[here];
//
//    // S can 수
//    if (field[y][x] == 'S') ret.second = 1;
//    else ret.second = 0;
//
//    visited[here] = 1;
//
//    for (int there : graph[here]) {
//        if (!selected[there]) continue;
//
//        if (visited[there]) continue;
//
//        pair<int, int> tmp = dfs(there);
//        ret.first += tmp.first;
//        ret.second += tmp.second;
//    }
//
//    return ret;
//}

int dfs_count(int here) {
    visited[here] = 1;
    int ret = 1;

    for (int there : graph[here]) {
        if (!selected[there]) continue;
        if (visited[there]) continue;

        ret += dfs_count(there);
    }
    return ret;
}

//목적
    // 선택한 v인덱스 중에서 s탐색할려고 
    // s탐색 왜하냐 -> 개수 새서 4이상이면 dfs돌릴려고
    // dfs돌려서 방문한 칸수 찾고 그게 7칸이면 리턴
    // 연속으로 7칸 붙어있다는 뜻.

bool isConnected(vector<int>& v) {

    // graph 탐색 -> int dfs == 7 true;
    memset(visited, 0, sizeof(visited));

    //** pair<int,int> 형이 어려울 경우*******
        // 1. S갯수 파악
        // 2. S 4이상이면 탐색 수행
        // 3. 탐색은 방문한 칸 수만 return -> 7이면 조건 모두 만족

    // pair<int, int> count = dfs(v[0]);
    int sCount = 0;
    

    for (int idx : v) {
        int y = can[idx].first;
        int x = can[idx].second;
        if (field[y][x] == 'S') sCount++;
    }
    if (sCount < 4) return false;

    int connected = dfs_count(v[0]);

    // 연결된 컴포넌트 && S >= 4
    // if (count.first == 7 && count.second >= 4) return true;
    return (connected == 7);
}


bool check(vector<int>& v) {

    // 연결된 컴포넌트 && S >= 4
    if (isConnected(v)) return true;
    else return false;

}

void combi(int idx, vector<int>& v) {

    if (v.size() == 7) {
        if (check(v)) cnt++;

        return;
    }

    for (int i = idx + 1; i < can.size(); i++) {

        selected[i] = 1;
        v.push_back(i);

        combi(i, v);

        selected[i] = 0;
        v.pop_back();
    }
}

int main() {

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> field[i][j];
            can.push_back({ i, j }); // 25개
        }
    }

    // 연결성 검사를 위한 graph 생성 (index 기반)
    // 인접칸 그래프
    for (int y = 0; y < n; y++) {
        for (int x = 0; x < n; x++) {
            int idx = n * y + x;

            int ny, nx;
            for (int d = 0; d < 4; d++) {
                ny = y + dy[d];
                nx = x + dx[d];

                if (ny >= n || ny < 0 || nx >= n || nx < 0) continue;
                int nidx = n * ny + nx;
                graph[idx].push_back(nidx);
            }
        }
    }

    vector<int> v;
    combi(-1, v);

    cout << cnt;

    return 0;
}