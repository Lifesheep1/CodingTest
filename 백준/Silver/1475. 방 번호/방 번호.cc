#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;



int main() {


	int cnt = 1;
	int count[10] = { 0 }; // 각 숫자의 등장 횟수 세기
	string s; // 방번호
	cin >> s;
	int max_ret = -1;

	for (char i : s) {
		{
			count[i - '0']++;
		}
	}

	//count인덱스중에서 max value 값을 답으로 리턴해줄려고 dat설정을 햇슴

	//6 ,9 
	//6과 9가 합쳐서 2개 이하 쓰였을경우
	//6과 9가 합쳐서 3개~4개 -> 세트 2개
	// 5~6 -> 세트3개
	//n<7자리 

	int sum = count[6] + count[9]; // 6과 9가 합친 개수

	if (sum <= 2) {
		count[6] = 1;
		count[9] = 1;
	}
	else if (sum >= 3 && sum <= 4) {
		count[6] = 2;
		count[9] = 2;
	}
	else if (sum >= 5 && sum <= 6) {
		count[6] = 3;
		count[9] = 3;
	}

	for (int i = 0; i < 10; i++)
	{
		if (count[i] >= max_ret) max_ret = count[i];
	}

	cout << max_ret;

	return 0;
}