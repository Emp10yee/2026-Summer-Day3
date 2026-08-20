#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    if (!(cin >> n >> m)) return 0;

    int W = min(n, m);
    int H = max(n, m);

    // 슬라이딩 윈도우 방식으로 2개의 배열만 사용
    vector<vector<long long>> dp(2, vector<long long>(1 << W, 0));
    dp[0][0] = 1;

    for (int i = 0; i < W * H; ++i) {
        int cur = i % 2;
        int nxt = (i + 1) % 2;
        
        fill(dp[nxt].begin(), dp[nxt].end(), 0);
        
        for (int mask = 0; mask < (1 << W); ++mask) {
            if (dp[cur][mask] == 0) continue;
            
            // 현재 칸이 이미 윗줄의 세로 타일에 의해 채워진 경우
            if (mask & 1) {
                dp[nxt][mask >> 1] += dp[cur][mask];
            } else {
                // 가로 타일 배치 (가장 오른쪽 칸이 아니고, 다음 칸이 비어있을 때)
                if ((i % W) != (W - 1) && !(mask & 2)) {
                    dp[nxt][(mask >> 1) | 1] += dp[cur][mask];
                }
                // 세로 타일 배치 (가장 아랫줄이 아닐 때)
                if (i / W < H - 1) {
                    dp[nxt][(mask >> 1) | (1 << (W - 1))] += dp[cur][mask];
                }
            }
        }
    }

    cout << dp[(W * H) % 2][0] << "\n";
    return 0;
}
