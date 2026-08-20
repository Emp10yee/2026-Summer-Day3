#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int& x : a) cin >> x;
    for (int& x : b) cin >> x;

    for (int mask = 0; mask < (1 << 9); mask++) {
        bool ok = true;

        for (int i = 0; i < n; i++) {
            bool found = false;

            for (int j = 0; j < m; j++) {
                int x = a[i] & b[j];

                if ((x | mask) == mask) {
                    found = true;
                    break;
                }
            }

            if (!found) {
                ok = false;
                break;
            }
        }

        if (ok) {
            cout << mask << '\n';
            return 0;
        }
    }

    return 0;
}