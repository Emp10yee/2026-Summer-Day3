#include <bits/stdc++.h>
using namespace std;

const long long INF = (1LL << 60);

int n;
int xs, ys;
int x[25], y_[25];

vector<long long> dp;
vector<pair<int, int>> choice;

long long dist2(int x1, int y1, int x2, int y2) {
    long long dx = x1 - x2;
    long long dy = y1 - y2;
    return dx * dx + dy * dy;
}

long long solve(int mask) {
    if (mask == 0) return 0;

    long long& ret = dp[mask];
    if (ret != -1) return ret;

    ret = INF;

    int i = __builtin_ctz(mask);

    int nextMask = mask ^ (1 << i);

    long long cost =
        2 * dist2(xs, ys, x[i], y_[i]) +
        solve(nextMask);

    if (cost < ret) {
        ret = cost;
        choice[mask] = { i, -1 };
    }

    for (int j = i + 1; j < n; j++) {
        if (!(mask & (1 << j))) continue;

        int next = mask ^ (1 << i) ^ (1 << j);

        cost =
            dist2(xs, ys, x[i], y_[i]) +
            dist2(x[i], y_[i], x[j], y_[j]) +
            dist2(x[j], y_[j], xs, ys) +
            solve(next);

        if (cost < ret) {
            ret = cost;
            choice[mask] = { i, j };
        }
    }

    return ret;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> xs >> ys;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> x[i] >> y_[i];
    }

    int full = (1 << n) - 1;

    dp.assign(1 << n, -1);
    choice.resize(1 << n);

    cout << solve(full) << '\n';

    int mask = full;

    cout << 0 << ' ';

    while (mask) {
        auto [i, j] = choice[mask];

        cout << i + 1 << ' ';

        mask ^= (1 << i);

        if (j != -1) {
            cout << j + 1 << ' ';
            mask ^= (1 << j);
        }

        cout << 0 << ' ';
    }

    cout << '\n';

    return 0;
}