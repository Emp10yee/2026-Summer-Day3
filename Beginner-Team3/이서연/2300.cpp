#include <iostream>
#include <vector>
using namespace std;

int main() {
	int N;
	cin >> N;

	vector<long long> a(N);

	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	
	int l = 0, r = (int)a.size() - 1;

	long long sum = a[l]+a[r];
	long long minValue;

	if (sum < 0)
		minValue = -sum;
	else
		minValue = sum;

	long long ans1 = a[l];
	long long ans2 = a[r];
	
	while (l < r) {
		sum = a[l] + a[r];

		long long current;

		if (sum < 0)
			current = -sum;
		else 
			current = sum;

		if (current < minValue) {
			minValue = current;
			ans1 = a[l];
			ans2 = a[r];
		}

		if (sum < 0) {
			l++;
		}
		else if (sum > 0) {
			r--;
		}
		else {
			break;
		}
	}

	cout << ans1 << ' ' << ans2;

	return 0;
}