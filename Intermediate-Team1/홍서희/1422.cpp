#include <bits/stdc++.h>
using namespace std;

int n, m;
long long dp[12][1 << 12];

void dfs(int col, int row, int cur, int nxt)
{
    if (row == n)
    {
        dp[col + 1][nxt] += dp[col][cur];
        return;
    }
    if (cur & (1 << row))
        dfs(col, row + 1, cur, nxt);
    else
    {
        dfs(col, row + 1, cur, nxt | (1 << row));
        if (row + 1 < n && !(cur & (1 << (row + 1))))
        {
            dfs(col, row + 2, cur, nxt);
        }
    }
}

int main()
{
    cin >> n >> m;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for (int col = 0; col < m; col++)
    {
        for (int mask = 0; mask < (1 << n); mask++)
        {
            if (dp[col][mask] > 0)
                dfs(col, 0, mask, 0);
        }
    }
    cout << dp[m][0];

    return 0;
}
