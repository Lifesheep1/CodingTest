#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string s,temp;

int main() {
	getline(cin, s); // 공백 있는 한줄 입력 받을때

	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 65 && s[i] <= 90) { // 대문자일때
			if (s[i] + 13 > 90) {
				s[i] = s[i] - 13;
			}
			else {
				s[i] = s[i] + 13;
			}
		}
		else if (s[i] >= 97 && s[i] <= 122) {
			if (s[i] + 13 > 122) {
				s[i] = s[i] - 13;
			}
			else {
				 s[i] = s[i] + 13;
			}
		}

		cout << s[i];
	}

}