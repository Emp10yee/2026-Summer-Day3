#include <iostream>
#include <set>
using namespace std;

int main() {
	int n;
	set<int> lst;
	cin >> n;
	for (int i = 1; i*i <= n; i++) {
		if (n % i == 0) {
			lst.insert(i);
			lst.insert(n / i);
		}
	}
	for (int i : lst) {
		cout << i << " ";
	}
	return 0;
}