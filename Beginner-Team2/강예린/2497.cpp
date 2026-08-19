#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, k;
	cin >> n >> k;

	vector<int> temp(n); //n일동안 매일 측정한 온도
	for (int i = 0; i < n; i++) {
		cin >> temp[i];
	}

	int sum = 0;
	for (int i = 0; i < k; i++) { 
		sum += temp[i];
	}

	int max = sum;
	for (int i = k; i < n; i++) {//슬라이딩 윈도우 알고리즘
		sum = sum + temp[i] - temp[i - k];
		if (max < sum) max = sum;
	}

	cout << max;
	return 0;
}