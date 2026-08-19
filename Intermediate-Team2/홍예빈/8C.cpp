// Day3 - 코드포스 8C번 : Looking for Order
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int sx, sy;
    cin >> sx >> sy;

    int n;
    cin >> n;

    vector<int> x(n), y(n);

    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    auto distFromBag = [&](int i) -> int {
        int dx = x[i] - sx;
        int dy = y[i] - sy;
        return dx * dx + dy * dy;
    };

    auto distBetween = [&](int i, int j) -> int {
        int dx = x[i] - x[j];
        int dy = y[i] - y[j];
        return dx * dx + dy * dy;
    };

    const int totalMask = 1 << n;
    const int fullMask = totalMask - 1;
    const int INF = 1'000'000'000;

    /*
        dp[mask]:

        mask에 포함된 물건들을 처리했을 때의 최소 비용
    */
    vector<int> dp(totalMask, INF);
    dp[0] = 0;

    for (int mask = 0; mask < totalMask; ++mask) {
        if (dp[mask] == INF) {
            continue;
        }

        if (mask == fullMask) {
            continue;
        }

        /*
            처리하지 않은 물건 중 번호가 가장 작은 물건을 선택한다.

            어떤 최적해에서도 이 물건은 반드시
            혼자 처리되거나 다른 하나의 물건과 함께 처리된다.
        */
        int remain = fullMask ^ mask;
        int first = __builtin_ctz(remain);

        // first 하나만 처리
        {
            int nextMask = mask | (1 << first);

            int cost = 2 * distFromBag(first);

            dp[nextMask] = min(
                dp[nextMask],
                dp[mask] + cost
            );
        }

        // first와 second를 함께 처리
        for (int second = first + 1; second < n; ++second) {
            if (mask & (1 << second)) {
                continue;
            }

            int nextMask =
                mask | (1 << first) | (1 << second);

            int cost =
                distFromBag(first)
                + distBetween(first, second)
                + distFromBag(second);

            dp[nextMask] = min(
                dp[nextMask],
                dp[mask] + cost
            );
        }
    }

    cout << dp[fullMask] << '\n';

    /*
        경로 복원

        현재 mask에서 마지막으로 처리된 물건을 찾아
        이전 mask로 되돌아간다.
    */
    vector<vector<int>> groups;

    int mask = fullMask;

    while (mask != 0) {
        int remain = fullMask ^ mask;

        /*
            현재 mask에서 제거된 마지막 그룹을 찾기 위해
            현재 mask에 포함된 물건 중 하나를 first로 선택한다.

            실제 마지막 그룹은 first 혼자이거나
            first와 second이다.
        */
        bool found = false;

        for (int first = 0; first < n && !found; ++first) {
            if (!(mask & (1 << first))) {
                continue;
            }

            // first 혼자 마지막에 처리된 경우
            {
                int previousMask = mask ^ (1 << first);
                int cost = 2 * distFromBag(first);

                if (dp[mask] ==
                    dp[previousMask] + cost) {
                    groups.push_back({first + 1});
                    mask = previousMask;
                    found = true;
                    break;
                }
            }

            // first와 second가 마지막에 함께 처리된 경우
            for (int second = first + 1;
                 second < n && !found;
                 ++second) {
                if (!(mask & (1 << second))) {
                    continue;
                }

                int previousMask =
                    mask ^ (1 << first) ^ (1 << second);

                int cost =
                    distFromBag(first)
                    + distBetween(first, second)
                    + distFromBag(second);

                if (dp[mask] ==
                    dp[previousMask] + cost) {
                    groups.push_back({
                        first + 1,
                        second + 1
                    });

                    mask = previousMask;
                    found = true;
                    break;
                }
            }
        }
    }

    reverse(groups.begin(), groups.end());

    cout << 0 << ' ';

    for (const auto& group : groups) {
        for (int object : group) {
            cout << object << ' ';
        }

        cout << 0 << ' ';
    }

    cout << '\n';

    return 0;
}
