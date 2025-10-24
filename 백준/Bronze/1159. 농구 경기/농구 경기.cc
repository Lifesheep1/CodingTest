#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int n;
string s;
int cnt[26];
string ret;

int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> s;
		cnt[s[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		if (cnt[i] >= 5) {
			ret += i + 'a';
		}
	}
	if (ret.size()) {
		cout << ret << "\n";
	}
	else {
		cout << "PREDAJA" << "\n";
	}
}