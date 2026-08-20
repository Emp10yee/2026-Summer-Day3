#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    
    vector<vector<int>> cost(n, vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> cost[i][j];

    vector<int> dp(1 << n, INF);
    vector<int> prev_state(1 << n, -1);
    vector<int> choice(1 << n, -1);

    dp[0] = 0;
    for (int mask = 0; mask < (1 << n); ++mask) {
        if (dp[mask] == INF) continue;
        
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (mask & (1 << i)) cnt++;
        }
        if (cnt == n) continue;

        for (int j = 0; j < n; ++j) {
            if (!(mask & (1 << j))) {
                int nxt = mask | (1 << j);
                if (dp[nxt] > dp[mask] + cost[cnt][j]) {
                    dp[nxt] = dp[mask] + cost[cnt][j];
                    prev_state[nxt] = mask;
                    choice[nxt] = j;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1] << "\n";
    vector<int> ans(n);
    int curr = (1 << n) - 1;
    while (curr > 0) {
        int c = 0;
        for (int i = 0; i < n; ++i) {
            if (curr & (1 << i)) c++;
        }
        ans[c - 1] = choice[curr] + 1;
        curr = prev_state[curr];
    }
    
    for (int i = 0; i < n; ++i) {
        cout << ans[i] << (i == n - 1 ? "" : " ");
    }
    cout << "\n";
    
    return 0;
}
