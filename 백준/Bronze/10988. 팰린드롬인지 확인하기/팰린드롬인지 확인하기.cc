#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <sstream>
#include <cmath>
#include <unordered_map>
#include <stack>
#include <set>
#define INF 2147483647

using namespace std;

string s,tmp;


int main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	cin >> s;
	tmp = s;
	reverse(s.begin(), s.end());
	if (tmp == s) cout<< 1;
	else cout<< 0;
	
	return 0;
}