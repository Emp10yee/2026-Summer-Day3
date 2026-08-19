#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int INF = 1e9;

struct Point {
    int x, y;
};

int dist2(Point a, Point b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    return dx * dx + dy * dy;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Point home;
    cin >> home.x >> home.y;

    int N;
    cin >> N;

    vector<Point> p(N);

    for (int i = 0; i < N; i++) {
        cin >> p[i].x >> p[i].y;
    }

    int FULL = (1 << N) - 1;

    vector<int> dp(1 << N, INF);

    vector<int> prevMask(1 << N, -1);
    vector<pair<int, int>> picked(1 << N);

    dp[0] = 0;

    for (int mask = 0; mask <= FULL; mask++) {

        if (dp[mask] == INF)
            continue;

        int i = -1;

        for (int k = 0; k < N; k++) {
            if (!(mask & (1 << k))) {
                i = k;
                break;
            }
        }

        if (i == -1)
            continue;

        int nextMask = mask | (1 << i);

        int cost = 2 * dist2(home, p[i]);

        if (dp[nextMask] > dp[mask] + cost) {
            dp[nextMask] = dp[mask] + cost;

            prevMask[nextMask] = mask;
            picked[nextMask] = {i, -1};
        }

        for (int j = i + 1; j < N; j++) {

            if (mask & (1 << j))
                continue;

            nextMask = mask | (1 << i) | (1 << j);

            cost =
                dist2(home, p[i])
                + dist2(p[i], p[j])
                + dist2(p[j], home);

            if (dp[nextMask] > dp[mask] + cost) {
                dp[nextMask] = dp[mask] + cost;

                prevMask[nextMask] = mask;
                picked[nextMask] = {i, j};
            }
        }
    }

    cout << dp[FULL] << '\n';

    vector<pair<int, int>> route;

    int mask = FULL;

    while (mask != 0) {
        route.push_back(picked[mask]);
        mask = prevMask[mask];
    }

    reverse(route.begin(), route.end());

    cout << 0 << ' ';

    for (auto [a, b] : route) {
        cout << a + 1 << ' ';

        if (b != -1)
            cout << b + 1 << ' ';

        cout << 0 << ' ';
    }

    cout << '\n';

    return 0;
}