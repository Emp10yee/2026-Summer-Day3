#include <bits/stdc++.h>
using namespace std;
int n;
int dist[20][20];
int dp[20][1 << 20];
int dfs(int cur, int visited)
{
    if (visited == (1 << n) - 1)
    {
        if (dist[cur][0] == 0)
            return 1e9;
        return dist[cur][0];
    }
    if (dp[cur][visited] != -1)
        return dp[cur][visited];
    dp[cur][visited] = 1e9;
    for (int i = 0; i < n; i++)
    {
        if ((visited & (1 << i)) || dist[cur][i] == 0)
            continue;
        dp[cur][visited] = min(dp[cur][visited], dfs(i, visited | (1 << i)) + dist[cur][i]);
    }
    return dp[cur][visited];
}
int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin >> dist[i][j];
    }
    memset(dp, -1, sizeof(dp));
    cout << dfs(0, 1);
    return 0;
}
