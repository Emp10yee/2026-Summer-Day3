#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int start = 0;
	int end = n - 1;

	int answer1 = v[start];
	int answer2 = v[end];
	int minSum = abs(v[start] + v[end]);
	
	while (start < end) {
		int sum = v[start] + v[end];

		if (abs(sum) < minSum) {
			answer1 = v[start];
			answer2 = v[end];
			minSum = abs(sum);
		}


		if (sum == 0) {
			break;
		}
		else if (sum < 0) {
			start++;
		}
		else {
			end--;
		}
	}

	cout << answer1 << " " << answer2;

	return 0;

}