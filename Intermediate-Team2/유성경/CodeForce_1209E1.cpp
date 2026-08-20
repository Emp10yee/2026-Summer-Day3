// CodeForce 1209E1. Rotate Columns (easy version)
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> a(n, vector<int>(m));

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < m; ++j)
        {
            cin >> a[i][j];
        }
    }

    vector<vector<int>> cols(m, vector<int>(n));
    vector<pair<int, int>> maxC(m);

    for (int j = 0; j < m; ++j)
    {
        int mx = 0;

        for (int i = 0; i < n; ++i)
        {
            cols[j][i] = a[i][j];

            if (a[i][j] > mx)
            {
                mx = a[i][j];
            }
        }

        maxC[j] = { mx, j };
    }

    sort(maxC.rbegin(), maxC.rend());

    int k = min(n, m);
    vector<vector<int>> best_cols(k, vector<int>(n));

    for (int i = 0; i < k; ++i)
    {
        int j = maxC[i].second;

        for (int r = 0; r < n; ++r)
        {
            best_cols[i][r] = cols[j][r];
        }
    }

    int maxM = 1 << n;
    vector<int> dp(maxM, 0);

    for (int i = 0; i < k; ++i)
    {
        vector<int> best(maxM, 0);

        for (int mask = 0; mask < maxM; ++mask)
        {
            for (int s = 0; s < n; ++s)
            {
                int curr = 0;

                for (int bit = 0; bit < n; ++bit)
                {
                    if (mask & (1 << bit))
                    {
                        curr += best_cols[i][(bit + s) % n];
                    }
                }

                if (curr > best[mask])
                {
                    best[mask] = curr;
                }
            }
        }

        vector<int> next = dp;

        for (int mask = 0; mask < maxM; ++mask)
        {
            int submask = mask;

            while (true)
            {
                int val = dp[mask ^ submask] + best[submask];

                if (val > next[mask])
                {
                    next[mask] = val;
                }

                if (submask == 0)
                {
                    break;
                }

                submask = (submask - 1) & mask;
            }
        }
        dp = next;
    }

    cout << dp[maxM - 1] << "\n";
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;

    while (t > 0)
    {
        solve();
        t--;
    }

    return 0;
}
#endif
