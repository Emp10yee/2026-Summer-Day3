#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;
	cin >> n;

	vector<int> a(n);
	vector<int> prefix(n + 1, 0);

	for (int i = 1; i <= n; i++) {
		cin >> a[i - 1];
		prefix[i] = prefix[i - 1] + a[i - 1];
	}

	int q, s, e;
	cin >> q;

	for (int i = 0; i < q; i++) {
		cin >> s >> e;
		cout << prefix[e] - prefix[s - 1] << "\n";
	}

	return 0;
}