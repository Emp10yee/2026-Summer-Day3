#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> a[i][j];
            }
        }

        vector<pair<int, int>> cols;

        for (int j = 0; j < m; j++) {
            int mx = 0;
            for (int i = 0; i < n; i++) {
                mx = max(mx, a[i][j]);
            }
            cols.push_back({ mx, j });
        }

        sort(cols.rbegin(), cols.rend());

        int k = min(n, m);
        vector<vector<int>> b(n, vector<int>(k));

        for (int j = 0; j < k; j++) {
            int col = cols[j].second;
            for (int i = 0; i < n; i++) {
                b[i][j] = a[i][col];
            }
        }

        int full = 1 << n;
        vector<int> dp(full, -1);
        dp[0] = 0;

        for (int col = 0; col < k; col++) {
            vector<int> best(full, 0);

            for (int shift = 0; shift < n; shift++) {
                for (int mask = 0; mask < full; mask++) {
                    int sum = 0;

                    for (int row = 0; row < n; row++) {
                        if (mask & (1 << row)) {
                            sum += b[(row + shift) % n][col];
                        }
                    }

                    best[mask] = max(best[mask], sum);
                }
            }

            vector<int> ndp = dp;

            for (int mask = 0; mask < full; mask++) {
                if (dp[mask] == -1) continue;

                int remain = (full - 1) ^ mask;

                for (int sub = remain; ; sub = (sub - 1) & remain) {
                    ndp[mask | sub] = max(
                        ndp[mask | sub],
                        dp[mask] + best[sub]
                    );

                    if (sub == 0) break;
                }
            }

            dp = ndp;
        }

        cout << dp[full - 1] << '\n';
    }

    return 0;
}