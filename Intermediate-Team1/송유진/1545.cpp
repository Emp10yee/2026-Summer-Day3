#include <iostream>
#include <vector>
#include <algorithm>

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

    vector<vector<int>> dp(1 << n, vector<int>(n, INF));
    dp[1][0] = 0; // 출발지는 1번(인덱스 0)

    for (int mask = 1; mask < (1 << n); ++mask) {
        for (int i = 0; i < n; ++i) {
            if (!(mask & (1 << i)) || dp[mask][i] == INF) continue;
            for (int j = 0; j < n; ++j) {
                // 갈 수 없는 경로(비용 0) 제외
                if (!(mask & (1 << j)) && cost[i][j] > 0) {
                    int nxt = mask | (1 << j);
                    dp[nxt][j] = min(dp[nxt][j], dp[mask][i] + cost[i][j]);
                }
            }
        }
    }

    int ans = INF;
    for (int i = 1; i < n; ++i) {
        if (cost[i][0] > 0 && dp[(1 << n) - 1][i] != INF) {
            ans = min(ans, dp[(1 << n) - 1][i] + cost[i][0]);
        }
    }
    
    if (n == 1) ans = 0; // 1개일 경우 제자리
    cout << (ans == INF ? 0 : ans) << "\n";
    
    return 0;
}
