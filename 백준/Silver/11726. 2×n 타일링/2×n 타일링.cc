#include <bits/stdc++.h>
using namespace std;

const int MOD = 10007;
int n;
vector<int> memo;

int solve(int x) {
    if (x == 1) return 1;
    if (x == 2) return 2;
    int& ret = memo[x];
    if (ret != -1) return ret;
    ret = (solve(x - 1) + solve(x - 2)) % MOD;
    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    if (!(cin >> n)) return 0;
    memo.assign(max(3, n + 1), -1); // n이 1이나 2여도 안전하게 확보
    cout << solve(n) % MOD << "\n";
    return 0;
}
