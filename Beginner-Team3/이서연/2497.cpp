#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	int arr[100001];

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	int sum = 0;
	for (int i = 0; i < K; i++) sum += arr[i];
	int best = sum;

	for (int i = K; i < N; i++) {
			sum += arr[i] - arr[i - K];
			best = max(best, sum);
	}

	cout << best;

	return 0;
}