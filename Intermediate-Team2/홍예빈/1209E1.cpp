// Day3 - 코드포스 1209E1번 : Rotate Columns
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;

    while (T--) {
        int n, m;
        cin >> n >> m;

        vector<vector<int>> a(n, vector<int>(m));

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                cin >> a[i][j];
            }
        }

        int FULL = 1 << n;
        const int NEG_INF = -1'000'000'000;

        vector<int> dp(FULL, NEG_INF);
        dp[0] = 0;

        for (int col = 0; col < m; ++col) {
            vector<int> nextDp = dp;

            /*
                한 열의 회전 상태는 n개만 존재한다.
                n칸 아래로 회전하면 원래 상태로 돌아온다.
            */
            for (int shift = 0; shift < n; ++shift) {
                vector<int> value(n);

                for (int row = 0; row < n; ++row) {
                    int originalRow = (row - shift + n) % n;
                    value[row] = a[originalRow][col];
                }

                /*
                    subsetSum[mask]:
                    현재 회전 상태에서 mask에 포함된 행들의 값의 합
                */
                vector<int> subsetSum(FULL, 0);

                for (int mask = 1; mask < FULL; ++mask) {
                    int bit = __builtin_ctz(mask);
                    int prev = mask ^ (1 << bit);

                    subsetSum[mask] =
                        subsetSum[prev] + value[bit];
                }

                for (int mask = 0; mask < FULL; ++mask) {
                    if (dp[mask] == NEG_INF) {
                        continue;
                    }

                    /*
                        모든 행이 이미 선택된 상태에서는
                        추가로 선택할 수 없으므로 건너뛴다.
                    */
                    if (mask == FULL - 1) {
                        continue;
                    }

                    int remain = (FULL - 1) ^ mask;

                    /*
                        remain의 모든 부분집합 sub를 확인한다.
                        sub는 현재 열이 담당할 행들의 집합이다.
                    */
                    for (int sub = remain;; sub = (sub - 1) & remain) {
                        int nextMask = mask | sub;

                        nextDp[nextMask] = max(
                            nextDp[nextMask],
                            dp[mask] + subsetSum[sub]
                        );

                        if (sub == 0) {
                            break;
                        }
                    }
                }
            }

            dp.swap(nextDp);
        }

        cout << dp[FULL - 1] << '\n';
    }

    return 0;
}
